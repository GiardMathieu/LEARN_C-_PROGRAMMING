//============================================================================
// Name        : Loops.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	/* While loop
	int i = 1, sum = 0;
	const int MAX = 100;

	while (i <= MAX) {
		if (i % 2 == 0) {
			sum += i;
		}
		i++;
	}
	cout << "The sum of all even numbers before a hundred is " << sum << endl;
	*/

	//For loop
	/*
	const int MAX = 10;
	for (int i = 1; i <= MAX; i ++) {
		cout << "The current iterator is " << i << endl;
	}
	*/

	//break
	/*
	const int MAX = 10;

	for (int i =1 ; i <= MAX; i++){
		if (i == MAX/2) {
			cout << "Breaking at " << i << endl;
			break;
		}
		cout << "The current iterator is " << i << endl;
	}

	cout << "Outside of the for loop! " << endl;
	*/

	//continue (Basically skips the rest of the function when the condition is true !
	/*
	const int MAX = 100;
	for (int i = 1; i <= MAX; i++) {
		if (i % 2 == 0) {
			continue;
		}
		cout << "The current iteration is " << i << endl;
	}
	*/

	//Nested loops
	/*
	 const int MAX = 5;

	 for (int i = 1; i <= MAX; i++) {
		 cout << "Iteration i = " << i << endl;

		 for (int j = 1; j <= MAX; j++) {
			 cout << "iteration j = " << j << endl;
		 }
	 }
	 */

	return 0;
}
