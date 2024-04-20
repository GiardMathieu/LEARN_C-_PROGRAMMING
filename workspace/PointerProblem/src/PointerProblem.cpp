//============================================================================
// Name        : PointerProblem.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void Swap(int & x, int & y);

int main() {

	//Problem 1: Write a function that will swap the values of 2 integers

	int x = 5;
	int y = 15;

	Swap(x, y);

	cout << "The value of x is: " << x << endl;
	cout << "The value of y is: " << y << endl;


	return 0;
}

/*void Swap(int & x, int & y) {
	int temp = x;
	x = y;
	y = temp;
}
*/
