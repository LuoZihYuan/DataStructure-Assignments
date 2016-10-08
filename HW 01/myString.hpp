#ifndef MYSTRING_H
#define MYSTRING_H

#include <string.h>
#include <iostream>
class myString {
private:
	char *string;
public:
	/* Constructor */
	myString();
	myString(const char*);
	/* Destructor */
	~myString();
	/* override operator = */
	myString& operator= (const char*);
	/* override operator [] */
	char& operator[] (size_t);
	/* override operator + */
	friend myString operator+ (const myString&, const myString&);
	/* override operator == */
	friend bool operator== (const myString&, const myString&) noexcept;
	/* override operator != */
	friend bool operator!= (const myString&, const myString&) noexcept;
	/* override operator << */
	friend std::ostream& operator<< (std::ostream&, const myString&);
	/* override operator >> */
	friend std::istream& operator>> (std::istream&, myString&);
	/* myString.size() */
	size_t size() const noexcept;
	/* myString.length() */
	size_t length() const noexcept;
	/* myString.clear() */
	void clear() noexcept;
	/* myString.empty() */
	bool empty() const noexcept;
};
#endif