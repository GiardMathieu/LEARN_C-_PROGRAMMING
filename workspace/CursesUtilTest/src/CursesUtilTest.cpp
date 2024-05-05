//============================================================================
// Name        : CursesUtilTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "CursesUtils.h"
#include <string>
#include "curses.h"

int main() {
	InitializeCurses(false);
	string aString = "Hello Everyone!";
	mvprintw(10,10, aString.c_str());
	GetChar();
	ShutdownCurses();
	return 0;
}
