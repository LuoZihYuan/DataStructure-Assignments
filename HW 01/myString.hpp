#ifndef MYSTRING_H
#define MYSTRING_H

#include <string.h>
#include <iostream>
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
	// override operator <<
	friend std::ostream& operator<<(std::ostream&, const myString&);
};
#endif