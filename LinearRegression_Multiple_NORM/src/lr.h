/*
 * lr.h
 *
 *  Created on: 21 Sep 2017
 *      Author: yunwu
 */

#ifndef SRC_LR_H_
#define SRC_LR_H_

#define ITERATION_BOUND 100
#define STOP_CRITERIA 0.000000001
#define SITA0_INIT 0
#define SITA1_INIT 0
#define LEARN_RATE 0.001
#define DIM 4
#define SIZE 1000

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

float linear_function(float *x, float *theta);
void linear_function_vec(float *x, float *theta,
						 float *y, int size);
float cost_function(float *sita,
					float *x,
					float *y,
					int size);
void gradient_descent(float *sita_init, float learn_rate,
					  float *x, float *y, int size,
					  float *sita_est);


#endif /* SRC_LR_H_ */
