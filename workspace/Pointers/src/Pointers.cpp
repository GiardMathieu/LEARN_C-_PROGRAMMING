//============================================================================
// Name        : Pointers.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;



int main() {

	int x = 5;
	int * myIntPointer = &x;

	cout << "The address of x is: " << myIntPointer << endl; //Returns the address of x: 0x61ff08

	*myIntPointer = 10;

	cout << "The value of x is now: " << x << endl;

	return 1;
}
