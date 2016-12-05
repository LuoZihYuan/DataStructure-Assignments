#include "maxQueue.hpp"
/* Constructor */
maxQueue::maxQueue() {
}
maxQueue::maxQueue(const maxQueue &queue) {
	myQueue = queue.myQueue;
}
/* Destructor */
maxQueue::~maxQueue() {
	myQueue.clear();
}
/* overload operator = */
maxQueue::maxQueue& operator= (const maxQueue &queue) {
	myQueue = queue.myQueue;
}
/* maxQueue.size() */
size_t maxQueue::size() const noexcept {
	return myQueue.size();
}
/* myQueue.clear() */
void maxQueue::clear() noexcept {
	myQueue.clear();
}
/* myQueue.empty() */
bool maxQueue::empty() const noexcept {
	return myQueue.empty();
}