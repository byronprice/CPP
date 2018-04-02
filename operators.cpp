// operators.cpp
//
// Created: 2017/01/30 by Byron Price
//
// C Tutorial Book - Day 4 - Statements, expressions, and operators
//
// Generate a random number, then automatically find it using the strategy of always dividing
//  the interval into two parts (e.g. the random number is between 0 and 1000 and equals 430. Try 
//  500, see if that is lower or higher than 430. Since it's higher, guess 250. 250 is too low so 
//  the value is between 250 and 500. Continue in that same manner).
// 
// Repeat this 1000 times and save the results (the number of guesses required to find the correct
//  answer) to a file named RandomNumberGuesses.txt 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <sstream> // for std::stringstream

using namespace std;

const int NO = 0;
const int YES = 1;

int main(int agrc,char *argv[]){
	// initialize variables
	int done, numRepeats = 10000;
	unsigned int randMaximum;
	unsigned int number, guess_value, prev_max, prev_min, numGuesses[numRepeats];
	float meanNumGuesses, varNumGuesses;

	// convert the character array argv[1] to an unsigned int
	stringstream convert(argv[1]);
	if (!(convert >> randMaximum)) {
		randMaximum = 100000;
	}

	// tell the user what the file does
	printf("Generate random numbers between 0 and %i.\n",randMaximum);
	printf("Then, guess those numbers using a simple, blind strategy \nand track the number of guesses required.\n");

        // open the file to be saved to
	ofstream myfile;
	myfile.open("RandomNumberGuesses.dat");
        srand( (unsigned) time(NULL));
	for (int ii=0;ii<numRepeats;ii++) {
		number = rand(); 
		number = number%randMaximum; // convert number to a value between 0 and randMaximum

		guess_value = randMaximum/2;
		prev_max = randMaximum; 
		prev_min = 0;

		// guess the random number using the optimal strategy
		done = NO;
		numGuesses[ii] = 0;
		while (done == NO) {
			numGuesses[ii]++;

			if (number == guess_value) {
				done = YES;
			}
			else if (number < guess_value) {
				prev_max = guess_value;
				guess_value = prev_min+(guess_value-prev_min)/2;
			
			}
			else {
				prev_min = guess_value;
				guess_value = guess_value+(prev_max-guess_value)/2;
			}
		}
		myfile << numGuesses[ii] << endl; // save the number of guesses to the .dat file
	}
	myfile.close();	// close and save the .dat file to the current directory

	// calculate the mean number of guesses
	meanNumGuesses = 0.0;
	for (int ii=0;ii<numRepeats;ii++) {
		meanNumGuesses += (float) numGuesses[ii]/numRepeats;
	}

	// calculate the variance of the number of guesses
	varNumGuesses = 0.0;
	for (int ii=0;ii<numRepeats;ii++) {
		varNumGuesses += pow(numGuesses[ii]-meanNumGuesses,2.0)*(1.0/numRepeats);
	}

	// print the results to the screen
	printf("\nMean number of guesses: %3.1f\n",meanNumGuesses);
	printf("Variance: %3.1f\n",varNumGuesses);
	return 0;
}
