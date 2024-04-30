//============================================================================
// Name        : FileIO_Project.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Write a program that can read and write an array of students to and from a file. Each student will be of this structure;

struct Student {
	int studentId;
	char firstName[256];
	char lastName[256];
	int age;
	float gpa;
};

struct StudentsDB {
	Student * optrStudents;
	int numberOfStudents;
	int capacity;
};

const int MAX_NAME_SIZE = 256;
const char  * INPUT_ERROR_STRING = "Input error! Please try again!";
const char * STUDENTS_FILE_NAME  = "StudentsDB.bin";

char GetOptionFromUser();
char GetCharacter(const char *prompt, const char* error, const char validInput[], int validInputLength);
int GetString(const char * prompt, const char * error, char string[], int maxLength);

void DisplayOption(StudentsDB & studentsDB);
void AddOption(StudentsDB & studentsDB);
void ExecuteOption(StudentsDB & studenstDB, char option);
void ResizeStudentsDB(StudentsDB & studentDB, int newCapacity);
void CreateStudentsFile();
void SaveStudents(const StudentsDB & studentsDB);

bool LoadStudents(StudentsDB & studentsDB);




int main() {


	StudentsDB studentsDB;
	studentsDB.optrStudents = nullptr;
	studentsDB.numberOfStudents = 0;
	studentsDB.capacity = 0;

	CreateStudentsFile();

	if(!LoadStudents(studentsDB)) {
		cout << "Error loading file: " << STUDENTS_FILE_NAME << endl;
		return 0;
	}

	char option;

	do {
		option = GetOptionFromUser();
		ExecuteOption(studentsDB, option);
	} while(option != 'q');

	SaveStudents(studentsDB);
	if(studentsDB.optrStudents != nullptr) {
		delete [] studentsDB.optrStudents;
		studentsDB.optrStudents = nullptr;
	}

	return 0;
}


char GetOptionFromUser() {
	const char validOptions[] = {'d', 'a', 'q'};
	return GetCharacter("Please choose an option: \n\n(D)isplay students\n(A)dd student\n(Q)uit\n\n", INPUT_ERROR_STRING, validOptions, 3);

}

void ExecuteOption(StudentsDB & studentsDB, char option) {
	switch(option) {
	case 'd':
		DisplayOption(studentsDB);
		break;
	case 'a':
		AddOption(studentsDB);
		break;
	}
}

void DisplayOption(StudentsDB & studentsDB){
	for(int i = 0; i < studentsDB.numberOfStudents; i++) {
		cout << "Student Id: " << studentsDB.optrStudents[i].studentId << endl;
		cout << "Name: " << studentsDB.optrStudents[i].firstName << " " << studentsDB.optrStudents[i].lastName << endl;
		cout << "Age: " << studentsDB.optrStudents[i].age << endl;
		cout << "GPA: " << studentsDB.optrStudents[i].gpa << endl;
	}
}

void CreateStudentsFile() {
	ifstream inFile;
	inFile.open(STUDENTS_FILE_NAME, fstream::binary);
	if(!inFile.is_open()) {
		ofstream outFile;
		outFile.open(STUDENTS_FILE_NAME, fstream::binary);
		outFile << flush;
		outFile.close();
	} else {
		inFile.close();
	}



}
void AddOption(StudentsDB & studentsDB){
	if (studentsDB.numberOfStudents == studentsDB.capacity) {
		ResizeStudentsDB(studentsDB, studentsDB.capacity * 2 + 10);
	}

	GetString("Please enter the first name: ", INPUT_ERROR_STRING, studentsDB.optrStudents[studentsDB.numberOfStudents].firstName, MAX_NAME_SIZE - 1);
	GetString("Please enter the last name: ", INPUT_ERROR_STRING, studentsDB.optrStudents[studentsDB.numberOfStudents].lastName, MAX_NAME_SIZE - 1 );

	cout << "Please input the student's age and GPA with a space in between, Example: 13 5.4 : ";
	cin >> studentsDB.optrStudents[studentsDB.numberOfStudents].age >> studentsDB.optrStudents[studentsDB.numberOfStudents].gpa;
	studentsDB.numberOfStudents++;
}

void ResizeStudentsDB(StudentsDB & studentsDB, int newCapacity) {
	// Create a new array with the given new capacity
	Student * newOptrStudent = new Student[newCapacity];

	// Copy the elements of the old array to the new
	for (int i = 0; i < studentsDB.numberOfStudents; i++) {
		strcpy(newOptrStudent[i].firstName, studentsDB.optrStudents[i].firstName);
		strcpy(newOptrStudent[i].lastName, studentsDB.optrStudents[i].lastName);
		newOptrStudent[i].age = studentsDB.optrStudents[i].age;
		newOptrStudent[i].gpa = studentsDB.optrStudents[i].gpa;
	}

	// delete the old array
	if (studentsDB.optrStudents != nullptr) {
		delete [] studentsDB.optrStudents;
		studentsDB.optrStudents = nullptr;
	}
	// Give new array to studentsDB
	studentsDB.optrStudents = newOptrStudent;
}

void SaveStudents(const StudentsDB & studentsDB) {
	ofstream outFile;

	outFile.open(STUDENTS_FILE_NAME, fstream::binary);

	if(outFile.is_open()) {
		outFile.write((char*)studentsDB.optrStudents, studentsDB.numberOfStudents* sizeof(Student));
		outFile.close();
	}
}

bool LoadStudents(StudentsDB & studentsDB) {
	ifstream inFile;
	inFile.open(STUDENTS_FILE_NAME, fstream::binary);

	if(inFile.is_open()) {
		if (inFile.is_open()) {
			inFile.seekg(0, inFile.end);
			int lengthFileInBytes = inFile.tellg();
			inFile.seekg(0, inFile.beg);

			int numberOfStudents = lengthFileInBytes / sizeof(Student);
			int capacity = numberOfStudents * 2 + 10;

			studentsDB.optrStudents = new Student[capacity];
			studentsDB.numberOfStudents = numberOfStudents;
			studentsDB.capacity = capacity;

			inFile.read((char*) studentsDB.optrStudents, lengthFileInBytes);
			inFile.close();

			return true;
		}
		return false;
	}
}

int GetString(const char * prompt, const char * error, char string[], int maxLength){
	bool failure;
	int length;
	const int IGNORE_CHARS = 256;

	do {
		failure = false;

		cout << prompt << endl;
		cin >> ws; //special -- meaning clear whitespace
		cin.get(string, maxLength, '\n');

		if(cin.fail()) {
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << error << endl;
			failure = true;
		} else {
			cin.ignore(IGNORE_CHARS, '\n');
			length = strlen(string);

			if(length == 0) {
				cout << "You must enter a word that's longer than 0 characters! Please try again!" << endl;
				failure = true;
			}
		}
	} while(failure);
	return 0;
}

char GetCharacter(const char *prompt, const char* error, const char validInput[], int validInputLength)
{

	const int IGNORE_CHARS = 256;

	char input;
	bool failure;

	do
	{
		failure = false;

		cout << prompt;
		cin >> input;

		if(cin.fail())
		{
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << error << endl;
			failure = true;
		}
		else
		{
			cin.ignore(IGNORE_CHARS, '\n');

			if(isalpha(input))
			{
				input = tolower(input);
				for(int i = 0; i < validInputLength; i++)
				{
					if(input == validInput[i])
					{
						return input;
					}
				}
			}

			cout << error << endl;
			failure = true;

		}

	}while(failure);

	return input;
}
