//============================================================================
// Name        : Functions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
/*
void Print(int x);
void Print(char c);
void Print(int x, char c);
*/

int CalcVolumeOfRectangularPrism(int width, int length = 2, int height = 10);


int main() {

	//Print(5);
	//Print('c');
	//Print(5, 'c');
	int width = 5;
	int length = 5;
	cout << "The volume of the prism is " << CalcVolumeOfRectangularPrism(width) << endl;


	return 0;
}

int CalcVolumeOfRectangularPrism(int width, int length, int height) {
	return width * length * height;
}

/*
void Print(int x) {
	cout << "Printing integer: " << x << endl;
}

void Print(char c) {
	cout << "The character is: " << c << endl;
}

void Print(int x, char c) {
	cout << "The integer is: " << x << " and the character is : " << c << endl;
}

*/
