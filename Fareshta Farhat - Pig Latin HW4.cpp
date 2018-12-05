#include <iostream>
#include <regex>
#include <cstring>
using namespace std;

void trasnlateToPigLatin(char *user_Input);
bool check(char *phrase);
void break_Sentence(char *phrase);
void sentence_Obtained(char *phrase);
void break_Sentence(char *phrase);
void sentence_Obtained(char *phrase);
void trasnlateToPigLatin(char *user_Input);
bool check(char *user_Input);

int main() {
	char phrase[500];
	while (true) {
		sentence_Obtained(phrase);

		if (phrase == NULL) {
			cout << "\n\nNot valid, error" << endl;
			return -1;
		}

		if (phrase[0] == '0')
			break;
		break_Sentence(phrase);
	}
	cout << "\n Status: exit program" << endl;
	return 0;
}

bool check(char *user_Input) {
	regex reg_Word("^[a-zA-Z]{2}\\w+[,.!?;:]?$");
	regex blackList("the|and|but|for|nor|yet|\\w+[-']{1}\\w+");
	bool match = !(regex_match(user_Input, blackList)) && (regex_match(user_Input, reg_Word)) ? true : false;
	return match;
}


void trasnlateToPigLatin(char *user_Input) {

	regex aeiou("[aeiouAEIOU]+\\w+[!.,:;?]?");
	int length = strlen(user_Input);

	if (regex_match(user_Input, aeiou)) {
		if (user_Input[length - 1] == ',' ||
			user_Input[length - 1] == '.' ||
			user_Input[length - 1] == '?' ||
			user_Input[length - 1] == '!' ||
			user_Input[length - 1] == ';' ||
			user_Input[length - 1] == ':') {
			for (int i = 0; i < length - 1; i++)
				cout << user_Input[i];
			cout << "ay" << user_Input[length - 1] << " ";
		}
		else {
			for (int i = 0; i < length; i++)
				cout << user_Input[i];
			cout << "ay ";
		}
	}

	else {
		if (user_Input[length - 1] == ',' || user_Input[length - 1] == '.' ||
			user_Input[length - 1] == '?' || user_Input[length - 1] == '!' ||
			user_Input[length - 1] == ';' || user_Input[length - 1] == ':') {
			for (int i = 1; i < length - 1; i++)
				cout << user_Input[i];
			cout << user_Input[0] << "ay" << user_Input[length - 1] << " ";
		}
		else {
			for (int i = 1; i < length; i++)
				cout << user_Input[i];
			cout << user_Input[0] << "ay ";
		}
	}
}

void break_Sentence(char *phrase) {
	char *user_Input;

	user_Input = strtok(phrase, " \n\r\0\t");

	cout << "\nTranslated into Pig Latin:\n " << endl;
	while (user_Input != NULL) {
		if (check(user_Input)) {
			trasnlateToPigLatin(user_Input);
		}
		else {
			cout << user_Input << " ";
		}
		user_Input = strtok(NULL, " \n\r\0\t");
	}
}

void sentence_Obtained(char *phrase) {
	char input[500];
	cout << "\n\nEnter phrase to translate\n" << endl;
	cout << "character limit of 500,to end program, enter 0" << "\n\nOriginal:\n" << endl;
	fgets(input, 500, stdin);
	strcpy(phrase, input);
	return;
}