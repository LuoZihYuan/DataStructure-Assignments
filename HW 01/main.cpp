#include <iostream>
#include <string>
#include "myDirtyString.hpp"
using namespace std;
int main(void) {
	myDirtyString a = "ababacd cdefghcd";
	myDirtyString b = "cd";
	occur c = a.freq(b);
	cout << c << endl;
	return 0;
}