#include "threadNode.hpp"
/* Constructor */
threadNode::threadNode(const int &n) {
	num = n;
	leftSize = 0;
	leftNode = NULL;
	rightNode = NULL;
	leftThread = NULL;
	rightThread = NULL;
}
/* Destructor */
threadNode::~threadNode() {
	delete leftNode;
	delete rightNode;
};