//============================================================================
// Name        : MultidimArrays.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void Resize(int ** noptrArray, int newSize);

int main() {

	const int MAX = 10;

	int * optrArray = new int[MAX];

	int length = MAX;

	do {
		cout << "length is now: " << length << endl;
		for (int i = 0; i < length; i++) {
			optrArray[i] = i+1;

			cout << "optrArray[" << i << "]: " << optrArray[i] << endl;
		}
		cout << "Please input the new length of the array (>- 10 will quit): ";
		cin >> length;

		if (length > 0) {
			Resize(&optrArray, length);
		}
	} while(length > 0);

	delete[] optrArray;

	return 0;
}

void Resize(int ** noptrArray, int newSize){
	if (noptrArray != nullptr) {
		delete [] *noptrArray;
	}

	*noptrArray = new int[newSize];
}
