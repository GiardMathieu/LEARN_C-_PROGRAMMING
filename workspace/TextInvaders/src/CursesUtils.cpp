/*
 * CursesUtils.cpp
 *
 *  Created on: May 2, 2024
 *      Author: Mathy
 */

#include "CursesUtils.h"

void InitializeCurses(bool noDelay){
	initscr();
	noecho();
	curs_set(false);

	nodelay(stdscr, noDelay);
	keypad(stdscr,true);
}

void ShutdownCurses(){
	endwin();
}

void ClearScreen(){
	clear();
}

void RefreshScreen(){
	refresh();
}

void DrawCharacter(int xPos, int yPos, char aCharacter){
	mvaddch(yPos, xPos, aCharacter);
}

void DrawSprite(int xPos, int yPos, const char * sprite[], int spriteHeight, int offset){
	for(int h = 0; h < spriteHeight; h++) {
		mvprintw(yPos + spriteHeight, xPos, "%s", sprite[h]);
	}
}

void MoveCursor(int xPos, int yPos){
	move(xPos, yPos);
}
int ScreenWidth(){
	return COLS;
}
int ScreenHeight(){
	return LINES;
}

int GetChar() {
	return getch();
}


