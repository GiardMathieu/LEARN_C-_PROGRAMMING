//============================================================================
// Name        : HangMan.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <cctype>


using namespace std;

#include "Utils.h"

const int IGNORE_CHARS = 256;

const char * INPUT_ERROR_STRING = "Input error! Please try again !";

void PlayGame();
bool WantToPlayAgain();

int GetSecretPhrase(char secretPhrase[], int maxLength);

void UpdateBoard(char guess, char * noptrHiddenPhrase, const char secretPhrase[], int secretPhraseLength, int & numberOfGuessesLeft);

bool IsGameOver(int numberOfGuessesLeft, const char * noptrHiddenPhrase, int secretPhraseLength);

void DisplayResult(const char * secretPhrase, int numberOfGuessesLeft);

char GetGuess();

char * MakeHiddenPhrase(const char * secretPhrase, int secretPhraseLength);
void DrawBoard(int numberOfGuessesLeft, const char * noptrHiddenPhrase);

int main() {


	/*
	 * Create the program Hangman. Prompt the plyaer to enter a phrase
	 * That phrase will be hidden by a series of dashes (excluding spaces).
	 * The player can then guess letters. If they guess correctly all the letters that match will be revealed.
	 * If they lose the gallows should look like this
	 *
	 * +---+
	 * |   |
	 * |   o
	 * |  /|\
	 * |  / \
	 *-+-
	 *-+- _ _ _ _ _ _ _ _ _ _ _ (Secret phrase that is hidden)
	 *-+-
	 * If the player loses, the word should be revealed.
	 * After the game is over the player should be prompted if they want to play again
	 *
	 */

	// We need a way of storing the secret phrase
	// We need a way of storing the hidden phrase (with dashes);
	// We need a variable that holds the number of guesses left. (set to 6 intially);


	/*
	 * Step 1
	 *
	 * do {
	 * {
	 * 	PlayGame
	 * } while (WantToPlayAgain)
	 *
	 *
	 */

	/*
	 * initialize the game
	 *
	 * Step 2
	 *
	 * Get the secret word
	 * secretPhrase = getSecretPhrase();
	 * hiddenPhrase = MakeHiddenPhrase(secretPhrase);
	 * numberOfGuessesLeft = 6;
	 *
	 * Make the hidden word (using the secret word)
	 * Set the number of guesses left (6)
	 *
	 * Draw the board(hiddenPhrase)
	 *
	 *
	 *	Step3 Get the secret phrase
	 *
	 *	Prompt the user for the secret phrase
	 *	get the secret phrase
	 *	return secret phrase
	 *
	 *	MaheHiddenPhrase(secretPhrase)
	 *	-------------------------------
	 *
	 *	hiddenPhrase = make new cstring given the length of the secret phrase
	 *
	 *	for(length of the secret phrase) {
	 *		hiddenPhrase[i] = '_';
	 *	}
	 *	return hiddenPhrase
	 *
	 *
	 *	Updating the board(guess, secretPhrase, hiddenPhrase, numberOfGuessesLeft);
	 *	------------------
	 *	bool found = false;
	 *	for (length of the secretPhrase){
	 *		if (secretPhrase[i] == guess)
	 *		{
	 *			hiddenPhrase[i] = guess;
	 *			found = true;
	 *		}
	 *		if (!found)
	 *		{
	 *			numberOfGuessesLeft --;
	 *
	 *		}
	 *	}
	 *
	 * do {
	 *  Prompt the player
	 * 	Get the input from the user
	 * 	Update Game
	 * 	Draw Game
	 *
	 * } while (Game is not over)
	 *
	 */

	/*
	 *
	 * WantToPlayAgain
	 * prompt the user
	 *
	 * Get the input
	 *
	 *  return true if the user wanted to play again
	 */

	do {
		PlayGame();
	} while(WantToPlayAgain());


	return 0;
}

void PlayGame(){
	const int MAX_LENGTH_OF_SECRET_PHRASE = 256;
	const int MAX_NUMBER_OF_GUESSES = 6;

	char secretPhrase[MAX_LENGTH_OF_SECRET_PHRASE];
	char * optrHiddenPhrase = nullptr;
	int numberOfGuessesLeft = MAX_NUMBER_OF_GUESSES;

	int secretPhraseLength = GetSecretPhrase(secretPhrase, MAX_LENGTH_OF_SECRET_PHRASE);

	optrHiddenPhrase = MakeHiddenPhrase(secretPhrase, secretPhraseLength);

	DrawBoard(numberOfGuessesLeft, optrHiddenPhrase);

	char guess;
	do {
		guess = GetGuess();

		UpdateBoard(guess, optrHiddenPhrase, secretPhrase, secretPhraseLength, numberOfGuessesLeft);

		DrawBoard(numberOfGuessesLeft, optrHiddenPhrase);

	} while(!IsGameOver(numberOfGuessesLeft, optrHiddenPhrase, secretPhraseLength));

	DisplayResult(secretPhrase, numberOfGuessesLeft);
	delete [] optrHiddenPhrase;

}

