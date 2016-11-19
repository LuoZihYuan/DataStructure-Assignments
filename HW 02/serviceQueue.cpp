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
client& serviceQueue::operator[] (size_t pos) {
	return myQueue[pos];
}
/* overload operator = */
serviceQueue& serviceQueue::operator= (const serviceQueue &queue) {
	myQueue = queue.myQueue;
	return *this;
}
/* serviceQueue.add() */
void serviceQueue::add(const client &newClient) {
	myQueue.push_back(newClient);
}