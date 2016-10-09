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
	myString(const myString&);
	/* Destructor */
	~myString();
	/* override operator [] */
	char& operator[] (size_t);
	/* override operator = */
	myString& operator= (char);
	myString& operator= (const char*);
	myString& operator= (const myString&);
	/* override operator += */
	myString& operator+= (char);
	myString& operator+= (const char*);
	myString& operator+= (const myString&);
	/* override operator + */
	friend myString operator+ (const myString&, char);
	friend myString operator+ (char, const myString&);
	friend myString operator+ (const myString&, const char*);
	friend myString operator+ (const char*, const myString&);
	friend myString operator+ (const myString&, const myString&);
	/* override operator == */
	friend bool operator== (const myString&, const char*);
	friend bool operator== (const char*, const myString&);
	friend bool operator== (const myString&, const myString&) noexcept;
	/* override operator != */
	friend bool operator!= (const myString&, const char*);
	friend bool operator!= (const char*, const myString&);
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
	/* myString.find() */
	size_t find(char, size_t pos = 0) const;
	size_t find(const char*, size_t pos = 0) const;
	size_t find(const myString&, size_t pos = 0) const noexcept;
};
#endif