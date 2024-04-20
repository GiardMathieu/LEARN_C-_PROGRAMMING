//============================================================================
// Name        : Arrays.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {


	/*					0	   1      2      3	    4     . . . n-1
	 * 				+------+------+------+------+------+
	 * array name   |	   |      |      |      |      |
	 *				+------+------+------+------+------+
	 */


	const int MAX = 5;
	int intArray[MAX] = {2, 4 ,6, 8, 10};
	int sum = 0;

	for (int i = 0; i < MAX; i++) {
		sum += intArray[i];
	}
	cout << "The sum of the intArray is: " << sum << endl;



	return 0;
}
