//============================================================================
// Name        : Battleship.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "Utils.h"

using namespace std;

/*
 Game: Battleship
 The game is played on four 10x10 grids by 2 players, with each player having 2 grids each.
 The rows of the grid go from A to J in the rows and 1 to 10 in the columns. Each player will arrange their ships on
 their respective ship board before the main game starts. Each ship occupies a number of consecutive squares on the
 grid, arranged either horizontally or vertically. The number of squares for each ship is determined by the type
 of the ship. The ships cannot overlap.

 The ships are as follows:

 Ship type       		Size
 --------------------+----------
 Aircraft carrier    |    5
 Battleship          |    4
 Cruiser             |    3
 Destroyer           |    3
 Submarine           |    2

 After the ships have been positioned, the game proceeds in a series of rounds. In each round, each player takes a turn
 to announce a target square in the opponent's grid which is to be shot at. The opponent announces whether or not
 the square is occupied by a ship, and if it is a miss, the player marks their guess board as a miss; if it is a hit
 they mark it as a hit. This is to build up a picture of the opponent's fleet. If the guess was a hit, the attacked
 player will mark their ship as hit in the guessed location. That will end the turn.

 When all of the squares of a ship have been hit, the ship is sunk and there is output about what ship was sunk.
 If all the player's ship have been sunk, the game is over and their opponent wins.


+---+
|   |
+---+

        +---------------+
Input   |               |
--------+               |   Output
        |     XForm     +---------
--------+               |
        |               |
        +---------------+


    General:
    - Ships
    - Boards
    - Players
    - Guess (position on the board)

    Ships
    -----
    -5 types - listed above
    -Have a size
    -Has a position on the board (row between A - J, columns between 1 - 10)
    -Orientation (either vertical or horizontal)
    -Can be damaged in a specific spot

    Boards
    ------
    - 2 different boards - Ship boards (where you place all your ships), guess board (your view of the opponent's board)
    - Each position on the Guess board can be in 3 states - hit, miss, we haven't guessed the spot
    - Board for ships - contain all the player's ships at certain locations, we place markers on the spots where our
    		ships have been hit

    	Players
    	-------
	- Name
	- All the ships
	- Guess board
	- Ship board

	Guess
	-----
	- Position on the board
	- Position has a row (A - J), columns (1 - 10)

 */

const char * INPUT_ERROR_STRING = "Input error! Please try again.";

enum
{
	AIRCRAFT_CARRIER_SIZE = 5,
	BATTLESHIP_SIZE = 4,
	CRUISER_SIZE = 3,
	DESTROYER_SIZE = 3,
	SUBMARINE_SIZE = 2,

	BOARD_SIZE = 10,
	NUM_SHIPS = 5,
	PLAYER_NAME_SIZE = 8, //Player1, Player2
	MAX_SHIP_SIZE = AIRCRAFT_CARRIER_SIZE
};

enum ShipType
{
	ST_NONE = 0,
	ST_AIRCRAFT_CARRIER,
	ST_BATTLESHIP,
	ST_CRUISER,
	ST_DESTROYER,
	ST_SUBMARINE
};

enum ShipOrientationType
{
	SO_HORIZONTAL = 0,
	SO_VERTICAL
};

struct ShipPositionType
{
	int row;
	int col;
};

struct Ship
{
	ShipType shipType;
	int shipSize;
	ShipOrientationType orientation;
	ShipPositionType position;
};

enum GuessType
{
	GT_NONE = 0,
	GT_MISSED,
	GT_HIT
};

struct ShipPartType
{
	ShipType shipType;
	bool isHit;
};

enum PlayerType
{
	PT_HUMAN = 0,
	PT_AI
};

struct Player
{
	PlayerType playerType;
	char playerName[PLAYER_NAME_SIZE];
	Ship ships[NUM_SHIPS];
	GuessType guessBoard[BOARD_SIZE][BOARD_SIZE];
	ShipPartType shipBoard[BOARD_SIZE][BOARD_SIZE];
};

