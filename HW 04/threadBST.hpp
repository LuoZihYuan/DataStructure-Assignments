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
class threadBST {
private:
	/* Node of a Binary Search Tree */
	typedef struct NODE{
		int num;
		size_t leftSubtree;
		struct NODE *leftNode;
		struct NODE *rightNode;
		struct NODE *leftThread;
		struct NODE *rightThread;
	} node;

	size_t size;
	node *root;
public:
	/* Constructor */
	threadBST();
	threadBST(const int*);
	threadBST(const std::vecotr<int>&);
	threadBST(const threadBST&);
	/* Destructor */
	~threadBST();
	/* threadBST.add() */
};
#endif