//============================================================================
// Name        : StatementBlocks.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int x = 0, y = 0;

	cout << "Please enter 2 numbers with a space between: " << endl;
	cin >> x >> y;

	if (x > y) {
		cout << "Case 1: The bigger number is x: " << x << endl;
	} else if (x < y){
		cout << "Case 2: The bigger number is y: " << y << endl;
	} else {
		cout << "Case 3: x and y are equal:  " << x << " == " << y << endl;
	}

	return 0;
}
