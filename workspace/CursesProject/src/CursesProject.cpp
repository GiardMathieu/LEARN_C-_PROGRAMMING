//============================================================================
// Name        : CursesProject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "curses.h"

using namespace std;

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
	//For output

//		 (y,  x)
	//int windowMaxX = 0;
	//int windowMaxY = 0;

	//getmaxyx(stdscr, windowMaxY, windowMaxX);
	//move(15, 10); //Changes cursor position
	//string helloString = "Hello world!";
	//LINES is the number of rows of our window
	//mvaddch(15,10,'*');

	//mvprintw(windowMaxY/2, windowMaxX/2 - helloString.length()/2,helloString.c_str());
