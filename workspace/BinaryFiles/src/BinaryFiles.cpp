//============================================================================
// Name        : BinaryFiles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Data {
	int value1;
	int value2;
};

int main() {
	srand(time(NULL));

	const int MAX = 10;

	const int VALUE1_MAX = 100;
	const int VALUE2_MAX = 1000;

	Data arrayData[MAX];

	for(int i = 0; i<MAX; i++) {
		arrayData[i].value1 = rand() % VALUE1_MAX + 1;
		arrayData[i].value2 = (rand() % (VALUE2_MAX-VALUE1_MAX)) + VALUE1_MAX + 1;

		cout << "arrayData[" << i << "].value1 " << arrayData[i].value1 << endl;
		cout << "arrayData[" << i << "].value2 " << arrayData[i].value2 << endl;

	}

	return 0;
}
