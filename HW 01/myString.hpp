#ifndef MYSTRING_H
#define MYSTRING_H

#include <string.h>
class myString {
private:
	char *string;
public:
	// Constructor & Destructor
	myString();
	myString(const char*);
	~myString();
	// override operator =
	myString& operator= (const char*);
};
#endif