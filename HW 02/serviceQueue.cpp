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
baseClient* serviceQueue::operator[] (size_t pos) {
	return myQueue[pos];
}
/* overload operator = */
serviceQueue& serviceQueue::operator= (const serviceQueue &queue) {
	myQueue = queue.myQueue;
	return *this;
}
/* serviceQueue.add() */
void serviceQueue::add(baseClient *newClient) {
	if(lastServed == NULL) {
		newClient->served = true;
		newClient->departure_time = newClient->arrival_time + newClient->service_time;
		lastServed = newClient;
	} else {
		if(lastServed->departure_time > (newClient->arrival_time + newClient->waiting_time)) {
			time_t past_time = lastServed->departure_time - lastServed->service_time;
			time_t possible_time = newClient->service_time + ((newClient->arrival_time > past_time) ? newClient->arrival_time: past_time);
			if(possible_time < (lastServed->arrival_time + lastServed->waiting_time)) {
				newClient->served = true;
				newClient->departure_time = possible_time;
				lastServed->departure_time = lastServed->service_time + ((lastServed->arrival_time > possible_time)? lastServed->arrival_time: possible_time);
			} else {
				newClient->served = false;
			}
		} else {
			newClient->served = true;
			newClient->departure_time = newClient->service_time + ((newClient->arrival_time > lastServed->departure_time)? newClient->arrival_time: lastServed->departure_time);
			lastServed = newClient;
		}
	}
	myQueue.push_back(newClient);
}