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
std::ostream& operator<<(std::ostream &output, const myString &str) {
	return output << str.string;
}
/* override operator >> */
std::istream& operator>> (std::istream &input, myString &str) {
	return input >> str.string;
}