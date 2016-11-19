#ifndef BASECLIENT_HPP
#define BASECLIENT_HPP
#include <string>
#include <iostream>
class baseClient {
	friend class serviceQueue;
protected:
	bool served;
	time_t departure_time;
public:
	// std::string identifier;
	time_t arrival_time;
	time_t service_time;
	time_t waiting_time;
	/* Constructor */
	baseClient();
	baseClient(const baseClient&);
	baseClient(const time_t&, const time_t&, const time_t&);
	// baseClient(const std::string&, const time_t&, const time_t&, const time_t&);
	/* Destructor */
	~baseClient();
	/* overload operator = */
	baseClient& operator= (const baseClient&);
	/* overload operator << */
	friend std::ostream& operator<< (std::ostream&, const baseClient&);
	/* overload operator >> */
	friend std::istream& operator>> (std::istream&, baseClient&);
	// friend std::istream& getline (std::istream&, baseClient&);
	/* baseClient.isServed() */
	bool isServed();
	/* baseClient.getDepartureTime() */
	time_t getDepartureTime();
	/* baseClient.clear() */
	void clear();
};
#endif