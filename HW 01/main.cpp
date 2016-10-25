#include <iostream>
#include <string>
#include "myString.hpp"
using namespace std;
int main(void) {
	occur a;
	for(int i = 0; i < 5; i++) {
		a.push_back(i);
	}
	cout << a << endl;
	return 0;
}