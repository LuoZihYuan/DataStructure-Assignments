#include <iostream>
#include "myString.hpp"
using namespace std;
void frequency(const myString&);
void characterDelete(const myString&);
int main(void) {
	int choice;
	myString s;
	cout << "S: ";
	getline(cin, s);
	cout << s << endl;
	while(true){
		cout << "----- MENU -----" << endl;
		cout << "[1] Frequency" << endl;
		cout << "[2] CharacterDelete" << endl;
		cin >> choice;
		switch(choice) {
			case 1: frequency(s);
				break;
			case 2: characterDelete(s);
				break;
			default: exit(0);
		}
	}
	return 0;
}

void frequency(const myString &str) {

}

void characterDelete(const myString&) {

}