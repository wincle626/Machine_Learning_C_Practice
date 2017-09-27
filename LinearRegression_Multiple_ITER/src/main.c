/*
 * main.c
 *
 *  Created on: 21 Sep 2017
 *      Author: yunwu
 */

#include "lr.h"
#include "ultis.h"

int main(int argc, char** argv){

	int size = 100;
	float *x;
	float *y;
	float *noise;
	float *theta_init;
	float *theta_est;
	noise = (float*) malloc(size*sizeof(float));
	x = (float*) malloc((DIM+1)*size*sizeof(float));
	y = (float*) malloc(size*sizeof(float));
	theta_init = (float*) malloc((DIM+1)*sizeof(float));
	theta_est = (float*) malloc((DIM+1)*sizeof(float));

	random_vector_float(theta_init,DIM+1);
	for(int i=0;i<DIM+1;i++){
		printf("theta_init[%d]=%f,",i,theta_init[i]);
	}
	printf("\n\n----------------------\n\n");
	random_vector_float(x,DIM*size);
	linear_function_vec(x,theta_init,y,size);
	random_vector_float_factor(noise, size, 0.1);
	vector_add_float(y,noise,y,size);
//	for(int j=0;j<size;j++){
//		for(int i=0;i<DIM+1;i++){
//			printf("theta_init[%d]=%f\n",i,theta_init[i]);
//		}
//		for(int i=0;i<DIM;i++){
//			printf("x[%d]=%f,",j*DIM+i,x[j*DIM+i]);
//		}
//		printf("\n");
//		printf("y[%d]=%f\n",j,y[j]);
//	}
//	printf("\n-----------------------------\n\n");

	gradient_descent(theta_init,LEARN_RATE,
					 x,y,size,theta_est);

	for(int i=0;i<DIM+1;i++){
		printf("theta_est[%d]=%f,",i,theta_est[i]);
	}
	printf("\n\n");

	return 0;
}
