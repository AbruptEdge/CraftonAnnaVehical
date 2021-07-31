//Anna Crafton
//CIS 1202 101
//July 30 2021

//CraftonAnna15

#include <iostream>
#include <locale>

using namespace std;
using namespace std;


struct invalidCharaterException : public exception {
		const char* what()
		const throw () {
		return 0; // "Bad Char Exception!";
	}
};

struct invalidRangeException : public exception {
		const char* what()
		const throw () {
		return 0;
		//"Bad Range Exception!";
	}
};

//functions
char character(char, int);

int main() {
	char letter;
	int num;
	char newLetter;

	cout << "\nLetter: ";
	cin >> letter;
	cout << "\nNumber: ";
	cin >> num;

	newLetter = character(letter, num);

	cout << "The new Letter is " << newLetter;
	cout << endl;
}

//Throws and exception if start is not a letter or 
//if offset is not a number it can be offset by without looping the alphabet. 
char character(char start, int offset) {

	bool startIsUpper;
	int startNum;
	int low;
	int high;
	int newLetter;
	char newChar;
	try {

		if (isalpha(start)) {
			//deterines if upper or lower and does math acordingly.
			if (isupper(start)) {
				startNum = (int(start) - 64);
			}
			else {
				startNum = (int(start) - 96);
			}
			//determines acceptable range for offset
			if (offset > 0) {
				low = (startNum * -1);
				high = (26 - startNum);
			}
			else {
				low = (-1 * startNum);
				high = (26 - startNum);
			}


			if ((offset > low) and (offset < high)) {
				newChar = char((start + offset));

				cout << "\n" << newChar;
				return newChar;
			}
			else {
				//throw exception bc not a number.
				throw invalidRangeException(); 
			}

		}
		else {
			throw invalidCharaterException();
		}
	}
	catch (invalidCharaterException& e) {
		cout << "\nCharater Exception caught!";
		cout << e.what();
	}

	catch (invalidRangeException& e) {
		cout << "\nRange Exception Caught!";
		cout << e.what();
	}

};

