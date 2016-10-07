#include "myString.hpp"
/* Constructor & Destructor */
myString::myString() {
	string = new char[0];
}
myString::myString(const char *str) {
	size_t len = strlen(str);
	string = new char[len];
	strcpy(string, str);
}
myString::~myString() {
	delete[] string;
}
/* override operator = */
myString& myString::operator= (const char *str) {
	delete[] string;
	size_t len = strlen(str);
	string = new char[len];
	strcpy(string, str);
	return *this;
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