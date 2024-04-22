#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

enum PlayerType {
	PT_DEALER = 0,
	PT_PLAYER
};

enum CardType {
	C_FACE = 0,
	C_NUMBER,
	C_NULL
};

enum {
	FACE_VALUE = 10,
	POINTS_CAP = 21,
	DEALER_SOFT_CAP = 17,
	CARD_COPIES = 4,
};

struct Card {
	CardType cardType;
	int cardValue;
};

struct Player {
	PlayerType playerType;
	char playerName[8];
	int numberOfCards =0;
	Card playerHand[11];


};


/*
 * Blackjack is a comparing card game between a player and dealer, meaning players compete against the dealer but not against other players. It is played with one deck of 52 cards. The objective of the game is to beat the dealer in one of the following ways:

Get 21 points on the player's first two cards (called a "blackjack), without a dealer blackjack;
Reach a final score higher than the dealer without exceeding 21; or
Let the dealer draw additional cards until his or her hand exceeds 21.
The player is dealt a two-card hand and add together the value of their cards. Face cards (kings, queens, and jacks) are counted as ten points. A player and the dealer can count an ace as 1 point or 11 points. All other cards are counted as the numeric value shown on the card. After receiving their first two cards, players have the option of getting a "hit", or taking an additional card. In a given round, the player or the dealer wins by having a score of 21 or by having the higher score that is less than 21. Scoring higher than 21 (called "busting" or "going bust") results in a loss. The player may win by having any final score equal to or less than 21 if the dealer busts. If a player holds an ace valued as 11, the hand is called "soft", meaning that the player cannot go bust by taking an additional card; 11 plus the value of any other card will always be less than or equal to 21. Otherwise, the hand is "hard".

The dealer must hit until the cards total 17 or more points. Players win by not busting and having a total higher than the dealer's. The dealer loses by busting or having a lesser hand than the player who has not busted. If the player and dealer have the same total, this is called a "push", and the player typically does not win or lose money on that hand. If all available players bust, the hand ends automatically without the dealer having to play his or her hand.

The player should be prompted if they want to play again when the game is over.
 */

/*
 * The dealer has a pack of 52 playing cards
 * The dealer gives players 2 cards at the beginning.
 * The dealer gives 2 cards to her/himself, if the sum of the value of the 2 cards is less than 17, he has draw another card
 * The player has the choice to either hit or stand after receiving both of his cards
 *
 *
 */

void InitializePlayer(Player& player, const char * playerName);
void PlayGame(Player & player, Player & dealer);
void Hit(Player & player);
void DrawCards(Player & player);
void DisplayResults(Player & player, Player & dealer);

char GetCharacter(const char *prompt, const char* error, const char validInput[], int validInputLength);

int GetSum(Player & player);

bool IsBusted(Player & player);
bool PossibleDraw(Player & player, Player & dealer, int cardValue);
bool WantsToHit(Player & player);
bool DealerUnderSoftCap(Player & dealer);
bool IsGameOver(Player & player, Player & dealer);

int GetRandomNumber();

Card GetCard(Player & player, Player & dealer);




int main(){

	srand((unsigned) time(NULL));

	Player player;
	Player dealer;

	InitializePlayer(player, "Player");
	InitializePlayer(dealer, "Dealer");


	PlayGame(player, dealer);

	DisplayResults(player, dealer);
	cout << "GAME END" << endl;


	return 0;
}

void Hit(Player & player, Player & dealer) {
	player.playerHand[player.numberOfCards-1] = GetCard(player, dealer);
}

void DisplayResults(Player & player, Player & dealer) {
	if (GetSum(player) > GetSum(dealer)) {
		cout << "The player has won with " << GetSum(player) << " points!" << endl;
	} else {
		cout << "The dealer has won with " << GetSum(dealer) << " points!" << endl;
	}
}

void DrawCards(Player & player) {
	cout << "------------- Deck of " << player.playerName << " ------------- " << endl;

	for (int i = 0; i < player.numberOfCards; i++) {
		cout << "numberOfCards[" << i << "] = " << i << endl;
		cout << "------    " << endl;
		cout << "|    |    " << endl;
		cout << "| "<< player.playerHand[i].cardValue << "  |    " << endl;
		cout << "|    |    " << endl;
		cout << "|____|    " << endl;;
	}
	cout << "Total cards value: " << GetSum(player) << endl;
}

