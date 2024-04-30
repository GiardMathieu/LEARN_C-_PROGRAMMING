//============================================================================
// Name        : SortingVectors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include <algorithm>
using namespace std;

bool DescCompare(int x1, int x2);

int main() {
	srand(time(NULL));

	const int MAX = 20;
	const int RANDOM_MAX = 10000;

	vector <int> intVec;
	intVec.reserve(MAX);

	cout << "Random list: " << endl << endl;
	for(int i = 0; i < MAX; i++) {
		int x = rand() % RANDOM_MAX;
		intVec.push_back(x);

		cout << x << endl;
	}

	sort(intVec.begin(), intVec.end(), DescCompare);
	cout << "Sorted list: " << endl << endl;
	for (int i = 0; i < MAX; i++) {
		cout << intVec[i] << endl;
	}
	return 0;
}
bool DescCompare(int x1, int x2){
	return x1 > x2; // Other way around for ascending order;
}
