/*
 * std.c
 *
 *  Created on: 26 juni 2021
 *      Author: Daniel Mårtensson
 */

#include "../../Headers/Functions.h"

float std(float* x, uint32_t length) {
	float mu = mean(x, length);
	float sigma = 0;
	for(uint32_t i = 0; i < length; i++)
		sigma += (*(x + i) - mu) * (*(x + i) - mu);
	return sqrtf(sigma/((float) length));
}
