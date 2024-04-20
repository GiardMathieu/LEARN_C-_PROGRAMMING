/*
 * Utils.cpp
 *
 *  Created on: Apr. 12, 2024
 *      Author: Mathy
 */

using namespace std;
#include "Utils.h"
#include <cctype>
#include <cstring>
#include <iostream>

char GetCharacter(const char * prompt, const char * error) {
	char input;
	bool failure;

	const int IGNORE_CHARS = 256;

	do {
		failure = false;

		cout << prompt;
		cin >> input;

		if(cin.fail()) {
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << error << endl;
			failure = true;
		}
	} while(failure);
	return input;
}

char GetCharacter(const char * prompt, const char * error, const char validInputs[], int validInputLength, CharacterCaseType charCase) {
	char input;
	bool failure;

	const int IGNORE_CHARS = 256;

	do {
		failure = false;

		cout << prompt << endl;
		cin >> input;

		if(cin.fail()) {
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << error << endl;
			failure = true;
		} else {
			cin.ignore(IGNORE_CHARS, '\n');

			if(isalpha(input)) {
				if (charCase == CC_UPPER_CASE) {
					input = toupper(input);
				} else if (charCase == CC_LOWER_CASE) {
					input = tolower(input);
				}
				for(int i = 0; i < validInputLength; i++) {
					return input;
				}
			}
			cout << error << endl;
			failure = true;
		}
	} while (failure);
}

int GetInteger(const char * prompt, const char* error, const int validInput[], int validInputLength){
	int input;
	bool inputFailure;

	const int IGNORE_CHARS = 256;


	do {
		inputFailure = false;
		cin >> input;

		if(cin.fail()) {
			inputFailure = true;
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << error << endl;
		} else {
			for(int i = 0; validInputLength; i++) {
				if(input == validInput[i]) {
					return input;
				}
			}
		}
		cout << error << endl;
		inputFailure= true;
	} while(inputFailure);
}


