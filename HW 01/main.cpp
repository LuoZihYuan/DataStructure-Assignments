#include <iostream>
#include "myString.hpp"
using namespace std;
int main(void) {
	myString a = "123";
	a.clear();
	cout << a.size() << endl;
	return 0;
}