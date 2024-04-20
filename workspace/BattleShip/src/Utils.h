/*
 * Utils.h
 *
 *  Created on: Apr. 12, 2024
 *      Author: Mathy
 */

#ifndef UTILS_H_
#define UTILS_H_

enum CharacterCaseType {
	CC_LOWER_CASE = 0,
	CC_UPPER_CASE,
	CC_EITHER
};

char GetCharacter(const char * prompt, const char * error);

char GetCharacter(const char * prompt, const char * error, const char validInputs[], int  validInputLength, CharacterCaseType charCase);

int GetInteger(const char * prompt, const char* error, const int validInput[], int validInputLength){

#endif /* UTILS_H_ */
