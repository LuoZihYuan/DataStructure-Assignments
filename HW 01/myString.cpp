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
/* overload operator [] */
char& myString::operator[] (size_t pos) {
	return string[pos];
}
/* overload operator = */
myString& myString::operator= (char c) {
	string.clear();
	string.push_back(c);
	return *this;
}
myString& myString::operator= (const char *s) {
	string.clear();
	int i = 0;
	while(s[i++] != '\0') {
		string.push_back(s[i-1]);
	}
	return *this;
}
myString& myString::operator= (const myString &str) {
	string = str.string;
	return *this;
}
/* overload operator += */
myString& myString::operator+= (char c) {
	string.push_back(c);
	return *this;
}
myString& myString::operator+= (const char *s) {
	int i = 0;
	while(s[i++] != '\0') {
		string.push_back(s[i-1]);
	}
	return *this;
}
myString& myString::operator+= (const myString &str) {
	for(char c: str.string) {
		string.push_back(c);
	}
	return *this;
}
/* overload operator + */
myString operator+ (const myString &lhs, char rhs) {
	myString newString = lhs;
	newString += rhs;
	return newString;
}
myString operator+ (char lhs, const myString &rhs) {
	myString newString = lhs;
	newString += rhs;
	return newString;
}
myString operator+ (const myString &lhs, const char *rhs) {
	myString newString = lhs;
	newString += rhs;
	return newString;
}
myString operator+ (const char *lhs, const myString &rhs) {
	myString newString = lhs;
	newString += rhs;
	return newString;
}
myString operator+ (const myString &lhs, const myString &rhs) {
	myString newString = lhs;
	newString += rhs;
	return newString;
}
/* overload operator == */
bool operator== (const myString &lhs, const char *rhs) {
	int i = 0;
	while(rhs[i++] != '\0') {
		if(lhs.string[i-1] != rhs[i-1])
			return false;
	}
	return true;
}
bool operator== (const char *lhs, const myString &rhs) {
	int i = 0;
	while(lhs[i++] != '\0') {
		if(lhs[i-1] != rhs.string[i-1])
			return false;
	}
	return true;
}
bool operator== (const myString &lhs, const myString &rhs) noexcept {
	if(lhs.string.size() != rhs.string.size()) {
		return false;
	} else {
		int i = 0, length = lhs.string.size();
		while(i++ != length) {
			if(lhs.string[i-1] != rhs.string[i-1])
				return false;
		}
	}
	return true;
}
/* overload operator != */
bool operator!= (const myString &lhs, const char *rhs) {
	return !(lhs == rhs);
}
bool operator!= (const char *lhs, const myString &rhs) {
	return !(lhs == rhs);
}
bool operator!= (const myString &lhs, const myString &rhs) noexcept {
	return !(lhs == rhs);
}