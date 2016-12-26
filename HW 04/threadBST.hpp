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
	size_t size;
public:
	/* Constructor */
	threadBST();
	threadBST(const std::vector<int>&);
	threadBST(const threadBST&);
	/* Destructor */
	~threadBST();
	/* threadBST.add() */
	void add(const int&);
};
#endif