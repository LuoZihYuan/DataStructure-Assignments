/* STL Version should be at least C++11 to support Vector */
#ifndef __cplusplus
	#error C++ is required
#elif __cplusplus <= 199711L
	#error This library needs at least a C++11 compliant compiler
#endif

#ifndef THREADNODE_HPP
#define THREADNODE_HPP
#include <stddef.h>
struct threadNode {
	int num;
	size_t leftSize;
	threadNode *leftNode;
	threadNode *rightNode;
	threadNode *leftThread;
	threadNode *rightThread;

	/* Constructor */
	threadNode() = delete;
	threadNode(const int&);
	/* Destructor */
	~threadNode();
};
#endif