/*
 	Step 1

	InitPlayer(player1, "Player1");
	InitPlayer(player2, "Player2");

	do
	{
		PlayGame(player1, player2);

	}while(WantToPlayAgain());

	PlayGame
	--------

	SetupBoard(player1);
	SetupBoard(player2);

	do
	{
		DrawBoards(currentPlayer)

		do
		{
			Prompt the current player for a guess
			guess = GetGuess()

		}while(!IsGuessValid(guess, currentPlayer));


		UpdateBoards(guess, currentPlayer, otherPlayer);
		DrawBoard(currentPlayer); //to see the result of the guess

		if(a ship was sunk on currentPlayer's turn)
		{
			output that the current player sunk that ship
		}
		WaitForKeyPress

		SwitchPlayers()

	}while(!GameIsOver());

	DisplayWinner()


	SetupBoards(player)
	-------------------

	ClearBoards(player)

	for(all the ships)
	{
		DrawBoards(player)

		currentShip = Get the current ship

		do
		{
			position = Get Board Position for the head of the ship
			orientation = Get the ship orientation

			isValidPlacement = IsValidPlacement(currentShip, position, orientation, player)
			if(!isValidPlacement)
			{
				output to the player that it was not a valid placement
			}
		}while(!isValidPlacement)

		PlaceShipOnBoard(player, currentShip, position, orientation)
	}

	IsValidPlacement(player, currentShip, position, orientation)
	---------------------------------------

	if(orientation == HORIZONTAL)
	{
		for(all the columns the currentShip would take up)
		{
			if(ship will overlap another ship or the ship will be off the board horizontally)
			{
				return false
			}
		}
	}
	else
	{
		for(all the rows the currentShip would take up)
		{
			if(ship will overlap another ship or the ship will be off the board vertically)
			{
				 return false;
			}
		}
	}

	return true


	PlaceShipOnBoard(player, ship, position, orientation)
	-----------------------------------

	ship.position = position
	ship.orientation = orientation

	if( orientation == HORIZONTAL)
	{
		for(all the columns the ship would take up)
		{
			set the ship part on the board at position.row and current column
		}
	}
	else
	{
		for(all the rows that the ship would take up)
		{
			set the ship part on the board at current row and position.col
		}
	}

	UpdateBoards(guess, currentPlayer, otherPlayer)
	--------------------------------

	if(otherplayer's ship board at guess is a ship)
	{
		//hit
		 set hit on the currentPlayer's guess board
		 apply damage to the otherPlayer's shipBoard
		 return shipType
	}
	else
	{
		set miss on the currentPlayer's guess board

		return ST_NONE
	}

	IsGameOver(player1, player2)
	----------------------------

	return AreAllShipsSunk(player1) || AreAllShipsSunk(player2)


	AreAllShipsSunk(player)
	------------------------

	for(all the player's ships)
	{
		if(!IsSunk(player, currentShip))
		{
			return false
		}
	}
	return true


	IsSunk(player, ship)
	--------------------

	if(ship.orientation == HORIZONTAl)
	{
		for(columns that ship takes up)
		{
			if(currentPosition on the shipBoard is not hit)
			{
				return false
			}
		}
	}
	else
	{
		for(rows that the ship takes up)
		{
			if(currentPosition on the shipBoard is not hit)
			{
				return false
			}
		}
	}

	return true

 */


void InitializePlayer(Player & player, const char * playerName);

void InitializeShip(Ship& ship, int shipSize, ShipType shipType);

void PlayGame(Player& player1, Player& player2);

bool WantToPlayAgain();

void SetupBoards(Player& player);

void ClearBoards(Player& player);

void  DrawBoards(const Player& player);

