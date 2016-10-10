#include "baseString.hpp"
/* Constructor */
baseString::baseString() {
	string = new char[0];
}
baseString::baseString(const char *s) {
	size_t len = strlen(s);
	string = new char[len];
	strcpy(string, s);
}
baseString::baseString(const baseString &str) {
	size_t len = strlen(str.string);
	string = new char[len];
	strcpy(string, str.string);
}
/* Destructor */
baseString::~baseString() {
	delete[] string;
}
/* override operator [] */
char& baseString::operator[] (size_t pos) {
	return string[pos];
}
/* override operator = */
baseString& baseString::operator= (char c) {
	delete[] string;
	string = new char;
	string[0] = c;
	return *this;
}
baseString& baseString::operator= (const char *str) {
	delete[] string;
	size_t len = strlen(str);
	string = new char[len];
	strcpy(string, str);
	return *this;
}
baseString& baseString::operator= (const baseString &str) {
	delete[] string;
	size_t len = strlen(str.string);
	string = new char[len];
	strcpy(string, str.string);
	return *this;
}
/* override operator += */
baseString& baseString::operator+= (char c) {
	size_t newLength = strlen(string) + 1;
	char *buffer = string;
	string = new char[newLength];
	strcat(string, buffer);
	string[newLength - 1] = c;
	delete[] buffer;
	return *this;
}
baseString& baseString::operator+= (const char *s) {
	size_t newLength = strlen(string) + strlen(s);
	char *buffer = string;
	string = new char[newLength];
	strcat(string, buffer);
	strcat(string, s);
	delete[] buffer;
	return *this;
}
baseString& baseString::operator+= (const baseString &str) {
	size_t newLength = strlen(string) + strlen(str.string);
	char *buffer = string;
	string = new char[newLength];
	strcat(string, buffer);
	strcat(string, str.string);
	delete[] buffer;
	return *this;
}
/* override operator + */
baseString operator+ (const baseString &lhs, char rhs) {
	size_t newLength = strlen(lhs.string) + 1;
	char *buffer = new char[newLength];
	strcat(buffer, lhs.string);
	buffer[newLength - 1] = rhs;
	baseString newString = buffer;
	delete[] buffer;
	return newString;
}
baseString operator+ (char lhs, const baseString &rhs) {
	size_t newLength = strlen(rhs.string) + 1;
	char *buffer = new char[newLength];
	buffer[0] = lhs;
	strcat(buffer, rhs.string);
	baseString newString = buffer;
	delete[] buffer;
	return newString;
}
baseString operator+ (const baseString &lhs, const char *rhs) {
	size_t newLength = strlen(lhs.string) + strlen(rhs);
	char *buffer = new char[newLength];
	strcat(buffer, lhs.string);
	strcat(buffer, rhs);
	baseString newString = buffer;
	delete[] buffer;
	return newString;
}
baseString operator+ (const char *lhs, const baseString &rhs) {
	size_t newLength = strlen(lhs) + strlen(rhs.string);
	char *buffer = new char[newLength];
	strcat(buffer, lhs);
	strcat(buffer, rhs.string);
	baseString newString = buffer;
	delete[] buffer;
	return newString;
}
baseString operator+ (const baseString &lhs, const baseString &rhs) {
	size_t newLength = strlen(lhs.string) + strlen(rhs.string);
	char *buffer = new char[newLength];
	strcat(buffer, lhs.string);
	strcat(buffer, rhs.string);
	baseString newString = buffer;
	delete[] buffer;
	return newString;
}
/* override operator == */
bool operator== (const baseString &lhs, const char *rhs) {
	return (strcmp(lhs.string, rhs)) ? false: true;
}
bool operator== (const char *lhs, const baseString &rhs) {
	return (strcmp(lhs, rhs.string)) ? false: true;
}
bool operator== (const baseString &lhs, const baseString &rhs) noexcept {
	return (strcmp(lhs.string, rhs.string)) ? false: true;
}
/* override operator != */
bool operator!= (const baseString &lhs, const char *rhs) {
	return (strcmp(lhs.string, rhs)) ? true: false;
}
bool operator!= (const char *lhs, const baseString &rhs) {
	return (strcmp(lhs, rhs.string)) ? true: false;
}
bool operator!= (const baseString &lhs, const baseString &rhs) noexcept {
	return (strcmp(lhs.string, rhs.string)) ? true: false;
}
/* override operator << */
std::ostream& operator<< (std::ostream &os, const baseString &str) {
	return os << str.string;
}
/* override operator >> */
std::istream& operator>> (std::istream &is, baseString &str) {
	return is >> str.string;
}
/* baseString.size() */
size_t baseString::size() const noexcept {
	return strlen(string);
}
/* baseString.length() */
size_t baseString::length() const noexcept {
	return strlen(string);
}
/* baseString.clear() */
// XXX: Temporarily uses strcpy to empty string
void baseString::clear() noexcept {
	if (strlen(string)) {
		delete[] string;
		string = new char[0];
		strcpy(string, "");
	}
}
/* baseString.empty() */
bool baseString::empty() const noexcept {
	return (strlen(string)) ? false: true;
}
/* baseString.replace() */
baseString& baseString::replace(size_t pos, size_t len, const char *s) {
	if (pos > strlen(string)) {
		throw std::out_of_range("char*");
	}
	size_t newLength = strlen(string) - len + strlen(s);
	char *buffer = string;
	string = new char[newLength];
	strncpy(string, buffer, pos);
	strcat(string, s);
	strcat(string, buffer + pos + len);
	delete[] buffer;
	return *this;
}
baseString& baseString::replace(size_t pos, size_t len, const char *s, size_t n) {
	if (pos > strlen(string)) {
		throw std::out_of_range("char*");
	} else if ((int)n < 0) {
		throw std::length_error("char*");
	}
	size_t newLength = strlen(string) - len + (strlen(s) * n);
	char *buffer = string;
	string = new char[newLength];
	strncpy(string, buffer, pos);
	for(int i = 0; i < n; i++) {
		strcat(string, s);
	}
	strcat(string, buffer + pos + len);
	delete[] buffer;
	return *this;
}
baseString& baseString::replace(size_t pos, size_t len, size_t n, char c) {
	if (pos > strlen(string)) {
		throw std::out_of_range("char*");
	} else if ((int)n < 0) {
		throw std::length_error("char*");
	}
	size_t newLength = strlen(string) - len + n;
	char *buffer = string;
	string = new char[newLength];
	strncpy(string, buffer, pos);
	for(size_t i = 0; i < n; i++) {
		string[pos + i] = c;
	}
	strcat(string, buffer + pos + len);
	delete[] buffer;
	return *this;
}
baseString& baseString::replace(size_t pos, size_t len, const baseString &str) {
	if (pos > strlen(string)) {
		throw std::out_of_range("char*");
	}
	size_t newLength = strlen(string) - len + strlen(str.string);
	char *buffer = string;
	string = new char[newLength];
	strncpy(string, buffer, pos);
	strcat(string, str.string);
	strcat(string, buffer + pos + len);
	delete[] buffer;
	return *this;
}
baseString& baseString::replace(size_t pos, size_t len, const baseString &str, size_t subpos, size_t sublen) {
	if (pos > strlen(string) || subpos > strlen(str.string)) {
		throw std::out_of_range("char*");
	}
	size_t newLength = strlen(string) - len + sublen;
	char *buffer = string;
	string = new char[newLength];
	strncpy(string, buffer, pos);
	strncat(string, str.string + subpos, sublen);
	strcat(string, buffer + pos + len);
	delete[] buffer;
	return *this;
}
/* baseString.find() */
size_t baseString::find(char c, size_t pos) const {
	char *pch = strchr(string + pos, c);
	return (pch - string);
}
size_t baseString::find(const char *s, size_t pos) const {
	char *pch = strstr(string + pos, s);
	return (pch - string);
}
size_t baseString::find(const baseString &str, size_t pos) const noexcept {
	char *pch = strstr(string + pos, str.string);
	return (pch - string);
}