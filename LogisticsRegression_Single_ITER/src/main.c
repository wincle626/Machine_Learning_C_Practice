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
	float *noise;
	float theta0_init = 2.3;
	float theta1_init = 1.5;
	float theta0_est;
	float theta1_est;
	x = (float*) malloc(size*sizeof(float));
	y = (float*) malloc(size*sizeof(float));
	noise = (float*) malloc(size*sizeof(float));
	srand(time(NULL));
	random_vector_float(x,size);
	random_vector_float_factor(noise, size, 0.0001);
	logistics_function_vec(x,theta0_init,theta1_init,y,size);
	vector_add_float(y,noise,y,size);

	gradient_descent(SITA0_INIT,SITA1_INIT,LEARN_RATE,
			x,y,size,&theta0_est,&theta1_est);

	printf("theta0_init=%f,theta1_init=%f\n",theta0_init,theta1_init);
	printf("theta0_est=%f,theta1_est=%f\n",theta0_est,theta1_est);

	return 0;
}

