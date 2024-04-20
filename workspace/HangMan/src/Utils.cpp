/*
 * Utils.cpp
 *
 *  Created on: Mar. 18, 2024
 *      Author: Mathy
 */
#include "Utils.h"
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

char GetCharacter(const char * prompt, const char * error){
	char input;
	bool failure;
	const int IGNORE_CHARS = 256;


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
	const int IGNORE_CHARS = 256;


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

void ClearScreen() {
	system("cls"); // For windows
	//system("clear") for MAC;
}

void WaitForKeyPress() {
	system("pause"); //Windows;
	// system(read -n 1 -s -p \"Press any key to continue..."\";echo"); FOR MAC
}
