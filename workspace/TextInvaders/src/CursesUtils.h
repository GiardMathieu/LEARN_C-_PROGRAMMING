/*
 * CursesUtils.h
 *
 *  Created on: May 2, 2024
 *      Author: Mathy
 */


#ifndef CURSESUTILS_H_
#define CURSESUTILS_H_

#include "CursesUtils.h"
#include "curses.h"

enum ArrowKeys {
	AK_UP = KEY_UP,
	AK_DOWN = KEY_DOWN,
	AK_LEFT = KEY_LEFT,
	AK_RIGHT = KEY_RIGHT
};

void InitializeCurses(bool nodelay);
void ShutdownCurses();
void ClearScreen();
void RefreshScreen();
void DrawCharacter(int xPos, int yPos, char aCharacter);
void MoveCursor(int xPos, int yPos);
void DrawSprite(int xPos, int yPos, const char * sprite[], int spriteHeight, int offset);
int ScreenWidth();
int ScreenHeight();
int GetChar();





#endif /* CURSESUTILS_H_ */
