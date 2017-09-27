/*
 * lr.c
 *
 *  Created on: 21 Sep 2017
 *      Author: yunwu
 */

#include "lr.h"

float linear_function(float x, float theta0, float theta1){
	float y;
	y = theta1 * x + theta0;
	return y;
}

void linear_function_vec(float *x, float theta0, float theta1,
						 float *y, int size){
	int i=0;
	for(i=0;i<size;i++){
		y[i] = linear_function(x[i], theta0, theta1);
	}
}

/*
 * The idea is to calculate the sum of mean square error
 * for the given theta0 and theta1 of all data samples
 * 		y_est_i = theta1 * x_i + theta0 (J(theta0, theta1))
 * 		mse = sum((y_i-y_est_i)^2)/(2*n) i belong 0 to n
 * 		where n is the size of samples
 */
float cost_function(float theta0, float theta1,
					float *x, float *y, int size){
	float error = 0;
	int i;
	float sum_sub = 0;
	for(i=0;i<size;i++){
		float p = linear_function(x[i],theta0,theta1);
		sum_sub += (y[i] - p) * (y[i] - p);
	}
	error = sum_sub / (2 * size);
	return error;
}

/*
 * The idea is to update the theta0 and theta1 simultaneously
 * so as to approach the values minimizing the cost function.
 * 		theta0 <= theta0 - alpha * d(J(theta0))/d(theta0)
 * 		theta1 <= theta1 - alpha * d(J(theta1))/d(theta1)
 * where alpha is the learning rate and d() is the partial
 * derivative operator.
 * The derivative will get the slope of cost function for each
 * theta value. by subtracting with the initial or previous one,
 * the enumeration process is toward the lower value of cost
 * function curve. However, this does not always achieve the
 * lowest one and it depends on the initial values.
 */
void gradient_descent(float theta0_init, float theta1_init, float learn_rate,
					  float *x, float *y, int size,
					  float *theta0_est, float *theta1_est){

	*theta0_est = 0;
	*theta1_est = 0;
	float alpha = learn_rate;
	float err;
	for (int i = 0; i < size*ITERATION_BOUND; i ++) {
	    int idx = i % size;
//	    float p = *theta0_est + *theta1_est * x[idx];
	    float p1 = linear_function(x[idx],*theta0_est,*theta1_est);
	    err = p1 - y[idx];
	    *theta0_est = *theta0_est - alpha * err;
	    *theta1_est = *theta1_est - alpha * err * x[idx];
//	    printf("x=%f,y=%f,p1=%f,err=%f\n",x[idx],y[idx],p1,err);
//	    printf("theta0_est=%f,theta1_est=%f\n",*theta0_est,*theta1_est);
	}

}
