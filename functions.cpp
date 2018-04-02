// functions.cpp
//  Created 2017/02/14 by Byron Price
//
// Chapter 5 from Teach Yourself C in 21 Days

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for random seed
#include <iostream> // input/output
#include <fstream>
#include <math.h>
#include <sstream> // for std::stringstream

using namespace std;

long f, x;
long factorial(long a);

int main(int agrc,char *argv[]){
	long initialValue;

	// convert the character array argv[1] to a long int
	stringstream convert(argv[1]);
	if (!(convert >> initialValue)) {
		initialValue = 1;
	}

	f = factorial(initialValue);
	printf("%ld factorial is %ld\n",initialValue,f);
	return 0;
}

long factorial(long a) {
	if (a==1) {
		return 1;	
	}
	else {
		a *= factorial(a-1);
		return a;
	}
}
