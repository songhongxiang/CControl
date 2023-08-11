/*
 * kpca.c
 *
 *  Created on: 28 Juli 2023
 *      Author: Daniel Mårtensson
 */

#include "../../Headers/functions.h"

 /*
  * Kernel Principal Component Analysis
  * X[m*n]
  * W[m*c]
  * P[c*n]
  */
void kpca(float X[], float W[], float P[], size_t c, size_t row, size_t column, float kernel_parameters[], KERNEL_METHOD kernel_method) {
	/* Create kernel matrix K */
	float* K = (float*)malloc(row * row * sizeof(float));
	kernel(X, K, row, column, kernel_parameters, kernel_method);
	
	/* Do PCA on K instead of X */
	float* mu = (float*)malloc(row * sizeof(float));
	float* Ptemporary = (float*)malloc(c * row * sizeof(float));
	pca(K, W, Ptemporary, mu, c, row, row);

	/* Do projection P = W'*X instead of P = W'*K */
	float* Wt = (float*)malloc(row * c * sizeof(float));
	memcpy(Wt, W, row * c * sizeof(float));
	tran(Wt, row, c);
	mul(Wt, X, P, c, row, column);

	/* Free */
	free(K);
	free(mu);
	free(Ptemporary);
	free(Wt);
}