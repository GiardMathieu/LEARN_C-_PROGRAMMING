//============================================================================
// Name        : Recursion.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int Factorial(int number);

int main() {
	int x = 5;
	cout << "The factorial value of x is : " << Factorial(x) << endl;;
	return 0;
}


int Factorial(int number) {
	if(number == 1) {
		return 1;
	}
	return number * Factorial(number - 1);
}
