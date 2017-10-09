/*
 * main.c
 *
 *  Created on: 9 Oct 2017
 *      Author: yunwu
 */

#include "nn.h"
#include "app.h"

int main(int argc, char** argv){

	net  Net;
	bool Stop;
	float MinTestError;

	InitializeRandoms();

	int Units[NUM_LAYERS] = {N, 10, 5, M};
	InitiateNetwork(&Net,NUM_LAYERS,Units);
	RandomWeights(&Net);
	InitializeApplication(&Net);

	Stop = false;
	MinTestError = MAX_REAL;
	do {
	TrainNet(&Net, 10);
	TestNet(&Net);
	if (TestError < MinTestError) {
		fprintf(f, " - saving Weights ...");
		MinTestError = TestError;
		SaveWeights(&Net);
	}
	else if (TestError > 1.2 * MinTestError) {
		fprintf(f, " - stopping Training and restoring Weights ...");
		Stop = true;
		RestoreWeights(&Net);
	}
	} while (NOT Stop);

	TestNet(&Net);
	EvaluateNet(&Net);

	FinalizeApplication(&Net);

	return 0;
}
