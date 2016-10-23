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
	myString(char c);
	myString(const char *s);
	myString(const myString &str);
	/* Destructor */
	~myString();
};

#endif