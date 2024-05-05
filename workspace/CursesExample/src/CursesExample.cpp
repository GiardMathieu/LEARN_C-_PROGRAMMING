//============================================================================
// Name        : CursesExample.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "curses.h"

int main() {
	initscr();
		curs_set(false); //To remove the cursor in the terminal
		noecho(); //Prevents from the characters to show up in the terminal
		nodelay(stdscr, true); //The terminal doesnt wait for a character to be entered (true means no delay) - getch() will not block anymore
		keypad(stdscr, true); //enable the keypad (arrow keys)


		//For input

		bool quit = false;
		int input;

		while(!quit) {
			input = getch(); //Read 1 character from input

			if(input == KEY_DOWN) //KEY_UP, KEY_LEFT, KEY_RIGHT
			{
				quit = true;
			}
			mvprintw(20,20, "Hello everyone");
			refresh();
		}






		endwin();
	return 0;
}
