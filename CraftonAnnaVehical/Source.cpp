//Anna Crafton
//CIS 1202 101
//July 30 2021

#include <iostream>
#include <locale>

using namespace std;

//functions
char character(char, int);

int main(){
	char letter;
	int num;
	char newLetter;

	cout << "\nLetter: ";
	cin >> letter;
	cout << "\nNumber: ";
	cin >> num;

	newLetter = character(letter,num);

	cout << "The new Letter is " << newLetter;
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

	if (isalpha(start)) {
		//deterines if upper or lower and does math acordingly.
		if (isupper(start)) {
			startNum = (int(start) - 64);
			cout << "\nstart is a upper letter! " << startNum;
		}
		else {
			startNum = (int(start) - 96);
			cout << "\nstart is a lower letter! " << startNum;
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
			cout << "\noffset is a number! " << offset;	
			cout << "\nrange is " << low << " to " << high; 
			newChar = char((start + offset));
		}
		else {
			//throw exception bc not a number.
			cout << "\nBad Offset!";
			return 'a';
		}
	
	}
	else {
		//throw exception bc not a letter
		cout << "\nBad Start!";
		return 'a';
	}

	cout << "\n" << newChar;
	return newChar;
};