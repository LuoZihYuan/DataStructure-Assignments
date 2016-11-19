#include "serviceQueue.hpp"
/* Constructor */
serviceQueue::serviceQueue() {
}
serviceQueue::serviceQueue(const serviceQueue &queue) {
	myQueue = queue.myQueue;
}
/* Destructor */
serviceQueue::~serviceQueue() {
	myQueue.clear();
}
/* overload operator [] */
baseClient& serviceQueue::operator[] (size_t pos) {
	return myQueue[pos];
}
/* overload operator = */
serviceQueue& serviceQueue::operator= (const serviceQueue &queue) {
	myQueue = queue.myQueue;
	return *this;
}
/* serviceQueue.add() */
void serviceQueue::add(const baseClient &newClient) {
	myQueue.push_back(newClient);
}