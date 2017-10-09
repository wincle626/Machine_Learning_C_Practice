/*
 * utils.h
 *
 *  Created on: 9 Oct 2017
 *      Author: yunwu
 */

#ifndef SRC_UTILS_H_
#define SRC_UTILS_H_


#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stddef.h>

#define RAND_DIV 1000
#define RAND_MUL 10

#define FALSE         0
#define TRUE          1
#define NOT           !
#define AND           &&
#define OR            ||

#define MIN_REAL      -HUGE_VAL
#define MAX_REAL      +HUGE_VAL
#define MIN(x,y)      ((x)<(y) ? (x) : (y))
#define MAX(x,y)      ((x)>(y) ? (x) : (y))

#define sqr(x)        ((x)*(x))

void InitializeRandoms();
int RandomEqualINT(int Low, int High);
float RandomEqualFLOAT(float Low, float High);
void random_vector_float_factor(float *x, int size, float factor);
void random_vector_float(float *x, int size);
void vector_add_float(float *a, float *b, float *c, int size);
void vector_sub_float(float *a, float *b, float *c, int size);
float vector_sum_float(float *a, int size);
void linear_vector_float(float *vec, int size);


#endif /* SRC_UTILS_H_ */