void DrawSeparatorLine();
void DrawColumnsRow();
void DrawShipBoardRow(const Player& player, int row);
void DrawGuessBoardRow(const Player& player, int row);
char GetGuessRepresentationAt(const Player& player, int row, int col);
char GetShipRepresentationAt(const Player& player, int row, int col);

const char * GetShipNameForShipType(ShipType shipType);
ShipPositionType GetBoardPosition();
ShipOrientationType GetShipOrientation();

bool IsValidPlacement(const Player& player, const Ship& currentShip,const ShipPositionType& shipPosition, ShipOrientationType orientation);

void PlaceShipOnBoard(Player& player, Ship& currentShip, const ShipPositionType& shipPosition, ShipOrientationType orientation);

ShipType UpdateBoards(ShipPositionType guess, Player& currentPlayer, Player& otherPlayer);

bool IsGameOver(const Player& player1, const Player& player2);

bool AreAllShipsSunk(const Player& player);

bool IsSunk(const Player& player, const Ship& ship);

void SwitchPlayers(Player ** currentPlayer, Player ** otherPlayer);

void DisplayWinner(const Player& player1, const Player& player2);


PlayerType GetPlayer2Type();

ShipPositionType GetAIGuess(const Player& aiPlayer);


void SetupAIBoards(Player & player);

int main()
{

	srand(time(NULL));

	Player player1;
	Player player2;

	InitializePlayer(player1, "Player1");
	InitializePlayer(player2, "Player2");

	do
	{
		PlayGame(player1, player2);

	}while(WantToPlayAgain());

	return 0;
}


void InitializePlayer(Player & player, const char * playerName)
{
	if(playerName != nullptr && strlen(playerName) > 0)
	{
		strcpy(player.playerName, playerName);
	}

	InitializeShip(player.ships[0], AIRCRAFT_CARRIER_SIZE, ST_AIRCRAFT_CARRIER);

	InitializeShip(player.ships[1], BATTLESHIP_SIZE, ST_BATTLESHIP);

	InitializeShip(player.ships[2], CRUISER_SIZE, ST_CRUISER);

	InitializeShip(player.ships[3], DESTROYER_SIZE, ST_DESTROYER);

	InitializeShip(player.ships[4], SUBMARINE_SIZE, ST_SUBMARINE);
}


void InitializeShip(Ship& ship, int shipSize, ShipType shipType)
{
	ship.shipType = shipType;
	ship.shipSize = shipSize;
	ship.position.row = 0;
	ship.position.col = 0;
	ship.orientation = SO_HORIZONTAL;
}

void PlayGame(Player& player1, Player& player2)
{

	ClearScreen();
	player1.playerType = PT_HUMAN;
	player2.playerType = GetPlayer2Type();

	SetupBoards(player1);
	SetupBoards(player2);

	Player * currentPlayer = &player1;
	Player * otherPlayer = &player2;

	ShipPositionType guess;

	do
	{
		if(currentPlayer->playerType == PT_HUMAN)
		{
			DrawBoards(*currentPlayer);
		}

		bool isValidGuess;

		do
		{
			if(currentPlayer->playerType == PT_HUMAN)
			{
				cout << currentPlayer->playerName << " what is your guess? " << endl;

				guess = GetBoardPosition();
			}
			else
			{
				guess = GetAIGuess(*currentPlayer);
			}

			isValidGuess = currentPlayer->guessBoard[guess.row][guess.col] == GT_NONE;

			if(!isValidGuess && currentPlayer->playerType == PT_HUMAN)
			{
				cout << "That was not a valid guess! Please try again." << endl;
			}


		}while(!isValidGuess);

		ShipType type = UpdateBoards(guess, *currentPlayer, *otherPlayer);


		if(currentPlayer->playerType == PT_AI)
		{
			DrawBoards(*otherPlayer);
			cout << currentPlayer->playerName << " chose row " << char(guess.row + 'A') << " and column " << guess.col + 1 << endl;
		}
		else
		{
			DrawBoards(*currentPlayer);
		}

		if(type != ST_NONE && IsSunk(*otherPlayer, otherPlayer->ships[type-1]))
		{
			if(currentPlayer->playerType == PT_AI)
			{
				cout << currentPlayer->playerName << " sunk your " << GetShipNameForShipType(type) << "!" << endl;
			}
			else
			{
				cout << "You sunk " << otherPlayer->playerName << "'s " << GetShipNameForShipType(type) << "!" << endl;

			}
		}

		WaitForKeyPress();

		SwitchPlayers(&currentPlayer, &otherPlayer);


	}while(!IsGameOver(player1, player2));

	DisplayWinner(player1, player2);
}

