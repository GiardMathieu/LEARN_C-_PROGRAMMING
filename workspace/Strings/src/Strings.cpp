//============================================================================
// Name        : Strings.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

void Func(const string & aString); //passing it by value - copy;

int main() {
	string myString = "Hello ";
	string myString2;

	cout << myString << endl;
	cout << "Please enter a string: ";
	cin >> myString2;
	cout << myString2 << endl;

	string myString3 = myString + myString2;
	myString3 += "!";
	cout << "Result is " << myString3 << endl;

	myString[0] = 'h';
	cout << "myString: " << myString;

	cout << "The length of myString3 is: " << myString3.length() << endl;

	cout << "The cstring representation is: " << myString3.c_str() << endl;

	return 0;
}
