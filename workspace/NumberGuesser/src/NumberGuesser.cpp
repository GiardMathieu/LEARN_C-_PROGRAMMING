//============================================================================
// Name        : NumberGuesser.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

/*

  do {
  	  Play The Game

  } while (want to play again)

  do {
   1. set the secret number
   2. set the number of guesses -> ceil(log2(100))

   do {
   3.Prompt the user to make a guess (output the number of guesses left)
   4. Get the guess from the player
   5. Check to see if the guess is not equal to the secret number
    5a1. decrement the number of guesses left
    5a2. check to see if the guess was higher or lower than the secret number
     5a2a. If it was higher, print that it was too high
     5a2b. If it was lower, print that it was too low
  } while (the game is not over)
  Display the result - tell the player if he got it or not

  functions:
  Play the Game -> PlayGame();
  Want to play again -> WantToPlayAgain();
  Get the guess from the player -> Get Guess();

  the game is not over -> IsGameOver();
  number of guesses left == 0 || player's guess == secret number

  Display results -> DisplayResults();
  if the player got it print that they got it and print the secret number
  if the player didnt get it prnit that they failed

 */

int PlayGame(int minimum = 0, int maximum = 10);
bool WantToPlayAgain();
int getGuess();
bool isGameOver(int guesses);
string DisplayResults();


int main() {



	do {
		int minimum; int maximum;
		cout << "Enter the minimum value and the maximum value with spaces in between: " << endl;
		cin >> minimum >> maximum;
		PlayGame(minimum, maximum);
	} while(WantToPlayAgain() == 1);

	return 0;
}

int PlayGame(int minimum, int maximum){

	int randInt = rand()%(maximum-minimum + 1) + minimum;
	cout << randInt << endl;
	int numberGuesses = ceil(log2(maximum));
	cout << "Guess the number between " << minimum << " and " << maximum << "; You have " << numberGuesses << " guesses" << endl;
	do {
		int guess = getGuess();
		if (guess == randInt) {
			cout << "Congrats ! You managed to guess the random number with " << numberGuesses << " remaining ! " << endl;
			numberGuesses = 0;
		} else if(guess > randInt){
			numberGuesses--;
			cout << "The number you entered is bigger than the random number ! You have " << numberGuesses << " remaining ! " << endl;
		} else {
			numberGuesses--;
			cout << "The number you entered is lower than the random number ! You have " << numberGuesses << " remaining ! " << endl;
		}
	} while(!isGameOver(numberGuesses));
	return 1;
}

bool WantToPlayAgain(){
	char playerWants = ' ';
	cout << "Do you want to play again ? Y for Yes and N for No : " << endl;
	cin >> playerWants;
	if (playerWants == 'Y') return 1;
	return 0;
}

int getGuess(){
	int guessedNumber;
	bool failure;
	do {
		failure = false;
		cin >> guessedNumber;
		if(cin.fail()) {
			cin.clear();
			failure = true;
			cout << "Error in the input! Try again : " << endl;
		}

	} while (failure);
	return guessedNumber;
}

bool isGameOver(int guesses){
	if (guesses == 0) {
		return 1;
	}
	return 0;
}
string DisplayResults();
