/*
 * TextInvaders.h
 *
 *  Created on: May 2, 2024
 *      Author: Mathy
 */

#ifndef TEXTINVADERS_H_
#define TEXTINVADERS_H_

#include <string>
#include <vector>
/*
 *
 * Sprites:
 *
 * Alien sprites:
 * 30 point Aliens: /oo\	/oo\
 * 					<  >	/""\
 *
 * 20 point aliens:  ><		|><|
 * 					|\/|  	/  \
 *
 * 10 point aliens: /--\   /--\
 * 				    /  \   <  >
 *
 * Alien explosion: \|/
 * 					/|\
 *
 *
 * Alien bombs:  \ | /
 *
 * Alien UFO: _/oo\_
 * 			  =q==p=
 *
 * Player sprite: =A=
 * 				 =====
 *
 *
 *
 * Player Explosion: '^,' '+-`.
 * 					===== =====
 *
 * Shield: /IIIII\
 * 		   IIIIIII
 * 		   I/	\I
 * Player
 * Aliens
 * Shields
 * Alien bombs
 * Player missiles
 * Game states (Game screen, Highscore screen, Game Over screen)
 * Scores
 * High Score table
 *
 *
 * Player
 * ----------
 * Position
 * Missile
 * Animation State (Alive / Dead)
 * Size of the sprite
 * Lives (3)
 * Score
 *
 * Shields
 * ----------
 * Sprite - the sprite can change
 * Position
 *
 * Alien Swarm (All the 10, 20 and 30 point aliens
 * -----------
 * Position
 * Direction (left or right)
 * Animation state(Moving, standing, Hit)
 * State - Alive, dead, exploding
 * Alien bombs
 *
 *
 * Alien UFO
 * ----------
 * Size
 * Position
 * Points
 *
 * Position
 * ----------
 * x, y coordinate
 *
 * Alien Bomb
 * ----------
 * Position
 * animation state - \ | / -
 *
 * Missile(sprite: |)
 * -----------
 * Position
 *
 *
 * Game
 * ------------
 * Game State
 * Level
 * Size of the window
 *
 * Score
 * -------------
 * Score value
 * name
 *
 * High Score table
 * ---------------
 * Vector of scores
 */

const char * ALIEN10_SPRITE[] = {"/--\\", "/  \\","/--\\", "<  >"};
const char * ALIEN20_SPRITE[] = {" >< ", "|\\/|", "|><|", "/   \\"};
const char * ALIEN30_SPRITE[] = {"/oo\\", "<  >", "/oo\\", "/\"\"\\"};
const char * ALIEN_EXPLOSION[] = {"\\||//", "/||\\"};


const char * SHIELD_SPRITE[] = {"/IIIII\\", "IIIIIII", "I/   \\I"};
const char * PLAYER_SPRITE[] = {" =A= ", "====="};
const char PLAYER_MISSILE_SPRITE = '|';

enum {
	SHIELD_SPRITE_HEIGHT = 3,
	SHIELD_SPRITE_WIDTH = 7,
	NUM_ALIEN_ROWS = 5,
	NUM_ALIEN_COLS = 11,
	NUM_MAX_ALIEN_BOMBS = 3,
	MAX_NUMBER_OF_LIVES = 3,
	PLAYER_SPRITE_WIDTH = 5,
	PLAYER_SPRITE_HEIGHT = 2,
	NOT_IN_PLAY = -1,
	PLAYER_MOVEMENT_AMOUNT = 2,
	PLAYER_MISSILE_SPEED = 1,
	FPS = 20,
	NUM_SHIELDS = 4,
	ALIEN_SPRITE_WIDTH = 4,
	ALIEN_SPRITE_HEIGHT = 2,
	ALIENS_X_PADDING = 1,
	ALIENS_Y_PADDING = 1,
	ALIEN_EXPLOSION_TIME = 4,
};

enum AlienState {
	AS_ALIVE = 0,
	AS_DEAD,
	AS_EXPLODING
};

enum GameState{
	GS_INTRO = 0,
	GS_HIGH_SCORES,
	GS_PLAY,
	GS_PLAYER_DEAD,
	GS_WAIT,
	GS_GAME_OVER,
};
struct Position{
	int x;
	int y;
};

struct Size{
	int width;
	int height;
};

struct Player{
	Position position;
	Position missile;
	Size spriteSize;
	int animation;
	int lives; // max 3 lives
	int score;
};

struct Shield {
	Position position;
	char * sprite[SHIELD_SPRITE_HEIGHT];
};

struct AlienBomb{
	Position position;
	int animation;

};

struct AlienSwarm{
	Position position;
	AlienState alienStates[NUM_ALIEN_ROWS][NUM_ALIEN_COLS];
	AlienBomb bombs[NUM_MAX_ALIEN_BOMBS];
	Size spriteSize;
	int animation;
	int direction; // > 0 - for going right and < 0 for going left (1 or -1);
	int numberOfBombsInPlay;
	int movementTime; // this is going to capture how fast the aliens should be going
	int explosionTimer; // this is going to capture how long for the bombs to explode
	int numAliensLeft; //this is to capture when to go to the next level
	int line; //this to capture when the aliens win - starts at the current level and decreases to 0 - once it's 0 then the aliens win
};

struct AlienUFO {
	Position position;
	Size size;
	int points; //From 50 to 200

};

struct Score {
	int scoreValue;
	std::string name; //std:: because we're not saying using namespace std in this file;
};

struct HighScoreTable{
	std::vector<Score> scores;
};

struct Game {
	Size windowSize;
	GameState currentState;
	int level;
};

#endif /* TEXTINVADERS_H_ */
