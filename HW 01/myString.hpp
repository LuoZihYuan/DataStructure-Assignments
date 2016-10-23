/* STL Version should be at least C++11 to support Vector */
#ifndef __cplusplus
	#error C++ is required
#elif __cplusplus <= 199711L
	#error This library needs at least a C++11 compliant compiler
#endif

#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <vector>
#include <iostream>
class myString {
private:
	std::vector<char> string;
public:
	/* Constructor */
	myString();
	myString(char);
	myString(const char*);
	myString(const myString&);
	/* Destructor */
	~myString();
	/* overload operator [] */
	char& operator[] (size_t);
	/* overload operator = */
	myString& operator= (char);
	myString& operator= (const char*);
	myString& operator= (const myString&);
	/* overload operator += */
	myString& operator+= (char);
	myString& operator+= (const char*);
	myString& operator+= (const myString&);
	/* overload operator + */
	friend myString operator+ (const myString&, char);
	friend myString operator+ (char, const myString&);
	friend myString operator+ (const myString&, const char*);
	friend myString operator+ (const char*, const myString&);
	friend myString operator+ (const myString&, const myString&);
	/* override operator == */
	friend bool operator== (const myString&, const char*);
	friend bool operator== (const char*, const myString&);
	friend bool operator== (const myString&, const myString&) noexcept;
};

#endif