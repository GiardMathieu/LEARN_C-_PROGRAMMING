//============================================================================
// Name        : DynamicMemory101.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int * Func();
void Use(int * noptrInt);

int main() {
	//int * optrnewInt = Func();
	//Use(optrnewInt);

	//delete optrnewInt;

	//optrnewInt = nullptr;

	int * ptr = new int[10];


	return 0;
}


void Use(int * noptrInt) {

}

int * Func() {
	return new int;
}
