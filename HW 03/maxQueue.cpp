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
		if (i == position) {
		} else if (i == check) {
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
/* maxQueue.clear() */
void maxQueue::clear() noexcept {
	myQueue.clear();
	myQueue.push_back(0);
}
/* maxQueue.empty() */
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
/* maxQueue.pop() */
void maxQueue::pop() {
	size_t position = 1;
	size_t childPosition = position * 2;
	size_t queueSize = size();
	if (queueSize == 0) {
		return;
	}
	while (childPosition <= queueSize) {
		size_t swapPosition;
		if (childPosition == queueSize) {
			swapPosition = childPosition;
		} else {
			swapPosition = (myQueue[childPosition] > myQueue[childPosition + 1])
						   ? childPosition
						   : childPosition + 1;
		}
		int temp = myQueue[position];
		myQueue[position] = myQueue[swapPosition];
		myQueue[swapPosition] = temp;
		position = swapPosition;
		childPosition = position * 2;
	}
	myQueue.erase(myQueue.begin() + position);
}
/* maxQueue.computSize() */
size_t maxQueue::computSize(const size_t &pos) const {
	size_t queueSize = size();
	if ((pos <= 0) || (pos > queueSize)) {
		throw std::out_of_range("maxQueue");
	}
	size_t level = 0;
	for (size_t i = pos * 2; i <= queueSize; i *= 2) {
		level += 1;
	}
	size_t remainder = (queueSize - (pos << level)) + 1;
	size_t limit = 1 << (level - 1);
	remainder = (remainder > limit) ? limit : remainder;
	size_t divisible = limit - 1;
	size_t total = (level == 0) ? 0 : divisible + remainder;
	return total;
}