//============================================================================
// Name        : ArrayPracticeProblems.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

char* cStringReverse(const char * string, int length);
void copyTable1ToTable2(int table1[], int * table2[]);

int main() {
	/*
	char cString[] = "Hello";

	cout << "Le reverse de " << cString << " est: " << cStringReverse(cString, 5);
	*/
	int lengthTable 5;


	int table1[lengthTable] = {10,20,30,40,100};
	int table2[lengthTable] = {};

	cout << "La deuxieme table avec les elements de la premiere table"
	return 0;
}

//Problem 1: Write a function that will reverse a C String. For example if the string was "Hello" it should be reversed to "olleH"

char* cStringReverse(const char * string, int length){
	char* newString = new char[length + 1];
	newString[length] = '\0';

	for (int i = 0; i < length; i++) {
		newString[i] = string[length-1-i];
	}
	return newString;
}
//Problem 2 Write a program to read elements in an array and copy all elements of first array into second array

void copyTable1ToTable2(int table1[], int * table2[], int length){
	for (int i = 0; i < length; i++) {
		* table2[i] = table1[i];
	}
}

