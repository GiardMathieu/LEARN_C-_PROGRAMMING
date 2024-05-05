//============================================================================
// Name        : CursesAttributes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "curses.h"
#include <string>

int main() {
	initscr();
	noecho();
	curs_set(false);

	string aString = "Hello everyone!";
	/*
	 * A_NORMAL				Normal Display (no highlights);
	 * A_STANDOUT			Best highlighting mode of the terminal
	 * A_UNDERLINE			Underlining
	 * A_REVERSE			Reverse video
	 * A_BLINK				Blinking
	 * A_DIM				Half Bright
	 * A_BOLD				Extra bright or bold
	 * A_PROTECT			Protected mode
	 * A_INVIS				Invisible or blank mode
	 * A_ALTCHARSET			Alternate character set
	 * A_CHARTEXT			Bit-mask to extract a character
	 *
	 *
	 */

	if(!has_colors()) {
		endwin();
		cout << "Your console doesn't support colors ! Too bad....";
		return 0;
	}
	start_color();

	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(A_STANDOUT);
	attron(A_BOLD);
	attron(COLOR_PAIR(1));



	mvprintw(LINES/2, COLS/2 - aString.length()/2, aString.c_str());



	getch();
	endwin();



	endwin();
	return 0;
}
