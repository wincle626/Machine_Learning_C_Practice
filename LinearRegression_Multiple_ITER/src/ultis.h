/*
 * ultis.h
 *
 *  Created on: 21 Sep 2017
 *      Author: yunwu
 */

#ifndef SRC_ULTIS_H_
#define SRC_ULTIS_H_

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define RAND_DIV 1000
#define RAND_MUL 10

void random_vector_float_factor(float *x, int size, float factor);
void random_vector_float(float *x, int size);
void vector_add_float(float *a, float *b, float *c, int size);
void vector_sub_float(float *a, float *b, float *c, int size);
float vector_sum_float(float *a, int size);
void linear_vector_float(float *vec, int size);

#endif /* SRC_ULTIS_H_ */
