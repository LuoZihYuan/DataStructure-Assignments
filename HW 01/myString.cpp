#include "myString.hpp"
/* Constructor */
myString::myString() {
	string = new char[0];
}
myString::myString(const char *str) {
	size_t len = strlen(str);
	string = new char[len];
	strcpy(string, str);
}
/* Destructor */
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
/* override operator [] */
char& myString::operator[] (size_t pos) {
	return string[pos];
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