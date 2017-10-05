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
#include <time.h>

#define RAND_DIV 1000
#define RAND_MUL 10

void print_vector_float(char* name, float *x, int size);
void print_matrix_float(char* name, float **x, int m, int n);
void random_vector_float_factor(float *x, int size, float factor);
void random_vector_float(float *x, int size);
void vector_add_float(float *a, float *b, float *c, int size);
void vector_sub_float(float *a, float *b, float *c, int size);
float vector_sum_float(float *a, int size);
void linear_vector_float(float *vec, int size);
float determinant(float **a,int k);
void cofactor(float **num, int f, float **inv);
void transpose(float **num, float **fac, int r, float **inverse);
void matrix_multiple(float **a, float **b, float **c, int m , int n, int l);
void matrix_vector_multiple(float **a, float *b, float *c, int m, int n);
void vector_multiple(float *a, float **c, int n);
void matrix_inverse(float **a, int n, float **b);
void matrix_transpose(float **a, float **b, int m, int n);

#endif /* SRC_ULTIS_H_ */
