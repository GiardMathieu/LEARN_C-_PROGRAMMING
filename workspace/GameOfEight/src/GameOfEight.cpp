//============================================================================
// Name        : GameOfEight.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int getGuess(int attempts, int numLeft);
int substract(int initialNumber, int guessedNumber);
void getWinner(int attempts);
bool WantToPlayAgain();

int main() {
	const int INITIAL_NUMBER = 8;
	int numLeft;
	int attempts = 1;
	int guessedNumber;


	do {
		numLeft = INITIAL_NUMBER;
		do {
			attempts++;
			guessedNumber = getGuess(attempts, numLeft);
			numLeft = substract(numLeft, guessedNumber);
		} while(numLeft != 0);
		getWinner(attempts);
	} while(WantToPlayAgain());
	cout << "GAME OVER !" << endl;




}


int getGuess(int attempts, int numLeft) {
	int guessedNumber;
	bool failure;
	if (attempts % 2 == 0) {
		cout << "Player 1, please enter a guess: " << " Remaining: " << numLeft << endl;
	} else cout << "Player 2. please enter a guess " << " Remaining: " << numLeft << endl;
	do {
		failure = false;
		cout << "Enter a number that is in the range of 1 to 3: " << endl;
		cin >> guessedNumber;
		if (cin.fail() || guessedNumber > 3 || guessedNumber < 1) {
			failure = true;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Error! You have not entered a valid number between 1 and 3." << endl;
		}
	} while (failure);
	return guessedNumber;
}

int substract(int num1, int num2){
	if (num2 > num1) {
		return num1;
	}
	return num1 - num2;
}

void getWinner(int attempts) {
	if (attempts % 2 == 0) {
		cout << "Player 1 has won !" << endl;
	} else {
		cout << "Player 2 has won !" << endl;
	}
}

bool WantToPlayAgain() {
	char input;
	bool failure;
	do {
		failure = false;
		cout << "Do you want to play again ? Enter 'Y' for Yes or 'N' for No (uppercase): " << endl;
		cin >> input;
		if (cin.fail() || (input != 'Y' && input != 'N')) {
			failure = true;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "ERROR! You did not enter the two options available! Try again ! " << endl;
		}
	} while(failure);
	if (input == 'Y') return true;
	return false;

}

