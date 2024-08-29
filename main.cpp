#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

string alphabet = "    abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!+=";

void printSpaceTimes(int k) { 
	for (int i = 0; i < k; i++)
		cout << " ";
}

void symbolAfterSpace(char ch, int spaceCount) {
	cout << "	";
	printSpaceTimes(spaceCount);
	cout << ch;
	cout << endl;
}

void printAlphabetSymbolNumberwithSpase(int k, int spaceCount) {
	if (k < 0 || k >= alphabet.length()) {
		cout << endl;
		return;
	}

	cout << "	";
	printSpaceTimes(spaceCount);
	cout << alphabet[k];
	cout << endl;
}

void outputString(string str) {
	cout << "	" << str << endl;
}

void addNotExistSymbolsToAlphabet(string str) {
	for (const auto& ch : str) {
		if (alphabet.find(ch) == -1) alphabet += ch;
	}
}

int main() {
	string inputStr;
	cout << "print your line : ";  getline(cin, inputStr);
	addNotExistSymbolsToAlphabet(inputStr);
	cout << endl;
	string outputStr = "";
	int k = 0;
	for (int i = 0; i < inputStr.length(); i++) {	
		k = 1;
		outputStr += alphabet[k];
		k++;
		while (inputStr[i] != outputStr[i]) {
			Sleep(90);
			system("cls");
			printAlphabetSymbolNumberwithSpase(k + 1, i);
			printAlphabetSymbolNumberwithSpase(k, i);
			outputString(outputStr);
			printAlphabetSymbolNumberwithSpase(k - 2, i);
			printAlphabetSymbolNumberwithSpase(k - 3, i);
			
			outputStr[i] = alphabet[k];
			k++;
		}
		system("cls");
		symbolAfterSpace('#', i);
		symbolAfterSpace('#', i);
		outputString(outputStr);
		symbolAfterSpace('#', i);
		symbolAfterSpace('#', i);
		Sleep(10);
	}
	system("cls");
	cout << endl;
	cout << endl;
	outputString(outputStr);
	cout << endl;
	cout << endl; 
	system("pause");
	return 0;
}