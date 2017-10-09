/*
 * utils.c
 *
 *  Created on: 9 Oct 2017
 *      Author: yunwu
 */

#include "utils.h"

void InitializeRandoms()
{
//  srand(4711);
	srand(time(NULL));
}

int RandomEqualINT(int Low, int High)
{
	return rand() % (High-Low+1) + Low;
}


float RandomEqualFLOAT(float Low, float High)
{
	return ((float) rand() / RAND_MAX) * (High-Low) + Low;
}

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
