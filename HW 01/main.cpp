#include <iostream>
#include "myString.hpp"
using namespace std;
void frequency(const myString&);
void characterDelete(myString&);
int main(void) {
	int choice;
	myString s;
	cout << "================= GO =================" << endl;
	cout << "S: ";
	getline(cin, s);
	while(s.size() > 0){
		static char choice;
		cout << endl << "================ MENU ================" << endl;
		cout << " [1] Frequency" << endl;
		cout << " [2] CharacterDelete" << endl;
		cout << " ... EXIT" << endl << endl;
		cout << "MODE: ";
		cin.get(choice);
		cin.ignore();
		cout << " >> Leave str blank to return to MENU" << endl << endl;
		switch(choice) {
			case '1': frequency(s);
				break;
			case '2': characterDelete(s);
				break;
			default: cout << "================ OVER ================" << endl;
				exit(0);
		}
	}
	cout << "================ OVER ================" << endl;
	return 0;
}

void frequency(const myString &s) {
	myString str;
	cout << "============ 1. Frequency ============" << endl;
	do {
		cout << endl << "S: " << s << endl;
		cout << "str: ";
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
		getline(cin, str);
		if(str.size() > 0) {
			cout << "ans: " << s.del(str) << endl;
		}
	} while((str.size() > 0) && (s.size() > 0));
}