ShipType UpdateBoards(ShipPositionType guess, Player& currentPlayer, Player& otherPlayer)
{
	if(otherPlayer.shipBoard[guess.row][guess.col].shipType != ST_NONE)
	{
		//hit
		currentPlayer.guessBoard[guess.row][guess.col] = GT_HIT;
		otherPlayer.shipBoard[guess.row][guess.col].isHit = true;
	}
	else
	{
		currentPlayer.guessBoard[guess.row][guess.col] = GT_MISSED;
	}

	return otherPlayer.shipBoard[guess.row][guess.col].shipType;
}


void SwitchPlayers(Player ** currentPlayer, Player ** otherPlayer)
{
	Player * temp = *currentPlayer;
	*currentPlayer = *otherPlayer;
	*otherPlayer = temp;
}



void DisplayWinner(const Player& player1, const Player& player2)
{
	if(AreAllShipsSunk(player1))
	{
		cout << "Congratulations " << player2.playerName << "! You won!" << endl;
	}
	else
	{
		cout << "Congratulations " << player1.playerName << "! You won!" << endl;
	}
}

bool IsSunk(const Player& player, const Ship& ship)
{
	if(ship.orientation == SO_HORIZONTAL)
	{
		for(int col = ship.position.col; col < (ship.position.col + ship.shipSize); col++)
		{
			if(!player.shipBoard[ship.position.row][col].isHit)
			{
				return false;
			}
		}
	}
	else
	{
		for(int row = ship.position.row; row < (ship.position.row + ship.shipSize); row++)
		{
			if(!player.shipBoard[row][ship.position.col].isHit)
			{
				return false;
			}
		}
	}

	return true;
}

bool AreAllShipsSunk(const Player& player)
{
	for(int i = 0; i < NUM_SHIPS; i++)
	{
		if(!IsSunk(player, player.ships[i]))
		{
			return false;
		}
	}

	return true;
}


bool IsGameOver(const Player& player1, const Player& player2)
{
	return AreAllShipsSunk(player1) || AreAllShipsSunk(player2);
}


bool WantToPlayAgain()
{
	char input;

	const char validInput[2] = {'y', 'n'};

	input = GetCharacter("Would you like to play again? (y/n): ", INPUT_ERROR_STRING, validInput, 2, CC_LOWER_CASE);

	return input == 'y';
}

const char * GetShipNameForShipType(ShipType shipType)
{
	if(shipType == ST_AIRCRAFT_CARRIER)
	{
		return "Aircraft Carrier";
	}
	else if(shipType == ST_BATTLESHIP)
	{
		return "Battleship";
	}
	else if(shipType == ST_CRUISER)
	{
		return "Cruiser";
	}
	else if(shipType == ST_DESTROYER)
	{
		return "Destroyer";
	}
	else if(shipType == ST_SUBMARINE)
	{
		return "Submarine";
	}

	return "None";
}

