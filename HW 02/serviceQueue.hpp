/* STL Version should be at least C++11 to support Vector */
#ifndef __cplusplus
	#error C++ is required
#elif __cplusplus <= 199711L
	#error This library needs at least a C++11 compliant compiler
#endif

#ifndef SERVICEQUEUE_HPP
#define SERVICEQUEUE_HPP
#include <vector>
#include "baseClient.hpp"
class serviceQueue {
private:
	std::vector<baseClient> myQueue;
public:
	/* Constructor */
	serviceQueue();
	serviceQueue(const serviceQueue&);
	/* Destructor */
	~serviceQueue();
	/* overload operator [] */
	baseClient& operator[] (size_t);
	/* overload operator = */
	serviceQueue& operator= (const serviceQueue&);
	/* serviceQueue.add() */
	void add(const baseClient&);
};
#endif