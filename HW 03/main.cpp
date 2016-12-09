#include <iostream>
#include "maxQueue.hpp"
using namespace std;
int main(void) {
	maxQueue queue;
	int num;
	for (int i = 0; i < 7; i++) {
		cin >> num;
		queue.push(num);
	}
	cout << queue << endl;
	return 0;
}