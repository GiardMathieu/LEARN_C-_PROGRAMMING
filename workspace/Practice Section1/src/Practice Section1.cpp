//============================================================================
// Name        : Practice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	//Problem 1 Write an algorithm that takes the temperature in fareinheit and outputs it in celsius
	/*
	float temperature, temperatureFareinheit;

	cout << "Please enter a temperature in celsius: " << endl;
	cin >> temperature;
	temperatureFareinheit = (temperature * 9/5) + 32;

	cout << "You entered " << temperature << " and its fareinheit value is " << temperatureFareinheit << endl;
	*/

	//Problem 2: Write a program taht takes three numbers and prints the average
	/*
	int nb1, nb2, nb3, avg;
	cout << "Please enter three numbers with a space between" << endl;
	cin >> nb1 >> nb2 >> nb3;
	avg = (nb1 + nb2 + nb3) / 3;
	cout << "The average of the numbers you inserted is " << avg << endl;
	*/

	//Problem 3: Write a program that takes in a character and outputs its ASCII value
	/*
	char character;
	cout << "Veuillez entrer un caractère: " << endl;
	cin >> character;
	cout << "Le caractère que vous avez entrer est " << int(character);
	return 0;

	*/
	//Problem 4 Write a program to input a number of days from user and convert it to years, weeks and days.
	/*
	int days, years = 0, months = 0, weeks = 0;
	const int DAYS_PER_YEAR = 365, DAYS_PER_MONTH = 30, DAYS_PER_WEEK = 7;
	cout << "Veuillez écrire le nombre de jours : " << endl;
	cin >> days;

	while(days >= DAYS_PER_YEAR){
		years++;
		days -= DAYS_PER_YEAR;
	}
	while(days >= DAYS_PER_MONTH) {
		months++;
		days -= DAYS_PER_MONTH;
	}
	while(days >= DAYS_PER_WEEK) {
		weeks++;
		days -= DAYS_PER_WEEK;
	}
	cout << "Le nombre d'années est de " << (int)years << " et le nombre de mois est de " << (int)months << " le nombre de semaines " << (int)weeks << " et " << (int)days << endl;
	*/
	/*
	int nb1 = 0;
	cout << "Entrer la valeur de nb1 : " << endl;
	cin >> nb1;
	if (nb1 % 2 == 0)
		cout << "Le nombre que vous avez entrer est pair: " << nb1 << endl;
	*/


	//Problem 5 Write a program that takes a foalting point number and outputs the minimum amount of currency denominations neede to make up that number.
	/*
	float money;
	int tenBills = 0, fiveBills = 0, twoBills = 0, oneBills = 0,twentyFiveCent = 0, tenCent = 0, fiveCent = 0, oneCent = 0;
	cout << "How much money do you have ?" << endl;
	cin >> money;
	while (money >= 10) {
		money -= 10;
		tenBills++;
	}
	while(money >=5) {
		money -=5;
		fiveBills++;
	}
	while(money >= 1) {
		money-= 1;
		oneBills++;

	}
	while(money >= 0.25) {
		money-=0.25;
		twentyFiveCent++;
	}
	while(money >= 0.10) {
		money-=0.10;
		tenCent++;
	}
	while(money >= 0.05) {
		money -= 0.05;
		fiveCent++;
	}
	while(money >= 0.01) {
		money -= 0.01;
		++oneCent;
	}
	cout << "You have " << tenBills << " ten dollar bills" << endl;
	cout << "You have " << fiveBills << " five dollar bills" << endl;
	cout << "You have " << twoBills << " two dollar bills" << endl;
	cout << "You have " << oneBills << " one dollar bills" << endl;
	cout << "You have " << twentyFiveCent << " twenty five cents" << endl;
	cout << "You have " << tenCent << " ten cents" << endl;
	cout << "You have " << oneCent << " one cent" << endl;
	*/

	//Problem 6 Write a program that takes in a number of seconds and outputs the time in this format: hh:mm:ss where hh is the hours, mm minutes and ss seconds
	const int ssPerH = 3600, ssPerM = 60;
	int ss = 0, nbH = 0, nbM = 0, nbS = 0;


	cout << "Écriver le nombre de secondes " << endl;
	cin >> ss;

	while(ss >= ssPerH) {
		ss -= ssPerH;
		nbH++;
	}
	while(ss >= ssPerM){
		ss -= ssPerM;
		nbM++;
	}
	nbS = ss;



	cout << nbH << "::" << nbM << "::" << nbS << endl;



}
