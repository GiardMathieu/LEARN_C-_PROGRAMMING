//============================================================================
// Name        : ArraysPractice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cctype>
using namespace std;

double dotProduct(const double vector1[], const double vector2[], int length);

char GetCharacter(const char * prompt, const char * error);

char GetCharacter(const char * prompt, const char* error, const char validInput[], int validInputLength);

const int IGNORE_CHARS = 256;

int main() {
	//Problem 1 Write a function that takes 2 vectors and returns the dot product of the two vectors. The vectors must be the same size

	double vector1[3] = {1, 4 , 7};
	double vector2[3] = {2, 5 , 8};

	//cout << "The dot product of the 2 vectors is: " << dotProduct(vector1, vector2, 3);

	//Problem 2 Write a function called GetCharacter that will take in a cstring prompt, an error cstring and return a character from stdin from the user.
	 // if the user types something incorrectly or the input doesn't match the valid inputs, the function should recover from the failure gracefully and output the error
	 // cstring and prompt the user to try again.


	char validInputs[] = {'y', 'n'};

	char input = GetCharacter("Would you like to play again ? (y/n) ", "Input Error! Please try again !", validInputs, 2);
	cout << "The character you input was: " << input << endl;

	return 0;
}


double dotProduct(const double vector1[], const double vector2[], int length){
	double product = 0;

	for (int i = 0; i < length; i++) {
		product += (vector1[i] * vector2[i]);
	}

	return product;

}

char GetCharacter(const char * prompt, const char * error){
	char input;
	bool failure;

	do {
		failure = false;

		cout << prompt;
		cin >> input;

		if(cin.fail()){
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << error << endl;
			failure = true;
		} else {
			cin.ignore(IGNORE_CHARS, '\n');
			if (isalpha(input)){
				input = tolower(input);
			} else {
				cout << error << endl;
				failure = true;
			}
		}
	} while(failure);
	return input;


}

char GetCharacter(const char * prompt, const char* error, const char validInput[], int validInputLength){
	char input;
	bool failure;

	do {
		failure = false;

		cout << prompt;
		cin >> input;

		if(cin.fail()){
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << error << endl;
			failure = true;
		} else {

			cin.ignore(IGNORE_CHARS, '\n');
			if (isalpha(input)){
				input = tolower(input);

				for (int i = 0; i < validInputLength; i++) {
					if (input == validInput[i]){
						return input;
					}
				}
			}

			cout << error << endl;
			failure = true;
		}
	} while(failure);
	return input;

}


