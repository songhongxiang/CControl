/*
 * odorp.c
 *
 *  Created on: 28 oktober 2023
 *      Author: Daniel Mårtensson
 */

#include "../../Headers/functions.h"

/*
 * This algorithm is created by Daniel Mårtensson in the year 2023.
 * This algorithm uses one linear neural network for classifying descriptors from interest points.
 * The purpose with this algorithm is to 
 * * Pros:
 *  - Offer localization
 *  - Multiple object at the time
 *  - Fast
 * Cons:
 *  - Classify specific objects
 */
DATA_COLLECT* odorp(DATA_SETTINGS* settings) {
	/* Header */
	printf("\t\t\t\tObject Detection Oriented FAST Rotated Pattern\n");

	/* Collect data */
	settings->collect_type = COLLECT_TYPE_ORP;
	printf("1: Collecting data. Reading the .pgm files in row-major. PGM format P2 or P5 format.\n");
	DATA_COLLECT* data_collect = collect_data(settings);

	/* Create a class ID vector for K-means clustering that have the same length as the original class ID vector */
	data_collect->class_id_k_means = (size_t*)malloc(data_collect->input_row * sizeof(size_t));

	/* Sort the data with K-means clustering so it's more linear separable with SVM */
	float* C = (float*)malloc(settings->k_value * data_collect->column * sizeof(float));
	bool success = false;
	while (!success) {
		/* Do K-means clustering */
		success = kmeans(data_collect->input, data_collect->class_id_k_means, C, settings->k_value, data_collect->input_row, data_collect->column);

		/* Message */
		if (success) {
			printf("\tK-means clustering success!\n");
		}
		else {
			printf("\tK-means clustering failed...try again with a lower k-value\n");
		}
	}

	/* Free */
	free(C);

	/* Save the row and column parameters */
	data_collect->model_row[0] = settings->k_value;
	data_collect->model_column[0] = data_collect->column;
	data_collect->is_model_created[0] = true;
	data_collect->activation_function[0] = ACTIVTION_FUNCTION_CLOSEST_VALUE_INDEX;
	data_collect->total_models = 1;

	/* Give the K-value from the settings to the classes_k_means */
	data_collect->classes_k_means = settings->k_value;
	
	/*
	 * Train Neural Network model of the total projection
	 * C is a tuning parameter
	 * lambda is a tuning parameter
	 * Important to turn P into transpose because we are going to use that as vectors ontop on each other
	 * Example:
	 * float C = 1;
	 * float lambda = 2.5;
	 */
	printf("2: Create a Neural Network for a linear model - Model 0.\n");
	float* accuracy = (float*)malloc(data_collect->classes_k_means * sizeof(float));
	bool* status = (bool*)malloc(data_collect->classes_k_means * sizeof(bool));
	data_collect->model_w[0] = (float*)malloc(data_collect->classes_k_means * data_collect->column * sizeof(float));
	data_collect->model_b[0] = (float*)malloc(data_collect->classes_k_means * sizeof(float));
	nn_train(data_collect->input, data_collect->class_id_k_means, data_collect->model_w[0], data_collect->model_b[0], status, accuracy, data_collect->input_row, data_collect->column, data_collect->classes_k_means, settings->C, settings->lambda);

	/* Free */
	free(status);
	free(accuracy);

	/* Check the accuracy of the neural network */
	float* y = (float*)malloc(data_collect->input_row * data_collect->column * sizeof(float));
	nn_eval(data_collect->model_w[0], data_collect->model_b[0], data_collect->input, y, data_collect->class_id_k_means, data_collect->classes_k_means, data_collect->column, data_collect->input_row, ACTIVTION_FUNCTION_CLOSEST_VALUE_INDEX);
	
	/* Free */
	free(y);

	/* Compute the histogram - That histogram is going to be the new data for the second neural network */
	printf("3: Create a Neural Network for a linear model - Model 1.\n");
	float* histogram = (float*)malloc(data_collect->classes_original * data_collect->classes_k_means * sizeof(float));
	memset(histogram, 0, data_collect->classes_original * data_collect->classes_k_means * sizeof(float));
	size_t i;
	bool class_id_found;
	y = (float*)malloc(data_collect->classes_k_means * sizeof(float));
	for (i = 0; i < data_collect->input_row; i++) {
		size_t class_id = nn_predict(data_collect->model_w[0], data_collect->model_b[0], data_collect->input + i * data_collect->column, y, data_collect->model_row[0], data_collect->model_column[0], &class_id_found, ACTIVTION_FUNCTION_CLOSEST_VALUE_INDEX);
		if (class_id_found) {
			histogram[data_collect->class_id_original[i] * data_collect->classes_k_means + class_id]++;
		}
	}

	/* Free */
	free(y);

	/* Create class ID for the histogram */
	size_t* class_id = (size_t*)malloc(data_collect->classes_original * sizeof(size_t));
	for (i = 0; i < data_collect->classes_original; i++) {
		class_id[i] = i;
	}

	/* Save the row and column parameters */
	data_collect->model_row[1] = data_collect->classes_original;
	data_collect->model_column[1] = data_collect->classes_k_means;
	data_collect->is_model_created[1] = true;
	data_collect->activation_function[1] = ACTIVTION_FUNCTION_CLOSEST_VALUE_INDEX;
	data_collect->total_models = 2;

	/* Use that histogram to bild a new neural network */
	printf("4: Create a Neural Network for a linear model 1.\n");
	status = (bool*)malloc(data_collect->classes_original * sizeof(bool));
	accuracy = (float*)malloc(data_collect->classes_original * sizeof(float));
	data_collect->model_w[1] = (float*)malloc(data_collect->classes_original * data_collect->classes_k_means * sizeof(float));
	data_collect->model_b[1] = (float*)malloc(data_collect->classes_original * sizeof(float));
	nn_train(histogram, class_id, data_collect->model_w[1], data_collect->model_b[1], status, accuracy, data_collect->classes_original, data_collect->classes_k_means, data_collect->classes_original, settings->C, settings->lambda);
	
	/* Free */
	free(status);
	free(accuracy);

	/* Check the accuracy of the neural network */
	y = (float*)malloc(data_collect->classes_original * data_collect->classes_k_means * sizeof(float));
	nn_eval(data_collect->model_w[1], data_collect->model_b[1], histogram, y, class_id, data_collect->classes_original, data_collect->classes_k_means, data_collect->classes_original, ACTIVTION_FUNCTION_CLOSEST_VALUE_INDEX);
	
	/* Free */
	free(y);
	free(class_id);

	/* Save model */
	printf("5: Saving the model to a .h file.\n");
	if (settings->save_model) {
		char model_path[260];
		char model_name[100];
		char model_name_h[100];
		char model_name_text[100];
		printf("Enter a model name: ");
		scanf("%s", model_name);
		uint8_t i;
		for (i = 0; i < data_collect->total_models; i++) {
			sprintf(model_name_h, "%s_%i.h", model_name, i);
			sprintf(model_name_text, "%s_%i", model_name, i);
			concatenate_paths(model_path, settings->folder_path, model_name_h);
			nn_save(data_collect->model_w[i], data_collect->model_b[i], data_collect->activation_function[i], model_path, model_name_text, data_collect->model_row[i], data_collect->model_column[i]);
		}
	}
	else {
		printf("\tNo...\n");
	}

	/* End */
	printf("6: Everything is done...\n");

	/* Return data */
	return data_collect;
}