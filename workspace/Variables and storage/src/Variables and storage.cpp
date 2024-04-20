//============================================================================
// Name        : Variables.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	/*int x = 0; // int means numbers like 10, 3 NOT 4.1

	char c = 'A';

	float pi = 3.14;

	double doublePi = 3.14159;

	cout << "The value of x is " << x << " and the char is " << c << endl;
	cout << "The value of pi is " << pi <<  endl;
	cout << "The value of doublePi is " << doublePi << endl;
	*/

	// 10,3

	// 123
	// (1 * 10^2) + (2 * 10 ^1) + (3*10^0)

	// 1001
	// (1 * 2^3) + (0 * 2^2) + (0 * 2^1) + (1 * 2^0) = 9

	// a byte is 8 bits

	// sizeof()

	//	cout << "The size of an int is : " << sizeof(int) << endl;
	//	cout << "The size of a char is: " << sizeof(char) << endl;
	//	cout << "The size of a float is " << sizeof(float) << endl;
	//	cout << "The size of a double is " << sizeof(double) << endl;

	// int -> -2^31 to 2^31 - 1 (-1 because of zero, gotta count zero)

	//unsigned int x = 0; // Cannot be negative range from 0 to 2^32-1

	int intVal = 6;

	float floatVal = 3.14;

	floatVal = intVal;

	cout << "The value of intVal is " << intVal << endl;

	return 0;
}
