#include <iostream>
#include "maxQueue.hpp"
using namespace std;
int main(void) {
	maxQueue queue;
	int count, num;
	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> num;
		queue.push(num);
		cout << queue << endl << endl;
	}
	cin >> count;
	cout << queue.computSize(count) << endl;
	return 0;
}