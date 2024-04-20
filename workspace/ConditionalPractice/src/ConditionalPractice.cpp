//============================================================================
// Name        : ConditionalPractice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	//Problem 1 write a program that inputs a character and outputs whether or not it is in the alphabet
	/*
	char letter = '_';
	cout << "Write a value for the character : " << endl;
	cin >> letter;

	if ((((int) letter >= 97) && (int)letter <= 122) || (((int) letter >= 65) && (int) letter <= 90)){
		cout << "The letter " << letter << "is in the alphabet !" << endl;
	} else {
		cout << "The letter " << letter << " is not in the alphabet !" << endl;
	}
	*/

	//Problem 2 Write a program that takes in 3 numbers and outputs the biggest number and the smallest number
	/*
	int nb1 = 0, nb2 = 0, nb3 = 0;

	cout << "Write the value for three numbers with spaces in between " << endl;
	cin >> nb1 >> nb2 >> nb3;

	if (nb1 > nb2 && nb2 > nb3) {
		cout << "The biggest number is " << nb1 << " and the smallest number is " << nb3 << endl;
	} else if (nb2 > nb1 && nb1 > nb3) {
		cout << "The biggest number is " << nb2 << " and the smallest number is " << nb3 << endl;
	} else if (nb3 > nb2 && nb2 > nb1) {
		cout << "The biggest number is " << nb3 << " and the smallest number is " << nb1 << endl;
	}
	*/

	//Problem 3 Write a program that enters 3 sides of a triangle and checks whether the triangle is valid or not. Remember that a triangle is valid if and only if the sum of any two sides is greater than the third side
	/*int size1 = 0, size2 = 0, size3 = 0;

	cout << "Enter the value of the three sizes with spaces in between " << endl;
	cin >> size1 >> size2 >> size3;

	if (size1 + size2 > size3 && size2 + size3 + size2 > size3 && size1 + size3 > size3) {
		cout << "You have entered valid dimensions for the triangle !" << endl;
	} else cout << "The triangle is not valid! Try again. " << endl;
	*/

	//Problem 4 Write a program to enter any alphabet and check whether alphabet is vowel or consonant using switch case
	char alpha = '_';
	cout << "Write a letter of the alphabet: " << endl;
	cin >> alpha;

	switch (alpha) {
	case 'a':
		cout << "The letter '" << alpha << "' is a vowel !" << endl;
		break;
	case 'e':
		cout << "The letter '" << alpha << "' is a vowel !" << endl;
		break;
	case 'i':
		cout << "The letter '" << alpha << "' is a vowel !" << endl;
		break;
	case 'o':
		cout << "The letter '" << alpha << "' is a vowel !" << endl;
		break;
	case 'u':
		cout << "The letter '" << alpha << "' is a vowel !" << endl;
		break;
	case 'y':
		cout << "The letter '" << alpha << "' is a vowel !" << endl;
		break;
	default:
		cout << "The letter '" << alpha << "'is a consonant !" << endl;
	}


	return 0;
}
