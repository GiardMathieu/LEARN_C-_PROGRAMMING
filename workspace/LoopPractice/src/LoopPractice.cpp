//============================================================================
// Name        : LoopPractice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	//Problem 1 Write a program that will take a number from the user and print the reverse order of that number 1234 -> 4321

	/*
	int num = 0, reverse = 0;
	cout << "Please enter the value of the number : " << endl;
	cin >> num;

	while (num > 0){
		reverse = (reverse * 10) + (num % 10);
		// 0 + 4
		//40 + 3
		//430 + 2
		//4320 + 1

		num /= 10;
	}
	cout << "The reverse is: " << reverse << " and the num is " << num << endl;
	*/

	//Problem 2 Write a program that takes in two numbers from the user and peints a start pattern in a rectangular form;
	/*
	int length = 0, height = 0;
	cout << "Please enter the value of the length and the height with spaces in between : " << endl;
	cin >> length >> height;

	for (int i = 0; i < height; i++) {
		for (int j = 1; j <= length; j++) {
			cout << " * ";
		}
		cout << endl;
	}
	*/

	//Problem 3 Write a program that takes in a number and prints a pyramid star pattern
	/*
	int number = 0;
	cout << "Please enter a value for the number : " << endl;
	cin >> number;

	for (int i = 0; i < number; i++) {

		for (int j = 0; j < (number - i - 1); j++) {
			cout << ' ';
		}

		for (int j = 0; j < (2 * i + 1); j++){
			cout << '*';
		}
		cout << endl;
	}
	*/

	//Problem 4 Write a program to read binary number from user and find the one's complement
	int binary = 0, complement = 0;
	cout << "Please enter a binary number " << endl;
	cin >> binary;

	while(binary > 0) {

		binary /= 10;
	}



	return 0;
}
