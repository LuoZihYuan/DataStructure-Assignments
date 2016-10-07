#ifndef MYSTRING_H
#define MYSTRING_H

#include <string.h>
class myString {
private:
	char *string;
public:
	myString(const char*);
	~myString();
};
#endif