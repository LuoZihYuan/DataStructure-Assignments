#ifndef CLIENT_HPP
#define CLIENT_HPP
#include <string>
#include <iostream>
typedef struct CLIENT {
	std::string client_name;
	int arrival_time;
	int service_time;
	int waiting_time;
	/* Constructor */
	CLIENT();
	CLIENT(const std::string&, const int&, const int&, const int&);
	/* Destructor */
	~CLIENT();
	/* overload operator << */
	friend std::ostream& operator<< (std::ostream&, const CLIENT&);
	/* overload operator >> */
	friend std::istream& operator>> (std::istream&, CLIENT&);
	friend std::istream& getline (std::istream&, CLIENT&);
	/* client.clear() */
	void clear();
} client;
#endif