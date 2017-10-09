/*
 * app.h
 *
 *  Created on: 9 Oct 2017
 *      Author: yunwu
 */

#ifndef SRC_APP_H_
#define SRC_APP_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "nn.h"

#define NUM_LAYERS    4
#define N             30
#define M             1

#define FIRST_YEAR    1700
#define NUM_YEARS     280

#define LO            0.1
#define HI            0.9

#define TRAIN_LWB     (N)
#define TRAIN_UPB     (179)
#define TRAIN_YEARS   (TRAIN_UPB - TRAIN_LWB + 1)
#define TEST_LWB      (180)
#define TEST_UPB      (259)
#define TEST_YEARS    (TEST_UPB - TEST_LWB + 1)
#define EVAL_LWB      (260)
#define EVAL_UPB      (NUM_YEARS - 1)
#define EVAL_YEARS    (EVAL_UPB - EVAL_LWB + 1)

float                  Mean;
float                  TrainError;
float                  TrainErrorPredictingMean;
float                  TestError;
float                  TestErrorPredictingMean;

FILE*                 f;

void NormalizeSunspots();
void InitializeApplication(net* Net);
void FinalizeApplication(net* Net);
void TrainNet(net* Net, int Epochs);
void TestNet(net* Net);
void EvaluateNet(net* Net);

#endif /* SRC_APP_H_ */
