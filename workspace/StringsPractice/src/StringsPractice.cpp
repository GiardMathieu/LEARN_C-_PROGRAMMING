//============================================================================
// Name        : StringsPractice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

/*
 * Problem: Pig Latin takes the first consonant (or consonant cluster) of an English word,
 *  moves it to the end of the word and suffixes an ay, or if a word begins with a vowel you just add way to the end.
 *  For example, pig becomes igpay, banana becomes ananabay, and aadvark becomes aadvarkway.
 *   Write a function that uses strings called PigLatinify that takes in a c++ string and returns the Pig Latin version.
 */

int GetConsonantIdx(string word, vector<string> vowels);
bool StartsWithVowel(string word, vector<string> vowels);
void SwapConsonantToEnd(string word);

const string VOWEL_WORD_ENDER = "way";
const string CONSONANT_WORD_ENDER = "ay";





int main() {
	vector<string> vowels;
	vowels.push_back("a");
	vowels.push_back("e");
	vowels.push_back("i");
	vowels.push_back("o");
	vowels.push_back("u");
	vowels.push_back("y");



	return 0;
}

int GetConsonantIdx(string word, vector<string> vowels) {
	for(int i = 0; i < word.size(); i++) {
		for (int j = 0; j < vowels.size(); j++) {
			if (!word[i] == vowels[i]) {
				return j;
			}
		}
	}
	return 0;
}

bool StartsWithVowel(string word, vector<string> vowels) {
	bool startsWithVowel = false;
	for (int i = 0; i < vowels.size(); i++) {
		if(word[0] == vowels[i]) {
			return true;
		}
	}
}

void SwapConsonantToEnd(string word) {
}
