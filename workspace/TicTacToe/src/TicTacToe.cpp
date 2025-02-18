//============================================================================
// Name        : TicTacToe.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void DrawGrid(char * gridBoard);
void PlayGame();
void inputIdxValue(char * gameArray, const int gameArrayLength, char playerName, int numPlayer);

bool WantToPlayAgain();
bool isGameOver(char * noptrGridBoard);

char GetCharacter(const char * prompt, const char* error, const char validInput[], int validInputLength);
char GetCharacter(const char * prompt, const char * error);



const char * INPUT_ERROR_STRING = "Input error! Please try again !";

const int MAX_GRID_LENGTH = 9;


int main() {


	/*
	 * Write the game of Tic Tac Toe. It's a game with a 3 by 3 grid played by 2 players. One player places O markers and the other player places X markers.
	 * Each player takes turns placing his/her marker in order to get 3 of their markers to line up on the board. A player wins when 3 or their markers line up either horizontally, vertically or diagonally.
	 * If no player has their markers line up in that fashion, and the board is full, then the game is called a "Cat Game". Your program should output the winner of the game or "Cat Game" if there was no winner.
	 * The user should be prompted if they would like to play again when the game is over. If they choose to play again, the player who started second last game should go first.
	 *
	 */

	do {
		PlayGame();
	} while(WantToPlayAgain());



	return 0;
}


// Function PlayGame();
void PlayGame() {
	char player1Name = GetCharacter("Player 1, please enter your name: ", INPUT_ERROR_STRING);
	char player2Name = GetCharacter("Player 2, please enter your name: ", INPUT_ERROR_STRING);

	char * optrGridBoard = nullptr;
	char playingBoard[MAX_GRID_LENGTH] = {'-','-','-','-','-','-','-','-','-'};
	optrGridBoard = playingBoard;

	do {
		inputIdxValue(optrGridBoard, MAX_GRID_LENGTH, player1Name, 1);
		DrawGrid(optrGridBoard);
		inputIdxValue(optrGridBoard, MAX_GRID_LENGTH, player2Name, 2);
		DrawGrid(optrGridBoard);


	}while(!isGameOver(optrGridBoard));

}

// Want to play again function
bool WantToPlayAgain() {
	const char validInputs[] = {'y', 'n'};

	char response = GetCharacter("Would you like to play again? (y/n) ", INPUT_ERROR_STRING, validInputs, 2);

	return response =='y';
}

// Function GetCharacter();
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


// Need a function that receives the input from a player to get the index, if it's valid, the idx entered its value will be changed to 'O' or 'X'
void inputIdxValue(char * noptrGridBoard, const int gameArrayLength, char playerName, int numPlayer) {
	const int IGNORE_CHARS = 256;
	bool failure;
	int idx;
	do {
		failure = false;
		cout << "Please enter a number between 0 and 8: ";
		cin >> idx;

		if(cin.fail()) {
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << "You need to enter a value between 0 and 8 (0 and 8 included)";
			failure = true;
		} else {
			cin.ignore(IGNORE_CHARS, '\n');
			if (idx >= 0 && idx <= 9) {
				if (noptrGridBoard[idx] == '-') {
					if (numPlayer == 1) {
						noptrGridBoard[idx] = 'O';
					}
					if (numPlayer == 2) {
						noptrGridBoard[idx] = 'X';
					}
				} else {
					cout << "You cannot overtake a grid index that has been registered already! Try again!" << endl;
					failure = true;
				}
			}
		}

	} while(failure);




}


/*
 * Function that creates an array
 */



/*
 * Need a function that draws a grid and outputs it with the values of the array
 * 											 0  1  2  3  4  5  6  7  8
 * Example, the array could look like this: [o, x, o, -, x, o, x, -, -]
 * The grid needs to be
 *  +---+---+---+
 *  | 0	| 1 | 2 |
 *  +---+---+---+
 *  | 3 | 4 | 5 |
 *	+---+---+---+
 *	| 6 | 7 | 8 |
 *  +---+---+---+
 */

void DrawGrid(char * noptrGridBoard) {

	cout << noptrGridBoard[0] << "   " << noptrGridBoard[1] << "   " << noptrGridBoard[2] << endl;
	cout << noptrGridBoard[3] << "   " << noptrGridBoard[4] << "   " << noptrGridBoard[5] << endl;
	cout << noptrGridBoard[6] << "   " << noptrGridBoard[7] << "   " << noptrGridBoard[8] << endl;


	//cout << noptrGridBoard[9];
}

/*
 * Function to see if a player one, the conditions are: Diagonal, line (in a while function)
 *
 * Horizontal Line example: if(idxArray[0] == idxArray[1] && idxArray[1] == idxArray[2])
 *
 * Vertical Line example: if(idxArray[0] == idxArray[3] && idxArray[3] == idxArray[6]);
 *
 * Diagonal Line example: if (idxArray[0] == idxArray[4] && idxArray[4] == idxArray[8]);
 *
 */

bool isGameOver(char * noptrGridBoard){
	 /*  +---+---+---+
	 *  | 0	| 1 | 2 |
	 *  +---+---+---+
	 *  | 3 | 4 | 5 |
	 *	+---+---+---+
	 *	| 6 | 7 | 8 |
	 *  +---+---+---+
	 */
	//Horizontal line conditions:

	if ((noptrGridBoard[0] == noptrGridBoard[1] && noptrGridBoard[1] == noptrGridBoard[2]) ||
		 (noptrGridBoard[3] == noptrGridBoard[4] && noptrGridBoard[4] == noptrGridBoard[5] ) ||
		 (noptrGridBoard[6] == noptrGridBoard[7] && noptrGridBoard[7] == noptrGridBoard[8]))
	{
		cout << "A player has completed a line !" << endl;
		return true;
	}

	//Diagonal line conditions
	if ((noptrGridBoard[0] == noptrGridBoard[4] && noptrGridBoard[4] == noptrGridBoard[8])
		 || (noptrGridBoard[2] == noptrGridBoard[4] && noptrGridBoard[4] == noptrGridBoard[6]))
	{
		cout << "A player has completed a diagonal line !" << endl;
		return true;
	}
	//Vertical line conditions
	if ((noptrGridBoard[0] == noptrGridBoard[3] && noptrGridBoard[3] == noptrGridBoard[6])
		 || (noptrGridBoard[1] == noptrGridBoard[4] && noptrGridBoard[4] == noptrGridBoard[7])
		 || (noptrGridBoard[2] == noptrGridBoard[5] && noptrGridBoard[5] == noptrGridBoard[8]))
	{
		cout << "A player has completed a Vertical line ! " << endl;
		return true;
	}
	return false;
}


// Display Result function that shows which player won


