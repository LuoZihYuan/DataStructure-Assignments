/* STL Version should be at least C++11 to support Vector */
#ifndef __cplusplus
	#error C++ is required
#elif __cplusplus <= 199711L
	#error This library needs at least a C++11 compliant compiler
#endif

#ifndef MAXQUEUE_HPP
#define MAXQUEUE_HPP
#include <vector>
#include <iostream>
class maxQueue {
protected:
	std::vector<int> myQueue;
public:
	/* Constructor */
	maxQueue();
	maxQueue(const maxQueue&);
	/* Destructor */
	~maxQueue();
	/* overload operator = */
	maxQueue& operator= (const maxQueue&);
	/* overload operator << */
	friend std::ostream& operator<< (std::ostream&, const maxQueue&);
	/* maxQueue.size() */
	size_t size() const noexcept;
	/* maxQueue.clear() */
	void clear() noexcept;
	/* maxQueue.empty() */
	bool empty() const noexcept;
	/* maxQueue.push() */
	void push(const int&);
};
#endif