/*
 * Test.cpp
 *
 *  Created on: Jul 11, 2015
 *  Author: Gulsum Gudukbay
 *  ID: 21401148
 */

#include "solutions.h"
#include <iostream>
#include <ctime>
using namespace std;

const int outputSize = 1000;
const int inputSize = 1000;
const int maxInputSize = 100000;
int outputArray[outputSize];
int trial;

int main() {

	trial = 1;

	while ((inputSize * trial) <= maxInputSize) {

		int inputArray[inputSize*trial];

		//FILLING THE ARRAY WITH RANDOM INTEGERS, SAME ARRAY IS USED FOR ALL SOLUTIONS TO HAVE ONLY ONE INDEPENDENT VARIABLE (OUTPUTSIZE)
		for (int i = 0; i < (inputSize * trial); i++)
			inputArray[i] = rand() % 1001;

		cout << "INPUT ARRAY SIZE: " << inputSize * trial << endl;
		cout << endl;
		//SOLUTION 1
		//Store the starting time
		double duration;
		clock_t startTime = clock();

		solution1(inputArray, inputSize*trial, outputSize, outputArray);

		//Compute the number of seconds that passed since the starting time
		duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
		cout << "Execution1 took " << duration << " milliseconds." << endl;

		//SOLUTION 2
		//Store the starting time
		double duration2;
		clock_t startTime2 = clock();

		solution2(inputArray, inputSize*trial, outputSize, outputArray);

		//Compute the number of seconds that passed since the starting time
		duration2 = 1000 * double(clock() - startTime2) / CLOCKS_PER_SEC;
		cout << "Execution2 took " << duration2 << " milliseconds." << endl;

		//SOLUTION 3
		//Store the starting time
		double duration3;
		clock_t startTime3 = clock();

		solution3(inputArray, inputSize*trial, outputSize, outputArray);

		//Compute the number of seconds that passed since the starting time
		duration3 = 1000 * double(clock() - startTime3) / CLOCKS_PER_SEC;
		cout << "Execution3 took " << duration3 << " milliseconds." << endl;

		cout << endl;

		trial++;
	}

	return 0;
}
