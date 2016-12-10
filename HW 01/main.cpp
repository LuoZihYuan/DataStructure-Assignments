#include <iostream>
#include "myString.hpp"
using namespace std;
void frequency(const myString&);
void characterDelete(myString&);
int main(void) {
	char choice;
	myString s;
	cout << "================= GO =================" << endl;
	cout << "S: ";
	getline(cin, s);
	while(s.size() > 0){
		cout << endl << "================ MENU ================" << endl;
		cout << " [1] Frequency" << endl;
		cout << " [2] CharacterDelete" << endl;
		cout << " ... EXIT" << endl << endl;
		cout << "MODE: ";
		cin.clear();
		cin.ignore();
		cin.get(choice);
		switch(choice) {
			case '1': cout << " >> Leave str blank to return to MENU" << endl << endl; 
				frequency(s);
				break;
			case '2': cout << " >> Leave str blank to return to MENU" << endl << endl;
				characterDelete(s);
				break;
			default: cout << endl << "================ OVER ================" << endl;
				exit(0);
		}
	}
	cout << endl << "================ OVER ================" << endl;
	return 0;
}

void frequency(const myString &s) {
	myString str;
	cout << "============ 1. Frequency ============" << endl;
	do {
		cout << endl << "S: " << s << endl;
		cout << "str: ";
		cin.clear();
		cin.ignore();
		getline(cin, str);
		if(str.size() > 0) {
			cout << "ans: " << s.freq(str) << endl;
		}
	} while((str.size() > 0) && (s.size() > 0));
}

void characterDelete(myString &s) {
	myString str;
	cout << "========= 2. CharacterDelete =========" << endl;
	do {
		cout << endl << "S: " << s << endl;
		cout << "str: ";
		cin.clear();
		cin.ignore();
		getline(cin, str);
		if(str.size() > 0) {
			cout << "ans: " << s.del(str) << endl;
		}
	} while((str.size() > 0) && (s.size() > 0));
}