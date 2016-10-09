#include "myString.hpp"
/* Constructor */
myString::myString() {
	string = new char[0];
}
myString::myString(const char *s) {
	size_t len = strlen(s);
	string = new char[len];
	strcpy(string, s);
}
myString::myString(const myString &str) {
	size_t len = strlen(str.string);
	string = new char[len];
	strcpy(string, str.string);
}
/* Destructor */
myString::~myString() {
	delete[] string;
}
/* override operator = */
myString& myString::operator= (char c) {
	delete[] string;
	string = new char;
	string[0] = c;
	return *this;
}
myString& myString::operator= (const char *str) {
	delete[] string;
	size_t len = strlen(str);
	string = new char[len];
	strcpy(string, str);
	return *this;
}
myString& myString::operator= (const myString &str) {
	delete[] string;
	size_t len = strlen(str.string);
	string = new char[len];
	strcpy(string, str.string);
	return *this;
}
/* override operator [] */
char& myString::operator[] (size_t pos) {
	return string[pos];
}
/* override operator + */
myString operator+ (const myString &lhs, char rhs) {
	int newLength = strlen(lhs.string) + 1;
	char *buffer = new char[newLength];
	strcat(buffer, lhs.string);
	buffer[newLength - 1] = rhs;
	myString newString = buffer;
	delete[] buffer;
	return newString;
}
myString operator+ (char lhs, const myString &rhs) {
	int newLength = strlen(rhs.string) + 1;
	char *buffer = new char[newLength];
	buffer[0] = lhs;
	strcat(buffer, rhs.string);
	myString newString = buffer;
	delete[] buffer;
	return newString;
}
myString operator+ (const myString &lhs, const char *rhs) {
	int newLength;
	char *buffer;
	newLength = strlen(lhs.string) + strlen(rhs);
	buffer = new char[newLength];
	strcat(buffer, lhs.string);
	strcat(buffer, rhs);
	myString newString = buffer;
	delete[] buffer;
	return newString;
}
myString operator+ (const char *lhs, const myString &rhs) {
	int newLength;
	char *buffer;
	newLength = strlen(lhs) + strlen(rhs.string);
	buffer = new char[newLength];
	strcat(buffer, lhs);
	strcat(buffer, rhs.string);
	myString newString = buffer;
	delete[] buffer;
	return newString;
}
myString operator+ (const myString &lhs, const myString &rhs) {
	int newLength;
	char *buffer;
	newLength = strlen(lhs.string) + strlen(rhs.string);
	buffer = new char[newLength];
	strcat(buffer, lhs.string);
	strcat(buffer, rhs.string);
	myString newString = buffer;
	delete[] buffer;
	return newString;
}
/* override operator == */
bool operator== (const myString &lhs, const char *rhs) {
	return (strcmp(lhs.string, rhs)) ? false: true;
}
bool operator== (const char *lhs, const myString &rhs) {
	return (strcmp(lhs, rhs.string)) ? false: true;
}
bool operator== (const myString &lhs, const myString &rhs) noexcept {
	return (strcmp(lhs.string, rhs.string)) ? false: true;
}
/* override operator != */
bool operator!= (const myString &lhs, const char *rhs) {
	return (strcmp(lhs.string, rhs)) ? true: false;
}
bool operator!= (const char *lhs, const myString &rhs) {
	return (strcmp(lhs, rhs.string)) ? true: false;
}
bool operator!= (const myString &lhs, const myString &rhs) noexcept {
	return (strcmp(lhs.string, rhs.string)) ? true: false;
}
/* override operator << */
std::ostream& operator<< (std::ostream &os, const myString &str) {
	return os << str.string;
}
/* override operator >> */
std::istream& operator>> (std::istream &is, myString &str) {
	return is >> str.string;
}
/* myString.size() */
size_t myString::size() const noexcept {
	return strlen(string);
}
/* myString.length() */
size_t myString::length() const noexcept {
	return strlen(string);
}
/* myString.clear() */
// XXX: Temporarily uses strcpy to empty string
void myString::clear() noexcept {
	if (strlen(string)) {
		delete[] string;
		string = new char[0];
		strcpy(string, "");
	}
}
/* myString.empty() */
bool myString::empty() const noexcept {
	return (strlen(string)) ? false: true;
}