char GetGuess() {
	return GetCharacter("Please input your guess: ", INPUT_ERROR_STRING);
}

bool WantToPlayAgain() {
	const char validInputs[] = {'y', 'n'};

	char response = GetCharacter("Would you like to play again? (y/n) ", INPUT_ERROR_STRING, validInputs, 2);

	return response == 'y';
}

int GetSecretPhrase(char secretPhrase[], int maxLength) {
	bool failure;
	int length;
	do {
		failure = false;

		cout << "Please enter the secret phrase: ";
		cin.get(secretPhrase, maxLength);

		if(cin.fail()) {
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << INPUT_ERROR_STRING << endl;
			failure = true;
		} else {
			length = strlen(secretPhrase);
			if(length == 0) {
				cout << "You must enter a word that's longer than 0 characters ! Please try again! " << endl;
				failure = true;
			}
		}

	} while(failure);

	return length;
}



char * MakeHiddenPhrase(const char * secretPhrase, int secretPhraseLength){
	char * hiddenPhrase = new char[secretPhraseLength+1];

	for(int i = 0; i < secretPhraseLength; i++) {
		if(secretPhrase[i] != ' '){
			hiddenPhrase[i] = '-';
		} else
			hiddenPhrase[i] = ' ';
	}
	hiddenPhrase[secretPhraseLength] = '\0';
	return hiddenPhrase;
}

void UpdateBoard(char guess, char * noptrHiddenPhrase, const char secretPhrase[], int secretPhraseLength, int & numberOfGuessesLeft){
	bool found = false;

	for (int i = 0; i < secretPhraseLength; i++) {
		if (tolower(secretPhrase[i]) == guess) {
			noptrHiddenPhrase[i] = secretPhrase[i];
			found = true;
		}
	}
	if (!found) {
		numberOfGuessesLeft--;
		cout << "Guesses left: " << numberOfGuessesLeft << endl;
	}
}

bool IsGameOver(int numberOfGuessesLeft, const char * noptrHiddenPhrase, int secretPhraseLength) {
	bool hasDash = false;

	for(int i =0; i < secretPhraseLength; i++) {
		if (noptrHiddenPhrase[i] == '-') {
			hasDash = true;
			break;
		}
	}

	return numberOfGuessesLeft == 0 || !hasDash;
}



void DrawBoard(int numberOfGuessesLeft, const char * noptrHiddenPhrase){
	ClearScreen();
	WaitForKeyPress();
	switch(numberOfGuessesLeft){
	case 0:
	{
		cout << " +--+" << endl;
		cout << " |  |" << endl;
		cout << " |  O" << endl;
		cout << " | /|\\" << endl;
		cout << " | / \\" << endl;
		cout << "-+-" << endl << endl;

	}
	break;
	case 1:
	{
		cout << " +--+" << endl;
		cout << " |  |" << endl;
		cout << " |  O" << endl;
		cout << " | /|\\" << endl;
		cout << " | / " << endl;
		cout << "-+-" << endl << endl;

	}
	break;
	case 2:
	{
		cout << " +--+" << endl;
		cout << " |  |" << endl;
		cout << " |  O" << endl;
		cout << " | /|\\" << endl;
		cout << "-+-" << endl << endl;
	}
	break;

	case 3:
	{
		cout << " +--+" << endl;
		cout << " |  |" << endl;
		cout << " |  O" << endl;
		cout << " | /|" << endl;
		cout << " |  " << endl;
		cout << "-+-" << endl << endl;
	}
	break;

	case 4:
	{
		cout << " +--+" << endl;
		cout << " |  |" << endl;
		cout << " |  O" << endl;
		cout << " |  |" << endl;
		cout << " | " << endl;
		cout << "-+-" << endl << endl;

	}
	break;
	case 5:
	{
		cout << " +--+" << endl;
		cout << " |  |" << endl;
		cout << " |  O" << endl;
		cout << " | " << endl;
		cout << " | " << endl;
		cout << "-+-" << endl << endl;
	}
	break;
	case 6:
	{
		cout << " +--+" << endl;
		cout << " |  |" << endl;
		cout << " |  " << endl;
		cout << " | " << endl;
		cout << " | " << endl;
		cout << "-+-" << endl << endl;
	}
	break;
	default:
		break;
	}
	cout << "Secret Phrase: " << noptrHiddenPhrase << endl << endl;

}

void DisplayResult(const char * secretPhrase, int numberOfGuessesLeft){
	if (numberOfGuessesLeft > 0) {
		cout << "You got it ! The phrase was: " << secretPhrase << endl;
	} else
		cout << "You didnt get it.... The phrase was " <<  secretPhrase << endl;
}




