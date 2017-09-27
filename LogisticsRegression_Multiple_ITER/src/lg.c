/*
 * lg.c
 *
 *  Created on: 25 Sep 2017
 *      Author: yunwu
 */

#include "lg.h"

float logistics_function(float *x, float *theta){// Sigmoid function
	float y = 0;
	float tmp = 0;
	int i;
	tmp = theta[0];
	for(i=1;i<DIM+1;i++){
		tmp += x[i-1] * theta[i];
	}
	y = 1 / (1+exp(-1 * tmp));
	return y;
}

void logistics_function_vec(float *x, float *theta,
		 	 	 	 	 	float *y, int size){
	int i=0;
	int k=0;
	for(i=0;i<size*DIM;i+=DIM,k++){
		float *x_tmp;
		x_tmp = (float*) malloc(DIM*sizeof(float));
		memcpy(x_tmp,&x[i],DIM*sizeof(float));
		y[k] = logistics_function(x_tmp, theta);
	}
}

float cost_function(float *x, float *theta, float y){
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
	cost = -1 * y * log(logistics_function(x,theta))
		   - (1 - y) * log(1 - logistics_function(x,theta));
	return cost;
}

float cost_function_vec(float *x, float *theta, float *y, int size){
	float cost = 0;
	int i=0;
	for(i=0;i<size/DIM;i++){
		cost += cost_function(&x[i*DIM],theta,y[i]);
	}

	return cost;
}

void gradient_descent(float *theta_init, float learn_rate,
					  float *x, float *y, int size,
					  float *theta_est){

//	memcpy(theta_est,theta_init,DIM*sizeof(float));
	float alpha = learn_rate;
	float err;
	for(int itr=0;itr<ITERATION_BOUND;itr++){
		int idx = 0;
		for (int i = 0; i < size*DIM; i+=DIM, idx++) {
			float *x_tmp;
			x_tmp = (float*) malloc(DIM*sizeof(float));
			memcpy(x_tmp,&x[i],DIM*sizeof(float));
			float p1 = logistics_function(x_tmp,theta_est);
			err = p1 - y[idx];
//			printf("before: ");
//			printf("theta_est[0]=%f,",theta_est[0]);
//			for(int j=1;j<DIM+1;j++){
//				printf("theta_est[%d]=%f,",j,theta_est[j]);
//			}
//			printf("\n");
			theta_est[0] = theta_est[0] - alpha * err;
			for(int j=1;j<DIM+1;j++){
				theta_est[j] = theta_est[j] - alpha * err * x_tmp[j-1];
			}
//			for(int j=0;j<DIM;j++){
//				printf("x[%d]=%f,",j,x_tmp[j]);
//			}
//			printf("p1=%f,y[%d]=%f,\n",p1,idx,y[idx]);
//			printf("err=%f\n",err);
//			printf("after: ");
//			printf("theta_est[0]=%f,",theta_est[0]);
//			for(int j=1;j<DIM+1;j++){
//				printf("theta_est[%d]=%f,",j,theta_est[j]);
//			}
//			printf("\n\n");
		}
	}

}

void conjugate_gradient(){

}

void BFGS(){

}

void L_BFGS(){

}
