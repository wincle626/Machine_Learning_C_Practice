/*
 * ultis.c
 *
 *  Created on: 21 Sep 2017
 *      Author: yunwu
 */

#include "ultis.h"

void random_vector_float_factor(float *x, int size, float factor){
	int i;
	for(i=0;i<size;i++){
		x[i] = factor*RAND_MUL*(rand()%RAND_DIV)/RAND_DIV;
	}
}

void random_vector_float(float *x, int size){
	int i;
	for(i=0;i<size;i++){
		x[i] = (float)RAND_MUL*(float)(rand()%RAND_DIV)/RAND_DIV;
	}
}

void vector_add_float(float *a, float *b, float *c, int size){
	int i;
	for(i=0;i<size;i++){
		c[i] = a[i] + b[i];
	}
}

void vector_sub_float(float *a, float *b, float *c, int size){
	int i;
	for(i=0;i<size;i++){
		c[i] = a[i] - b[i];
	}
}

float vector_sum_float(float *a, int size){
	int i;
	float sum = 0;
	for(i=0;i<size;i++){
		sum += a[i];
	}
	return sum;
}

void linear_vector_float(float *vec, int size){
	int i=0;
	for(i=0;i<size;i++){
		vec[i] = i;
	}
}
