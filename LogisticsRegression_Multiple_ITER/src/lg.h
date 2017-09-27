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

#define ITERATION_BOUND 10000
#define STOP_CRITERIA 0.000000001
#define LEARN_RATE 1
#define DIM 4

float logistics_function(float *x, float *theta);
void logistics_function_vec(float *x, float *theta,
		 	 	 	 	 	float *y, int size);
float cost_function(float *x, float *theta, float y);
float cost_function_vec(float *x, float *theta, float *y, int size);
void gradient_descent(float *theta_init, float learn_rate,
					  float *x, float *y, int size,
					  float *theta_est);

#endif /* SRC_LG_H_ */
