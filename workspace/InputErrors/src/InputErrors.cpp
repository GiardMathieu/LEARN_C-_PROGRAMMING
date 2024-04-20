//============================================================================
// Name        : InputErrors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int num1;
	bool failure = false;


	do {
		cout << "Please enter a value for num " << endl;
		cin >> num1;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			failure = true;
			cout << "Input error! Please try again " << endl;
		} else failure = false;
	} while (failure);

	cout << "The value of the number is : " << num1 << endl;


	return 0;
}
