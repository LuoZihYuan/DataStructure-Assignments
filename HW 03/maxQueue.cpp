#include "maxQueue.hpp"
/* Constructor */
maxQueue::maxQueue() {
	myQueue.push_back(0);
}
maxQueue::maxQueue(const maxQueue &queue) {
	myQueue = queue.myQueue;
}
/* Destructor */
maxQueue::~maxQueue() {
	myQueue.clear();
}
/* overload operator = */
maxQueue& maxQueue::operator= (const maxQueue &queue) {
	myQueue = queue.myQueue;
	return *this;
}
/* overload operator << */
std::ostream& operator<< (std::ostream &os, const maxQueue &queue) {
	size_t position = queue.size();
	for (size_t i = 1, check = 1; i <= position; i++) {
		os << queue.myQueue[i];
		if (i == check) {
			os << std::endl;
			check = check * 2 + 1;
		} else {
			os << " ";
		}
	}
	return os;
}
/* maxQueue.size() */
size_t maxQueue::size() const noexcept {
	return (myQueue.size() - 1);
}
/* myQueue.clear() */
void maxQueue::clear() noexcept {
	myQueue.clear();
	myQueue.push_back(0);
}
/* myQueue.empty() */
bool maxQueue::empty() const noexcept {
	return (myQueue.size() <= 1) ? true: false;
}
/* maxQueue.push() */
void maxQueue::push(const int &num) {
	myQueue.push_back(num);
	size_t position = size();
	while ((position >> 1) != 0) {
		size_t fatherPosition = position >> 1;
		if (myQueue[position] > myQueue[fatherPosition]) {
			int temp = myQueue[fatherPosition];
			myQueue[fatherPosition] = myQueue[position];
			myQueue[position] = temp;
			position = position >> 1;
		} else {
			break;
		}
	}
}