void SetupBoards(Player& player)
{
	ClearBoards(player);

	if(player.playerType == PT_AI)
	{
		SetupAIBoards(player);
		return;
	}

	for(int i = 0; i < NUM_SHIPS; i++)
	{

		DrawBoards(player);

		Ship& currentShip = player.ships[i];

		ShipPositionType shipPosition;
		ShipOrientationType orientation;

		bool isValidPlacement = false;

		do
		{
			cout << player.playerName << " please set the position and orientation for your " << GetShipNameForShipType(currentShip.shipType) << endl;

			shipPosition = GetBoardPosition();
			orientation = GetShipOrientation();

			isValidPlacement = IsValidPlacement(player, currentShip, shipPosition, orientation);

			if(!isValidPlacement)
			{
				cout << "That was not a valid placement. Please try again." << endl;
				WaitForKeyPress();
			}

		}while(!isValidPlacement);


		PlaceShipOnBoard(player, currentShip, shipPosition, orientation);

	}

	DrawBoards(player);
	WaitForKeyPress();
}


bool IsValidPlacement(const Player& player, const Ship& currentShip,const ShipPositionType& shipPosition, ShipOrientationType orientation)
{
	if(orientation == SO_HORIZONTAL)
	{
		for(int c = shipPosition.col; c < (shipPosition.col + currentShip.shipSize); c++)
		{
			if(player.shipBoard[shipPosition.row][c].shipType != ST_NONE || c >= BOARD_SIZE)
			{
				return false;
			}
		}
	}
	else
	{
		for(int r = shipPosition.row; r < (shipPosition.row + currentShip.shipSize); r++)
		{
			if(player.shipBoard[r][shipPosition.col].shipType != ST_NONE || r >= BOARD_SIZE)
			{
				return false;
			}
		}
	}
	return true;
}


void PlaceShipOnBoard(Player& player, Ship& currentShip, const ShipPositionType& shipPosition, ShipOrientationType orientation)
{
	currentShip.position = shipPosition;
	currentShip.orientation = orientation;

	if(orientation == SO_HORIZONTAL)
	{
		for(int c = shipPosition.col; c < (shipPosition.col + currentShip.shipSize); c++)
		{
			player.shipBoard[shipPosition.row][c].shipType = currentShip.shipType;
			player.shipBoard[shipPosition.row][c].isHit = false;
		}
	}
	else
	{
		for(int r = shipPosition.row; r < (shipPosition.row + currentShip.shipSize); r++)
		{
			player.shipBoard[r][shipPosition.col].shipType = currentShip.shipType;

			player.shipBoard[r][shipPosition.col].isHit = false;
		}
	}
}

ShipPositionType MapBoardPosition(char rowInput, int colInput)
{
	int realRow = rowInput - 'A';
	int realCol = colInput - 1;

	ShipPositionType boardPosition;

	boardPosition.row = realRow;
	boardPosition.col = realCol;

	return boardPosition;
}

