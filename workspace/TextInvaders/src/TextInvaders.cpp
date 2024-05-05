//============================================================================
// Name        : TextInvaders.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "TextInvaders.h"
#include "CursesUtils.h"
using namespace std;

void InitGame(Game & game);
void InitPlayer(const Game & game, Player & player);
void ResetPlayer(const Game & game, Player & player);
void ResetMissile(Player & player);
void UpdateGame(const  Game & game, Player & player);
void DrawGame(const Game & game, const Player & player);
char HandleInput(const Game & game, Player & player);

int main() {

	Game game;
	Player player;

	InitializeCurses(true);

	InitGame(game);
	InitPlayer(game, player);

	bool quit = false;
	char input;

	while(!quit) {
		input = HandleInput(game, player);
		UpdateGame(game, player);
		ClearScreen(); // curses utils
		DrawGame(game, player);
		RefreshScreen(); // curses utils
	}

	ShutdownCurses();


	return 0;
}

void InitGame(Game & game){
	game.windowSize.width = ScreenWidth();
	game.windowSize.height = ScreenHeight();
	game.level = 1;
	game.currentState = GS_PLAY; // For now - TODO: change to GS_INTRO at the end
}
void InitPlayer(const Game & game, Player & player){
	player.lives = MAX_NUMBER_OF_LIVES;
	player.spriteSize.width = PLAYER_SPRITE_WIDTH;
	player.spriteSize.height = PLAYER_SPRITE_HEIGHT;
	ResetPlayer(game, player);
}

void ResetPlayer(const Game & game, Player & player){
	player.position.x = game.windowSize.width / 2 - player.spriteSize.width/2; //Puts the player in the center of the screen horizontally
	player.position.y = game.windowSize.height - player.spriteSize.height - 1;
	player.animation = 0;
}

void ResetMissile(Player & player){
	player.missile.x = NOT_IN_PLAY;
	player.missile.y = NOT_IN_PLAY;
}

void DrawGame(const Game & game, const Player & player) {
	DrawSprite(player.position.x, player.position.y, PLAYER_SPRITE, player.spriteSize.height);
}

void UpdateGame(const Game & game, const Player & player) {

}
char HandleInput(const Game & game, Player & player){
	return ' ';
}
