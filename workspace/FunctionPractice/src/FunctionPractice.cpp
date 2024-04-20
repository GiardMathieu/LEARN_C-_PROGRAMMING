//============================================================================
// Name        : FunctionPractice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//void Circle(double radius);
//const float PI = 3.1416;

bool isPrime(int x);
string boolToString(bool boolean);
void getAllPrime(int x, int y);

int main() {
	/*
	 Problem 1: Write a program that takes a radius as input and calculates the diameter the circumference
	 and area of the given circle using functions



	double radius;
	cout << "Please enter the value of the radius of the circle : " << endl;

	cin >> radius;
	Circle(radius);
	*/

	/*
	Write a function that takes in an integer and returns true if the integer is a prime number

	 */
	/*
	int x;
	cout << "Please enter the value of the integer x : " << endl;
	cin >> x;

	cout << "Is " << x << " a prime number ?: " << boolToString(isPrime(x)) << endl;
	*/
	/*
	 * Write a function to find all prime numbers between two intervals
	 */
	int x, y;
	cout << "Please enter the value of x and y with spaces in between " << endl;
	cin >> x >> y;
	getAllPrime(x, y);
	return 0;
}
/*
void Circle(double radius) {
	cout << "The diameter of the circle is " << radius * 2 << endl;
	cout << "The circumference of the circle is " << (2 * PI * radius) << endl;
	cout << "The area of the circle is " << PI * (radius * radius) << endl;

}
*/

bool isPrime(int x) {
	bool prime = true;
	for (int i = 1; i < x; i++){
		if (x % i == 0 && i != 1){
			prime = false;
		}
	}
	return prime;
}

string boolToString(bool boolean) {
	if (boolean == 0) {
		return "false";
	} else return "true";
}



void getAllPrime(int x, int y){
	cout << "The prime numbers between " << x << " and " << y << " are " << endl;
	for (int i = x; i < y; i++) {
		if (isPrime(i)){
			cout << i << " ";
		}
	}
}

