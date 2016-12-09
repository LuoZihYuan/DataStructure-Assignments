#include <iostream>
#include "maxQueue.hpp"
using namespace std;
void insert(maxQueue&);
void del(maxQueue&);
void computSize(const maxQueue&);
int main(void) {
	int num;
	size_t size;
	maxQueue queue;
	cout << "================== GO ==================" << endl;
	cout << "Size: ";
	cin >> size;
	cout << "Elements: ";
	for (size_t i = 0; i < size; i++) {
		cin >> num;
		queue.push(num);
	}
	cout << "Initial: " << endl;
	cout << queue << endl;
	while (true) {
		static char choice;
		cout << endl << "================= MENU =================" << endl;
		cout << " [1] Insert" << endl;
		cout << " [2] Delete" << endl;
		cout << " [3] Compute Size" << endl;
		cout << " ... EXIT" << endl << endl;
		cout << "MODE: ";
		cin.ignore();
		cin.get(choice);
		switch(choice) {
			case '1': insert(queue);
				break;
			case '2': del(queue);
				break;
			case '3': computSize(queue);
				break;
			default: cout << endl << "================= OVER =================" << endl;
				exit(0);
		}
	}
	return 0;
}

void insert(maxQueue &queue) {
	int num;
	cout << endl << "=============== 1.Insert ===============" << endl;
	cout << "Num: ";
	cin >> num;
	queue.push(num);
	cout << "Result: " << endl;
	cout << queue << endl;
}

void del(maxQueue &queue) {
	char input;
	cout << endl << "=============== 2.Delete ===============" << endl;
	while (input != 'Y' && input != 'y' && input != 'N' && input != 'n') {
		cout << "Delete? [Y/N]: ";
		cin >> input;
		if (input == 'Y' || input == 'y') {
			queue.pop();
			cout << "Result: " << endl;
			cout << queue << endl;
		}
	}
}

void computSize(const maxQueue &queue) {
	size_t position;
	cout << endl << "============ 3.Compute Size ============" << endl;
	cout << "Position: ";
	cin >> position;
	size_t total = queue.computSize(position);
	cout << "Total: " << total << endl;
}