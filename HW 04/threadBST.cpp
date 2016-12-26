#include "threadBST.hpp"
/* Constructor */
threadBST::threadBST() {
	root = NULL;
	size = 0;
}
threadBST::threadBST(const std::vector<int> &v) {
	for(int num: v) {
		add(num);
	}
}
threadBST::threadBST(const threadBST &tree) {
}
/* Destructor */
threadBST::~threadBST() {
	delete root;
	root = NULL;
}
/* threadBST.add() */
void threadBST::add(const int &num) {
	threadNode *newNode, *currentNode, *previousNode;
	newNode = new threadNode(num);
	if (size == 0) {
		root = newNode;
		min = newNode;
		max = newNode;
		size += 1;
	} else {
		// determine route taken
		enum Route { left, right, none};

		Route lastRoute;
		currentNode = root;

		// tree trasversal
		while(currentNode != NULL) {
			if (newNode->num > currentNode->num) {
				previousNode = currentNode;
				currentNode = currentNode->rightNode;
				newNode->leftThread = previousNode;
				lastRoute = right;
			} else if (newNode->num < currentNode->num) {
				previousNode = currentNode;
				currentNode = currentNode->leftNode;
				newNode->rightThread = previousNode;
				lastRoute = left;
			} else {
				delete newNode;
				lastRoute = none;
			}
		}

		if (lastRoute != none) {
			if (lastRoute == left) {
				previousNode->leftNode = newNode;
			} else  {
				previousNode->rightNode = newNode;
			}
			if (newNode->leftThread != NULL) {
				newNode->leftThread->rightThread = newNode;
			} else {
				min = newNode;
			}
			if (newNode->rightThread != NULL) {
				newNode->rightThread->leftThread = newNode;
			} else {
				max = newNode;
			}
			size += 1;
		}
	}
}