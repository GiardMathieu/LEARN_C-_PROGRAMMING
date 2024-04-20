//============================================================================
// Name        : FileIo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	/*
	ofstream outFile;

	outFile.open("Test.txt");

	outFile << "Hello File IO " << endl;

	outFile.close();
	*/

	ifstream inFile;

	inFile.open("Test.txt");

	if(inFile.is_open()) {
		inFile.seekg(0, inFile.end); //Move the cursor to the end of the file
		int length = inFile.tellg(); // Give the position of the current character
		inFile.seekg(0,inFile.beg); //Move the cursor to the beginning of the file

		char * optrBuffer = new char[length + 1];

		inFile.get(optrBuffer,length);

		cout << optrBuffer << endl;

		delete [] optrBuffer;

		inFile.close();
	}

	return 0;
}
