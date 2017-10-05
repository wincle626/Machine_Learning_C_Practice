/*
 * lr.c
 *
 *  Created on: 21 Sep 2017
 *      Author: yunwu
 */

#include "lr.h"

float linear_function(float *x, float *theta){
	float y;
	int i;
	y = theta[0];
	for(i=1;i<DIM+1;i++){
		y += x[i-1] * theta[i];
	}
	return y;
}

void linear_function_vec(float *x, float *theta,
						 float *y, int size){
	int i=0;
	int k=0;
	for(i=0;i<size*DIM;i+=DIM,k++){
		float *x_tmp;
		x_tmp = (float*) malloc(DIM*sizeof(float));
		memcpy(x_tmp,&x[i],DIM*sizeof(float));
		y[k] = linear_function(x_tmp, theta);
	}
}

/*
 * The idea is to calculate the sum of mean square error
 * for the given theta0 and theta1 of all data samples
 * 		y_est_i = theta1 * x_i + theta0 (J(theta0, theta1))
 * 		mse = sum((y_i-y_est_i)^2)/(2*n) i belong 0 to n
 * 		where n is the size of samples
 */
float cost_function(float *theta,
					float *x,
					float *y,
					int size){
	float error = 0;
	int i,j;
	float sum_sub = 0;
	for(i=0;i<size;i++){
		float y_i = y[i];
		for(j=0;j<DIM+1;j++){
			float x_i = x[j*size+i];
			float theta_i = theta[j];
			sum_sub += (y_i - x_i * theta_i) * (y_i - x_i * theta_i);
		}
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
void gradient_descent(float *theta_init, float learn_rate,
					  float *x, float *y, int size,
					  float *theta_est){


//	memcpy(theta_est,theta_init,(DIM+1)*sizeof(float));
	float alpha = learn_rate;
	float err;
	for(int itr=0;itr<ITERATION_BOUND;itr++){
		int idx = 0;
		for (int i = 0; i < size*DIM; i+=DIM, idx++) {
			float *x_tmp;
			x_tmp = (float*) malloc(DIM*sizeof(float));
			memcpy(x_tmp,&x[i],DIM*sizeof(float));
			float p1 = linear_function(x_tmp,theta_est);
			err = p1 - y[idx];
			theta_est[0] = theta_est[0] - alpha * err;
			for(int j=1;j<DIM+1;j++){
				theta_est[j] = theta_est[j] - alpha * err * x_tmp[j-1];
			}
//			for(int j=0;j<DIM;j++){
//				printf("x[%d]=%f,",j,x_tmp[j]);
//			}
//			printf("p1=%f,y[%d]=%f,\n",p1,idx,y[idx]);
//			printf("err=%f\n",err);
//			printf("theta_est[0]=%f,",theta_est[0]);
//			for(int j=1;j<DIM+1;j++){
//				printf("theta_est[%d]=%f,",j,theta_est[j]);
//			}
//			printf("\n\n");
		}
	}

}
