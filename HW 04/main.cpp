#include <vector>
#include <iostream>
#include "threadBST.hpp"
using namespace std;
void small(const threadBST&);
void large(const threadBST&);
void median(const threadBST&);
int main(void) {
	int num;
	size_t size;
	threadBST tree;
	vector<int> leftSize;
	cout << "================ START ================" << endl;
	cout << "Size: ";
	cin >> size;
	cout << "Elements: ";
	for (size_t i = 0; i < size; i++) {
		cin >> num;
		tree.add(num);
	}
	leftSize = tree.leftSize();
	cout << "LeftSize: ";
	for (int num: leftSize) {
		cout << num << " ";
	}
	cout << "(Level Order)" << endl;
	while (true) {
		char choice;
		cout << endl << "================ TABLE ================" << endl;
		cout << " [1] Small" << endl;
		cout << " [2] Median" << endl;
		cout << " [3] Large" << endl;
		cout << " ... EXIT" << endl << endl;
		cout << "MODE: ";
		cin.clear();
		cin.ignore();
		cin.get(choice);
		switch(choice) {
			case '1': small(tree);
				break;
			case '2': median(tree);
				break;
			case '3': large(tree);
				break;
			default: cout << endl << "================= END =================" << endl;
				exit(0);
		}
	}
	return 0;
}

void small(const threadBST &tree) {
	int size;
	cout << endl << "=============== 1.Small ===============" << endl;
	cout << "Size: ";
	cin >> size;
	cout << "Average of SMALLEST " << size << " element" << ((size <= 1) ? " :": "s :");
	if ((size <= 0) || (size > tree.size())) {
		cout << -1 << endl;
	} else {
		int total;
		double average;
		for (int i = 1; i <= size; i++) {
			total += tree.intAtRank(-i);
		}
		average = (double)total / (double)size;
		cout << average << endl;
	}
}

void large(const threadBST &tree) {
	int size;
	cout << endl << "=============== 3.Large ===============" << endl;
	cout << "Size: ";
	cin >> size;
	cout << "Average of LARGEST " << size << " element" << ((size <= 1) ? " :": "s :");
	if ((size <= 0) || (size > tree.size())) {
		cout << -1 << endl;
	} else {
		int total;
		double average;
		for (int i = 1; i <= size; i++) {
			total += tree.intAtRank(i);
		}
		average = (double)total / (double)size;
		cout << average << endl;
	}
}

void median(const threadBST &tree) {
	cout << endl << "============== 2. Median ==============" << endl;
	if (tree.size() % 2 == 0) {
		int rank = tree.size() / 2;
		int total = tree.intAtRank(rank) + tree.intAtRank(rank + 1);
		double average = (double)total / 2.0;
		cout << "Average of MEDIAN elements: " << average << endl;
	} else {
		int rank = tree.size() / 2 + 1;
		cout << "Median element: " << tree.intAtRank(rank) << endl;
	}
}