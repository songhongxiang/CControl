/*
 * pooling.c
 *
 *  Created on: 22 juli 2023
 *      Author: Daniel M�rtensson
 */

#include "../../Headers/Functions.h"
/*
 * Pooling 
 * A[m*n]
 * P[m*n/p]
 */
void pooling(float A[], float P[], size_t row_a, size_t column_a, size_t p, POOLING_METOD pooling_method) {
	/* Get the height and width for B */
	size_t h = row_a / p;
	size_t w = column_a / p;

	/* Create B */
	float* B = (float*)malloc(p*p * sizeof(float));

	/* Slack variable */
	size_t max_index = 0;

	/* Loop */
	size_t i, j, start_row, stop_row, start_column, stop_column;
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			/* Cut A into B */
			start_row = i * p;
			stop_row = i * p + 1;
			start_column = j * p;
			stop_column = j * p + 1;
			cut(A, column_a, B, start_row, stop_row, start_column, stop_column);

			/* Add to P */
			switch (pooling_method) {
			case POOLING_METOD_AVERAGE:
				P[j] = mean(B, p * p);
				break;
			case POOLING_METOD_MAX:
				P[j] = amax(B, &max_index, p * p);
				break;
			}
		}
		P += w;
	}

	/* Free */
	free(B);
}

/* GNU Octave code:
 * A = [0.950541   0.565081   0.233296   0.134038   0.092543   0.174173   0.675002   0.271878   0.921699   0.296898
		0.028431   0.986487   0.898816   0.283115   0.157745   0.864740   0.839363   0.329373   0.303102   0.030187
		0.287999   0.970384   0.685952   0.327385   0.042384   0.065263   0.668094   0.016202   0.133942   0.967720
		0.119599   0.788482   0.775595   0.125143   0.898057   0.745977   0.181511   0.863085   0.237734   0.818524
		0.975217   0.397514   0.781937   0.314420   0.414597   0.501971   0.768909   0.440769   0.501774   0.352254
		0.218738   0.229907   0.662609   0.272773   0.982926   0.543600   0.777082   0.965983   0.345566   0.999757
		0.141835   0.473209   0.028366   0.482486   0.245346   0.802416   0.456072   0.551474   0.544778   0.922006
		0.057235   0.284095   0.951537   0.370885   0.958261   0.596167   0.361224   0.489283   0.439690   0.704039
		0.099949   0.092182   0.199169   0.250974   0.127467   0.072122   0.659420   0.509071   0.515593   0.131673
		0.610705   0.863790   0.684771   0.188464   0.860727   0.037058   0.051288   0.865577   0.753889   0.557765];

	% Pooling factor
	p = 2;

	% Size of A
	[row_a, column_a] = size(A);

	% P size
	h = floor(row_a / p);
	w = floor(column_a / p);
	P = zeros(h, w);

	% Process
	for i = 1:h
		for j = 1:w
			% Cut
			start_row = (i - 1) * p + 1;
			stop_row = i * p;
			start_column = (j - 1) * p + 1;
			stop_column = j * p;
			B = A(start_row:stop_row, start_column:stop_column);

			% Do pooling
			P(i, j) = max(B(:)); % mean(B(:));
		end
	end

	size(A)
	size(P)
	P
 */