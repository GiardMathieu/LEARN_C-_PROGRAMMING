/*
 * Utils.h
 *
 *  Created on: Apr. 9, 2024
 *      Author: Mathy
 */

#ifndef UTILS_H_
#define UTILS_H_

enum CharacterCaseType{
	CC_UPPER_CASE = 0,
	CC_LOWER_CASE,
	CC_EITHER,
};

char GetCharacter(const char * prompt, const char * error, const char validInput[], int validInputLength, CharacterCaseType charCase);


#endif /* UTILS_H_ */
