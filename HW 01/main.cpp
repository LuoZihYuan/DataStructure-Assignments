#include <iostream>
#include <string>
#include "myDirtyString.hpp"
using namespace std;
int main(void) {
	myDirtyString a = "12312", b = "12";
	occur c = a.freq(b);
	cout << c.count << endl;
	return 0;
}