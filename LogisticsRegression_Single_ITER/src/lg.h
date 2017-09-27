/*
 * lg.h
 *
 *  Created on: 25 Sep 2017
 *      Author: yunwu
 */

#ifndef SRC_LG_H_
#define SRC_LG_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ITERATION_BOUND 1000
#define STOP_CRITERIA 0.000000001
#define SITA0_INIT 0.1
#define SITA1_INIT 0.1
#define LEARN_RATE 0.01

float logistics_function(float x, float theta0, float theta1);
void logistics_function_vec(float *x, float theta0, float theta1, float *y, int size);
float cost_function(float x, float theta0, float theta1, float y);
float cost_function_vec(float *x, float theta0, float theta1, float *y, int size);
void gradient_descent(float theta0_init, float theta1_init, float learn_rate,
					  float *x, float *y, int size,
					  float *theta0_est, float *theta1_est);

#endif /* SRC_LG_H_ */
