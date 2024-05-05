//============================================================================
// Name        : CursesExamples.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "curses.h"
#include <ctime>

int main() {
	initscr();
	noecho();
	curs_set(false);
	nodelay(stdscr, true);
	keypad(stdscr, true);

	bool quit = false;

	int input;

	clock_t currentTime = clock(); //Give us the current time in clock ticks
	const int FPS = 60;
	int currentXPos = 0;
	int currentYPos = 0;

	while(!quit) {

		clock_t newTime = clock();
		clock_t dt = newTime-currentTime;
		if(dt > CLOCKS_PER_SEC / FPS){ // t / s f / s -> t/f
			currentTime = newTime;

			input = getch();
			if(input != 'q') {
				clear();
				if(input == KEY_DOWN) {
					currentYPos++;
				} else if(input == KEY_UP) {
					currentYPos--;
				} else if(input == KEY_LEFT) {
					currentXPos--;
				} else if(input == KEY_RIGHT) {
					currentXPos++;
				}
				mvprintw(currentYPos, currentXPos, "o");
				refresh();
			} else {
				quit = true;
			}
		}
	}



	endwin();

	return 0;
}
