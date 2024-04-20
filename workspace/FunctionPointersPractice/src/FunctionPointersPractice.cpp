//============================================================================
// Name        : FunctionPointersPractice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

typedef int(*ArithmeticFcn)(int, int);

int Index(int r , int c, int numberOfColumns);

int Sum(int nb1, int nb2);

int Divide(int nb1, int nb2);

int Multiply(int nb1, int nb2);

int Substract(int nb1, int nb2);

int Modulo(int nb1, int nb2);

int Power(int nb1, int nb2);


ArithmeticFcn GetArithmeticFcn(char op);

int main() {

	/*
	 * Problem 1:
	 *
	 * How would you write a 2D array using only a 1D array. What extra functions might accomplish this?
	 *
	 *
	 */
	/*
	const int MAX = 10;
	int array [MAX*MAX];

	for(int r = 0; r < MAX; r++) {
		for(int c = 0; c < MAX; c++){
			array[Index(r,c,MAX)] = Index(r, c, MAX);

			cout << "array[" << Index(r,c, MAX) << "] = " << array[Index(r,c,MAX)] << endl;
		}
	}
	*/

	/*
	 * Problem 2:
	 *
	 * Write a mini calculator program that takes in a character ('+', '-', '*', '/') and 2 integets and outputs the result
	 * Use Function pointers for this
	 */

	int x1 = 0;
	int x2 = 0;

	char operation = ' ';

	cout << "Please input the 2 operands with a space between: ";
	cin >> x1 >> x2;

	cout << "Please input the operation: ('+', '-', '/', '*', '%', '^'): ";
	cin >> operation;

	ArithmeticFcn opFcn = GetArithmeticFcn(operation);

	cout << x1 << " " << operation << " " << x2 << " = " << opFcn(x1, x2) << endl;
	return 0;
}

int Index(int r , int c, int numberOfColumns){
	return c + numberOfColumns * r;
}

int Sum(int nb1, int nb2){
	return nb1 + nb2;
}

int Divide(int nb1, int nb2) {
	return nb1 / nb2;
}

int Multiply(int nb1, int nb2) {
	return nb1 * nb2;
}

int Substract(int nb1, int nb2) {
	return nb1 - nb2;
}

int Modulo (int nb1, int nb2){
	return nb1 % nb2;
}

int Power(int nb1, int nb2){
	return pow(nb1, nb2);
}

ArithmeticFcn GetArithmeticFcn(char op) {
	switch(op) {
		case '+': return Sum;
		case '/': return Divide;
		case '*': return Multiply;
		case '-': return Substract;
		case '%': return Modulo;
		case '^': return Power;
	}
	return Sum;
}

