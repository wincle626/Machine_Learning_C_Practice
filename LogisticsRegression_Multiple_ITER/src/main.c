/*
 * main.c
 *
 *  Created on: 25 Sep 2017
 *      Author: yunwu
 */

#include "lg.h"
#include "ultis.h"

int main(int argc, char** argv){

	int size = 1000;

	float *x;
	float *y;
	float *theta_init;
	float *theta_est;
	float *noise;
	x = (float*) malloc(size*DIM*sizeof(float));
	y = (float*) malloc(size*sizeof(float));
	noise = (float*) malloc(size*sizeof(float));
	theta_init = (float*) malloc((DIM+1)*sizeof(float));
	theta_est = (float*) malloc((DIM+1)*sizeof(float));
	srand(time(NULL));
//	printf(" RAND_MAX is %d \n", RAND_MAX);
	for(int i=0;i<DIM+1;i++){
		theta_init[i] = (float)(rand()%1000)/100;
	}
	for(int i=0;i<DIM+1;i++){
		printf("theta_init[%d]=%f,",i,theta_init[i]);
	}
	printf("\n");
	random_vector_float(x,size);
	logistics_function_vec(x,theta_init,y,size);
	random_vector_float_factor(noise, size, 0.0000001);
	vector_add_float(y,noise,y,size);

	gradient_descent(theta_init,LEARN_RATE,x,y,size,theta_est);

	for(int i=0;i<DIM+1;i++){
		printf("theta_est[%d]=%f,",i,theta_est[i]);
	}
	printf("\n");

	return 0;
}

