#include "myString.hpp"
/* Constructor */
myString::myString() {
}
myString::myString(char c) {
	string.push_back(c);
}
myString::myString(const char *s) {
	int i = 0;
	while(s[i++] != '\0') {
		string.push_back(s[i-1]);
	}
}
myString::myString(const myString &str) {
	for(char c: str.string) {
		string.push_back(c);
	}
}
/* Destructor */
myString::~myString() {
	string.clear();
}