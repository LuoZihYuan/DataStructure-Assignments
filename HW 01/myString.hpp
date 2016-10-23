#ifndef __cplusplus
	#error C++ is required
#elif __cplusplus <= 199711L
	#error This library needs at least a C++11 compliant compiler
#endif

#ifndef MYSTRING_H
#define MYSTRING_H

#include <vector>
#include <iostream>
class myString {
private:
	std::vector<char> string;
public:

};

#endif