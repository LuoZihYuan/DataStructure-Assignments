#ifndef MYDIRTYSTRING_H
#define MYDIRTYSTRING_H

#include <string.h>
#include <iostream>
#include "baseString.hpp"
typedef struct OCCUR{
	int count = 0;
	int *loc = NULL;
} occur;
/* override operator << */
std::ostream& operator<< (std::ostream&, const occur&);

class myDirtyString : public baseString {
	using baseString::baseString;
public:
	/* myDirtyString.freq() */
	occur freq(char);
	occur freq(const char*);
	occur freq(const myDirtyString&);
	/* myDirtyString.del() */
	myDirtyString& del(char);
	myDirtyString& del(const char*);
	myDirtyString& del(const myDirtyString&);
	/* del() */
	friend myDirtyString del(const myDirtyString&, char);
	friend myDirtyString del(const myDirtyString&, const char*);
	friend myDirtyString del(const char*, const myDirtyString&);
	friend myDirtyString del(const myDirtyString&, const myDirtyString&);
};
#endif