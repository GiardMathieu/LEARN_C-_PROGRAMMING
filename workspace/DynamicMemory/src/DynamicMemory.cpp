//============================================================================
// Name        : DynamicMemory.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int length;
	cout << "Please enter the value of length: ";
	cin >> length;

	int * intPtr = new int[length];

	for(int i = 0; i < length; i++){
		intPtr[i] = i + 1;
	}

	for (int i = 0; i < length; i++) {
		cout << "intPtr[" << i << "] = " << intPtr[i] << endl;
	}
	delete [] intPtr;

	return 0;
}
