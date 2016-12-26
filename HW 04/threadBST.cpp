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
}