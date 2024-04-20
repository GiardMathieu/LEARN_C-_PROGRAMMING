//============================================================================
// Name        : DynamicMemoryPractice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <cstring>
#include <iostream>
using namespace std;

char * ReverseCopy(char  * phrase);

int main() {
	//Problem 1: Read a phrase from the user and output it again

	const int MAX_BUFFER_LENGTH = 256;

	char buffer[MAX_BUFFER_LENGTH];

	cout << "Please enter a phrase: ";

	cin.get(buffer, MAX_BUFFER_LENGTH-1);

	cout << "Your input was: " << buffer << endl;


	// Problem 2: Using problem 1, make a function that will take the input and reverse it
	char * optrReversePhrase = ReverseCopy(buffer);

	cout << "The phrase in reverse is: " << optrReversePhrase << endl;

	delete[] optrReversePhrase;

	return 0;

}


char * ReverseCopy(char * phrase){
	int length = strlen(phrase);

	char * reverseString = new char [length+1]; // +1 for the null character

	int j = 0;

	for(int i = length-1; i >= 0; i--) {
		reverseString[j] = phrase[i];

		j++;
	}

	reverseString[j] = '\0'; //null character
	return reverseString;
}
