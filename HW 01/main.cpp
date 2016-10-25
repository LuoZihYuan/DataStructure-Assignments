#include <iostream>
#include <string>
#include "myString.hpp"
using namespace std;
int main(void) {
	myString a = "banana*ananab", b = "b";
	cout << a.del(b) << endl;
	return 0;
}