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
/* overload operator << */
std::ostream& operator<< (std::ostream &os, const myString &str) {
	for(char c: str.string) {
		os << c;
	}
	return os;
}
/* overload operator >> */
std::istream& operator>> (std::istream &is, myString &str) {
	char c;
	is.get(c);
	while(c != ' ' && c != '\n') {
		str.string.push_back(c);
		is.get(c);
	}
	return is;
}
/* myString.size() */
size_t myString::size() const noexcept {
	return string.size();
}
/* myString.length() */
size_t myString::length() const noexcept {
	return string.size();
}
/* myString.clear() */
void myString::clear() noexcept {
	string.clear();
}
/* myString.empty() */
bool myString::empty() const noexcept {
	return string.empty();
}
/* myString.replace() */
myString& myString::replace(size_t pos, size_t len, const char *s) {
	std::vector<char>::iterator begin = string.begin() + pos;
	string.erase(begin, (begin + len));
	for(int i = 0; s[i] != '\0'; i++) {
		string.insert(begin + i, s[i]);
	}
	return *this;
}
myString& myString::replace(size_t pos, size_t len, const char *s, size_t n) {
	std::vector<char>::iterator begin = string.begin() + pos;
	string.erase(begin, (begin + len));
	for(int i = 0; i < n; i++) {
		for(int j = 0; s[j] != '\0'; j++) {
			string.insert(begin++, s[j]);
		}
	}
	return *this;
}
myString& myString::replace(size_t pos, size_t len, size_t n, char c) {
	std::vector<char>::iterator begin = string.begin() + pos;
	string.erase(begin, (begin + len));
	string.insert(begin, n, c);
	return *this;
}
myString& myString::replace(size_t pos, size_t len, const myString &str) {
	std::vector<char>::iterator begin = string.begin() + pos;
	string.erase(begin, (begin + len));
	for(char c: str.string) {
		string.insert(begin++, c);
	}
	return *this;
}
myString& myString::replace(size_t pos, size_t len, const myString &str, size_t subpos, size_t sublen) {
	std::vector<char>::iterator begin = string.begin() + pos;
	string.erase(begin, (begin + len));
	for(int i = 0; i < sublen; i++) {
		string.insert(begin++, str.string[subpos + i]);
	}
	return *this;
}