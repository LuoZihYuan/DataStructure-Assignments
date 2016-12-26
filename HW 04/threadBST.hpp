/* STL Version should be at least C++11 to support Vector */
#ifndef __cplusplus
	#error C++ is required
#elif __cplusplus <= 199711L
	#error This library needs at least a C++11 compliant compiler
#endif

#ifndef THREADBST_HPP
#define THREADBST_HPP
#include <vector>
#include <iostream>
#include "threadNode.hpp"
class threadBST {
private:
	threadNode *root;
	threadNode *max;
	threadNode *min;
	size_t count;
public:
	/* Constructor */
	threadBST();
	threadBST(const std::vector<int>&);
	threadBST(const threadBST&);
	/* Destructor */
	~threadBST();
	/* overload operator << */
	friend std::ostream& operator<< (std::ostream&, const threadBST&);
	/* threadBST.size() */
	size_t size() const noexcept;
	/* threadBST.clear() */
	void clear() noexcept;
	/* threadBST.empty() */
	bool empty() const noexcept;
	/* threadBST.add() */
	void add(const int&);
	/* threadBST.leftSize() */
	std::vector<int> leftSize() const noexcept;
	/* threadBST.intAtRank() */
	int intAtRank(const int&) const;
};
#endif