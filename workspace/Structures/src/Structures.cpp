//============================================================================
// Name        : Structures.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>

using namespace std;


struct BookType {
	int bookId;
	char title[256];
	char author[256];
	int year;
	float price;
};

//void Func(const BookType book);

int main() {

	BookType aBook;

	BookType * bookPtr = &aBook;

	BookType * optrBook = new BookType;

	// Cumbersome D:
	//(*bookPtr).year = 1999;
	//Same thing
	bookPtr->year = 1999;

	delete optrBook;

	return 0;
}

/*void Func(const BookType book) {
	cout << "The size of an integer is " << sizeof(int) << endl;
	cout << "The size of BookType: " << sizeof(BookType) << endl;
}
*/
