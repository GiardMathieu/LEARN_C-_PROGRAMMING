//============================================================================
// Name        : Ternary.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	//(boolean expression) ? (true expression) : (false case);
	/*
	int x = 12, y = 9, max = 0;

	x > y ? max = x : max = y;

	cout << "The max is " << max << endl;
	*/

	//Write a program that enters a number and prints out whether it's even or odd. Use a switch statement.

	int nb = 0;
	cout << "Write a value for nb " << endl;
	cin >> nb;
	bool isPair = nb % 2 == 0;

	switch (isPair) {
		case 1:
			cout << "The number " << nb << " is even !" << endl;
			break;
		default:
			cout << "The number " << nb << " is odd !" << endl;

	}

	return 0;
}
