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
#define LEARN_RATE 0.01

#include <stdio.h>

float linear_function(float x, float theta0, float theta1);
void linear_function_vec(float *x, float theta0, float theta1,
						 float *y, int size);
float cost_function(float theta0, float theta1,
					float *x, float *y, int size);
void gradient_descent(float theta0_init, float theta1_init, float learn_rate,
					  float *x, float *y, int size,
					  float *theta0_est, float *theta1_est);


#endif /* SRC_LR_H_ */
