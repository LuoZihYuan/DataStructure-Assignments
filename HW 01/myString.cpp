#include "myString.hpp"
myString::myString(const char *str) {
	size_t len = strlen(str);
	string = new char[len];
	strcpy(string, str);
}

myString::~myString() {
	delete[] string;
}