ShipPositionType GetBoardPosition()
{
	char rowInput;
	int colInput;

	const char validRowInputs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	const int validColumnInputs[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	rowInput = GetCharacter("Please input a row (A - J): ", INPUT_ERROR_STRING, validRowInputs, BOARD_SIZE, CC_UPPER_CASE);
	colInput = GetInteger("Please input a column (1 - 10): ", INPUT_ERROR_STRING, validColumnInputs, BOARD_SIZE);

	return MapBoardPosition(rowInput, colInput);
}

ShipOrientationType GetShipOrientation()
{

	const char validInput[2] = {'H', 'V'};

	char input = GetCharacter("Please choose and orientation (H) for Horizontal or (V) for Vertical: ", INPUT_ERROR_STRING, validInput, 2, CC_UPPER_CASE);

	if(input == validInput[0])
	{
		return SO_HORIZONTAL;
	}
	else
	{
		return SO_VERTICAL;
	}
}

void ClearBoards(Player& player)
{
	for(int r = 0; r < BOARD_SIZE; r++)
	{
		for(int c = 0; c < BOARD_SIZE; c++)
		{
			player.guessBoard[r][c] = GT_NONE;
			player.shipBoard[r][c].shipType = ST_NONE;//no ship here
			player.shipBoard[r][c].isHit = false;
		}
	}
}

void DrawSeparatorLine()
{
	cout << " ";

	for(int c = 0; c < BOARD_SIZE; c++)
	{
		cout << "+---";
	}

	cout << "+";
}

void DrawColumnsRow()
{
	cout << "  ";
	for(int c = 0; c < BOARD_SIZE; c++)
	{
		int columnName = c + 1;

		cout << " " << columnName << "  ";
	}
}

char GetShipRepresentationAt(const Player& player, int row, int col)
{
	if(player.shipBoard[row][col].isHit)
	{
		return '*'; //represents hit
	}

	if(player.shipBoard[row][col].shipType == ST_AIRCRAFT_CARRIER)
	{
		return 'A';
	}
	else if(player.shipBoard[row][col].shipType == ST_BATTLESHIP)
	{
		return 'B';
	}
	else if(player.shipBoard[row][col].shipType == ST_CRUISER)
	{
		return 'C';
	}
	else if(player.shipBoard[row][col].shipType == ST_DESTROYER)
	{
		return 'D';
	}
	else if(player.shipBoard[row][col].shipType == ST_SUBMARINE)
	{
		return 'S';
	}
	else
	{
		return ' ';
	}
}

char GetGuessRepresentationAt(const Player& player, int row, int col)
{
	if(player.guessBoard[row][col] == GT_HIT)
	{
		return '*';
	}
	else if(player.guessBoard[row][col] == GT_MISSED)
	{
		return 'o';
	}
	else
	{
		return ' ';
	}
}

void DrawShipBoardRow(const Player& player, int row)
{
	char rowName = row + 'A';
	cout << rowName << "|";

	for(int c = 0; c < BOARD_SIZE; c++)
	{
		cout << " " << GetShipRepresentationAt(player, row, c) << " |";
	}
}

void DrawGuessBoardRow(const Player& player, int row)
{
	char rowName = row + 'A';
		cout << rowName << "|";

		for(int c = 0; c < BOARD_SIZE; c++)
		{
			cout << " " << GetGuessRepresentationAt(player, row, c) << " |";
		}
}

void  DrawBoards(const Player& player)
{
	ClearScreen();

	DrawColumnsRow();

	DrawColumnsRow();

	cout << endl;

	for(int r = 0; r < BOARD_SIZE; r++)
	{
		DrawSeparatorLine();

		cout << " ";

		DrawSeparatorLine();

		cout << endl;

		DrawShipBoardRow(player, r);

		cout << " ";

		DrawGuessBoardRow(player, r);

		cout << endl;
	}

	DrawSeparatorLine();

	cout << " ";

	DrawSeparatorLine();

	cout << endl;
}


PlayerType GetPlayer2Type()
{
	const int validInputs[2] = {1, 2};


	int input = GetInteger("Who would you like to player against?\n1. Human\n2. AI\n\nWhat is your choice? ", INPUT_ERROR_STRING, validInputs, 2);


	if(input == 1)
	{
		return PT_HUMAN;
	}
	else
	{
		return PT_AI;
	}
}

ShipPositionType GetRandomPosition()
{
	ShipPositionType guess;

	guess.row = rand() % BOARD_SIZE;
	guess.col = rand() % BOARD_SIZE;

	return guess;
}

ShipPositionType GetAIGuess(const Player& aiPlayer)
{
	return GetRandomPosition();
}


void SetupAIBoards(Player & player)
{
	ShipPositionType pos;
	ShipOrientationType orientation;

	for(int i =0; i < NUM_SHIPS; i++)
	{
		Ship& currentShip = player.ships[i];

		do
		{
			pos = GetRandomPosition();
			orientation = ShipOrientationType(rand() % 2);



		}while(!IsValidPlacement(player, currentShip, pos, orientation));

		PlaceShipOnBoard(player, currentShip, pos, orientation);
	}
}

