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
	/* overload operator == */
	friend bool operator== (const myString&, const char*);
	friend bool operator== (const char*, const myString&);
	friend bool operator== (const myString&, const myString&) noexcept;
	/* overload operator != */
	friend bool operator!= (const myString&, const char*);
	friend bool operator!= (const char*, const myString&);
	friend bool operator!= (const myString&, const myString&) noexcept;
	/* overload operator << */
	friend std::ostream& operator<< (std::ostream&, const myString&);
	/* overload operator >> */
	friend std::istream& operator>> (std::istream&, myString&);
	/* myString.size() */
	size_t size() const noexcept;
	/* myString.length() */
	size_t length() const noexcept;
	/* myString.clear() */
	void clear() noexcept;
	/* myString.empty() */
	bool empty() const noexcept;
	/* myString.replace() */
	myString& replace(size_t, size_t, const char*);
	myString& replace(size_t, size_t, const char*, size_t);
	myString& replace(size_t, size_t, size_t, char);
	myString& replace(size_t, size_t, const myString&);
	myString& replace(size_t, size_t, const myString&, size_t, size_t);
	/* myString.find() */
	size_t find(char, size_t pos = 0) const;
	size_t find(const char*, size_t pos = 0) const;
	size_t find(const myString&, size_t pos = 0) const noexcept;
};

#endif