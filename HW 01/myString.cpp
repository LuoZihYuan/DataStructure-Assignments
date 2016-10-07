#include "myString.hpp"
// Constructor & Destructor
myString::myString() {
}
myString::myString(const char *str) {
	size_t len = strlen(str);
	string = new char[len];
	strcpy(string, str);
}
myString::~myString() {
	delete[] string;
}
// override operator =
myString& myString::operator= (const char *str) {
	size_t len = strlen(str);
	string = new char[len];
	strcpy(string, str);
	return *this;
}