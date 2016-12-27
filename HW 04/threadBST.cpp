#include "threadBST.hpp"
/* Constructor */
threadBST::threadBST() {
	root = NULL;
	max = NULL;
	min = NULL;
	count = 0;
}
threadBST::threadBST(const std::vector<int> &v) {
	for(int num: v) {
		add(num);
	}
}
threadBST::threadBST(const threadBST &tree) {
	if (tree.count > 0) {
		std::vector<threadNode*> queue;
		queue.push_back(tree.root);
		while(queue.size() > 0) {
			add(queue[0]->num);
			if (queue[0]->leftNode != NULL) {
				queue.push_back(queue[0]->leftNode);
			}
			if (queue[0]->rightNode != NULL) {
				queue.push_back(queue[0]->rightNode);
			}
			queue.erase(queue.begin());
		}
	}
}
/* Destructor */
threadBST::~threadBST() {
	delete root;
}
/* overload operator << */
std::ostream& operator<< (std::ostream &os, const threadBST &tree) {
	if (tree.count > 0) {
		std::vector<threadNode*> queue;
		queue.push_back(tree.root);
		while(queue.size() > 0) {
			os << queue[0]->num << " ";
			if (queue[0]->leftNode != NULL) {
				queue.push_back(queue[0]->leftNode);
			}
			if (queue[0]->rightNode != NULL) {
				queue.push_back(queue[0]->rightNode);
			}
			queue.erase(queue.begin());
		}
	}
	return os;
}
/* threadBST.size() */
size_t threadBST::size() const noexcept {
	return count;
}
/* threadBST.clear() */
void threadBST::clear() noexcept {
	delete root;
	root = NULL;
	max = NULL;
	min = NULL;
	count = 0;
}
/* threadBST.empty() */
bool threadBST::empty() const noexcept {
	return (count == 0) ? true : false;
}
/* threadBST.add() */
void threadBST::add(const int &num) {
	threadNode *newNode, *currentNode, *previousNode;
	newNode = new threadNode(num);
	if (count == 0) {
		root = newNode;
		min = newNode;
		max = newNode;
	} else {
		// determine route taken
		enum Route { left, right};

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
				currentNode->leftSize += 1;
				previousNode = currentNode;
				currentNode = currentNode->leftNode;
				newNode->rightThread = previousNode;
				lastRoute = left;
			} else {
				delete newNode;
				return;
			}
		}

		// link node
		if (lastRoute == left) {
			previousNode->leftNode = newNode;
		} else  {
			previousNode->rightNode = newNode;
		}
		// link thread
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
	}
	count += 1;
}
/* threadBST.remove() */
// void threadBST::remove(const int &num) {
// 	threadNode *currentNode, *previousNode;
// 	previousNode = NULL;
// 	currentNode = root;

// 	// tree trasversal
// 	while(currentNode != NULL) {
// 		if (num > currentNode->num) {
// 			if (currentNode->rightNode != NULL) {
// 				previousNode = currentNode;
// 				currentNode = currentNode->rightNode;
// 			} else {
// 				return;
// 			}
// 		} else if (num < currentNode->num) {
// 			if (currentNode->leftNode != NULL) {
// 				previousNode = currentNode;
// 				currentNode = currentNode->leftNode;
// 			} else {
// 				return;
// 			}
// 		} else {
// 			break;
// 		}
// 	}

// 	// link thread
// 	if (currentNode->leftThread != NULL) {
// 		currentNode->leftThread->rightThread = currentNode->rightThread;
// 	} else {
// 		min = currentNode->rightThread;
// 	}
// 	if (currentNode->rightThread != NULL) {
// 		currentNode->rightThread->leftThread = currentNode->leftThread;
// 	}else {
// 		max = currentNode->leftThread;
// 	}
// 	// link node
// 	if ((currentNode->leftNode != NULL) && (currentNode->rightNode != NULL)) {

// 	} else if (currentNode->leftNode != NULL) {

// 	} else if (currentNode->rightNode != NULL) {

// 	} else {
		
// 	}
// }
/* threadBST.leftSize() */
std::vector<int> threadBST::leftSize() const noexcept {
	std::vector<int> result;
	if (count > 0) {
		std::vector<threadNode*> queue;
		queue.push_back(root);
		while(queue.size() > 0) {
			result.push_back(queue[0]->leftSize);
			if (queue[0]->leftNode != NULL) {
				queue.push_back(queue[0]->leftNode);
			}
			if (queue[0]->rightNode != NULL) {
				queue.push_back(queue[0]->rightNode);
			}
			queue.erase(queue.begin());
		}
	}
	return result;
}
/* threadBST.intAtRank() */
int absolute(int num) {
	return (num < 0) ? -num : num;
}
int threadBST::intAtRank(const int &pos) const {
	if ((absolute(pos) > count) || (pos == 0)) {
		throw std::out_of_range("threadBST");
	} else if (pos > 0) {
		threadNode *currentNode = max;
		for (int i = 1; i < pos; i++) {
			currentNode = currentNode->leftThread;
		}
		return currentNode->num;
	} else {
		threadNode *currentNode = min;
		for (int i = -1; i > pos; i--) {
			currentNode = currentNode->rightThread;
		}
		return currentNode->num;
	}
}