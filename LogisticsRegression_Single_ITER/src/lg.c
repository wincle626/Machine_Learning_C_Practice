/*
 * lg.c
 *
 *  Created on: 25 Sep 2017
 *      Author: yunwu
 */

#include "lg.h"

float logistics_function(float x, float theta0, float theta1){// Sigmoid function
	float y = 0;
	y = 1 / (1+exp(-1 * (theta1 * x + theta0)));
	return y;
}

void logistics_function_vec(float *x, float theta0, float theta1, float *y, int size){
	int i=0;
	for(i=0;i<size;i++){
		y[i] = logistics_function(x[i],theta0,theta1);
	}
}

float cost_function(float x, float theta0, float theta1, float y){
	float cost = 0;
	// direct cost function
//	cost = logitstics_function(x,theta) - y;
	// log cost function
//	if(y==1){
//		cost = -1 * log(logitstics_function(x,theta));
//	}
//	else{
//		cost = -1 * log(1 - logitstics_function(x,theta));
//	}
	// Optimised log cost function
	cost = -1 * y * log(logistics_function(x,theta0,theta1))
		   - (1 - y) * log(1 - logistics_function(x,theta0,theta1));
	return cost;
}

float cost_function_vec(float *x, float theta0, float theta1, float *y, int size){
	float cost = 0;
	int i=0;
	for(i=0;i<size;i++){
		cost += cost_function(x[i],theta0,theta1,y[i]);
	}

	return cost;
}

void gradient_descent(float theta0_init, float theta1_init, float learn_rate,
					  float *x, float *y, int size,
					  float *theta0_est, float *theta1_est){

	*theta0_est = theta0_init;
	*theta1_est = theta1_init;
	float alpha = learn_rate;
	float err;
	for (int i = 0; i < size*ITERATION_BOUND; i ++) {
	    int idx = i % size;
//	    float p = *theta0_est + *theta1_est * x[idx];
	    float p1 = logistics_function(x[idx],*theta0_est,*theta1_est);
	    err = p1 - y[idx];
//	    printf("%f-%f\n",p1,y[idx]);
	    *theta0_est = *theta0_est - alpha * err;
	    *theta1_est = *theta1_est - alpha * err * x[idx];
	}

}

void conjugate_gradient(){

}

void BFGS(){

}

void L_BFGS(){

}
