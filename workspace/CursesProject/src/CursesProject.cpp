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
	curs_set(false);
//		 (y,  x)
	int windowMaxX = 0;
	int windowMaxY = 0;

	getmaxyx(stdscr, windowMaxY, windowMaxX);
	//move(15, 10); //Changes cursor position
	string helloString = "Hello world!";
	//LINES is the number of rows of our window

	//mvprintw(windowMaxY/2, windowMaxX/2 - helloString.length()/2,helloString.c_str());

	mvaddch(15,10,'*');

	refresh();

	getch(); //pause


	endwin();



	return 0;
}
