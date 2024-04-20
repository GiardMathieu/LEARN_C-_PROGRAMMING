//============================================================================
// Name        : MultidimensionalArrays.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	//int array2D[10][10];


	/*
	 *   Columns
	 * 	  0   1   2
	 *  +---+---+---+
	 *0 |   |   |   |
	 *  +---+---+---+
	 *1 |   |   |   |
	 *  +---+---+---+
	 *2 |   |   |   |
	 *  +---+---+---+
	 *
	 *
	 *
	 */
	//Top Left
	//array2D[0][0];
	//Top mid
	//array2D[0][1];
	//Bottom mid
	//array2D[2][1];

	/*int array2D[2][3] = {
			{1,2,3},
			{4,5,6}
	};
	*/

	const int MAX = 10;

	// If you know the MAX range
	//int (*pointer)[MAX] = new int[10][10];

	int ** pointer = new int *[MAX];

	for(int r =0; r < MAX; r++) {
		pointer[r] = new int[MAX];
	}

	for (int r = 0; r < MAX; r++) {
		for (int c = 0; c < MAX; c++) {
			pointer[r][c] = r * c;
			cout << "r = " << r << ", c = " << c << ", val = " << pointer[r][c] << endl;
		}
	}

	for (int r = 0; r < MAX; r++) {
		delete[] pointer[r];
	}
	//delete [] pointer;
	delete [] pointer

	return 0;
}
