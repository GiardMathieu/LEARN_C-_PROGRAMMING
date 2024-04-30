//============================================================================
// Name        : Vectors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;


void Func(vector<int> & vecRef);
int main() {
	vector<int> intVec;

	intVec.reserve(20);
	intVec.push_back(5);

	for(int i = 0; i < 20; i++) {
		intVec.push_back(5);

		cout << "The size of intVec: " << intVec.size() << endl;
		cout << "The capacity of the vector: " << intVec.capacity() << endl;
	}

	intVec.pop_back(); //Remove the last element in the vector



	cout << "The size of intVec: " << intVec.size() << endl;
	cout << "The capacity of the vector: " << intVec.capacity() << endl;

	intVec.clear(); //Remove all of the elements in the vector
	if(intVec.empty()){
		cout << "The vector is empty !" << endl;
	} else {
		cout << "The vector is not empty !" << endl;
	}

	intVec[0] = 5;
	cout << "intVec[0]: " << intVec[0] << endl;

	return 0;
}