Card GetCard(Player & currentPlayer, Player & otherPlayer) {
	Card newCard;

	int cardValue;


	do {
		cardValue = GetRandomNumber();
	} while (!(PossibleDraw(currentPlayer, otherPlayer, cardValue)));
	currentPlayer.numberOfCards ++;
	newCard.cardValue = cardValue;
	if (newCard.cardValue < 11) {
		newCard.cardType = C_NUMBER;
	} else if(newCard.cardValue > 11 && newCard.cardValue < 14){
		newCard.cardType = C_FACE;
		newCard.cardValue = FACE_VALUE;
	} else {
		newCard.cardType = C_NULL;
		newCard.cardValue = 0;
	}


	return newCard;
}

void InitializePlayer(Player& player, const char * playerName){
	if (playerName != nullptr && strlen(playerName) > 0) {
		strcpy(player.playerName, playerName);
		if(strcmp(player.playerName, "Dealer")) {
			player.playerType = PT_DEALER;
		} else {
			player.playerType = PT_PLAYER;
		}
	}
}

void PlayGame(Player & player, Player & dealer) {
	// The player receives the first two cards of the game
	player.playerHand[0] = GetCard(player, dealer);
	player.playerHand[1] = GetCard(player, dealer);
	DrawCards(player);

	// The dealer receives the first two cards of the game
	dealer.playerHand[0] = GetCard(dealer, player);
	dealer.playerHand[1] = GetCard(dealer, player);
	DrawCards(dealer);
	while(DealerUnderSoftCap(dealer)) {
		dealer.playerHand[dealer.numberOfCards-1] = GetCard(dealer, player);
		cout << "Dealer's number of Cards: " << dealer.numberOfCards << endl;

	}
	DrawCards(dealer);

	if (WantsToHit(player)) {
		do {
			Hit(player, dealer);
			DrawCards(player);
		} while(WantsToHit(player) && !IsGameOver(player, dealer));
	}
}

int GetSum(Player & player) {
	int cardValueSum = 0;

	for (int i = 0; i < player.numberOfCards; i++) {
		cardValueSum += player.playerHand[i].cardValue;
	}
	return cardValueSum;
}

bool IsBusted(Player & player){
	int cardSum = GetSum(player);
	if (cardSum > POINTS_CAP) {
		return true;
	};
	return false;
}

bool PossibleDraw(Player & player, Player & dealer, int cardValue) {
	int copies = 0;
	for(int i = 0; i < player.numberOfCards; i++) {
		if (player.playerHand[i].cardValue == cardValue) {
			copies++;
		}
	}
	for (int j = 0; j < dealer.numberOfCards; j++) {
		if(dealer.playerHand[j].cardValue == cardValue){
			copies++;
		}
	}
	return copies <= 4;

}

bool WantsToHit(Player & player) {
	char validInput[] = {'y', 'n'};
	char input = GetCharacter("Do you want to hit to receive new cards? : ", "Input error!", validInput, 2);

	return input == 'y';
}

bool DealerUnderSoftCap(Player & dealer) {
	return GetSum(dealer) < DEALER_SOFT_CAP;
}

bool IsGameOver(Player & player, Player & dealer) {
	if (IsBusted(player) || IsBusted(dealer)) {
		return true;
	}
	return false;
}

char GetCharacter(const char *prompt, const char* error, const char validInput[], int validInputLength)
{

	const int IGNORE_CHARS = 256;

	char input;
	bool failure;

	do
	{
		failure = false;

		cout << prompt;
		cin >> input;

		if(cin.fail())
		{
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << error << endl;
			failure = true;
		}
		else
		{
			cin.ignore(IGNORE_CHARS, '\n');

			if(isalpha(input))
			{
				input = tolower(input);
				for(int i = 0; i < validInputLength; i++)
				{
					if(input == validInput[i])
					{
						return input;
					}
				}
			}

			cout << error << endl;
			failure = true;

		}

	}while(failure);

	return input;
}

int GetRandomNumber() {
	return (rand() % 13) + 1;
}
