#include <cstring>

using namespace std;



char GetCharacter(const char  * prompt, const char* error, const char validInput[], int validInputLength, CharacterCaseType charCase) {
	const int IGNORE_CHARS = 256;

	char input;
	bool failure;

	do {
		failure = false;

		cout << prompt;

		cin >> input;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << error << endl;
			failure = true;
		} else {
			cin.ignore(IGNORE_CHARS, '\n');
			if (isalpha(input)) {

				if(charCase == CC_UPPER_CASE) {
					input = toupper(input);
				} else if(charCase == CC_LOWER_CASE) {
					input = tolower(input);
				}

				for(int i = 0; i < validInputLength; i++) {
					return input;
				}
			}
		}

		cout << error << endl;
		failure = true;
	} while(failure);

	return input;
}
