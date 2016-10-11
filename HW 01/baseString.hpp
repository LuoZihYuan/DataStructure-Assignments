#ifndef BASESTRING_H
#define BASESTRING_H

#include <string.h>
#include <iostream>
class baseString {
protected:
	char *string;
public:
	/* Constructor */
	baseString();
	baseString(const char*);
	baseString(const baseString&);
	/* Destructor */
	~baseString();
	/* override operator [] */
	char& operator[] (size_t);
	/* override operator = */
	baseString& operator= (char);
	baseString& operator= (const char*);
	baseString& operator= (const baseString&);
	/* override operator += */
	baseString& operator+= (char);
	baseString& operator+= (const char*);
	baseString& operator+= (const baseString&);
	/* override operator + */
	friend baseString operator+ (const baseString&, char);
	friend baseString operator+ (char, const baseString&);
	friend baseString operator+ (const baseString&, const char*);
	friend baseString operator+ (const char*, const baseString&);
	friend baseString operator+ (const baseString&, const baseString&);
	/* override operator == */
	friend bool operator== (const baseString&, const char*);
	friend bool operator== (const char*, const baseString&);
	friend bool operator== (const baseString&, const baseString&) noexcept;
	/* override operator != */
	friend bool operator!= (const baseString&, const char*);
	friend bool operator!= (const char*, const baseString&);
	friend bool operator!= (const baseString&, const baseString&) noexcept;
	/* override operator << */
	friend std::ostream& operator<< (std::ostream&, const baseString&);
	/* override operator >> */
	friend std::istream& operator>> (std::istream&, baseString&);
	/* baseString.size() */
	size_t size() const noexcept;
	/* baseString.length() */
	size_t length() const noexcept;
	/* baseString.clear() */
	void clear() noexcept;
	/* baseString.empty() */
	bool empty() const noexcept;
	/* baseString.replace() */
	baseString& replace(size_t, size_t, const char*);
	baseString& replace(size_t, size_t, const char*, size_t);
	baseString& replace(size_t, size_t, size_t, char);
	baseString& replace(size_t, size_t, const baseString&);
	baseString& replace(size_t, size_t, const baseString&, size_t, size_t);
	/* baseString.find() */
	size_t find(char, size_t pos = 0) const;
	size_t find(const char*, size_t pos = 0) const;
	size_t find(const baseString&, size_t pos = 0) const noexcept;
};
#endif