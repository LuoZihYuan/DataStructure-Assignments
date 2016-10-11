#include <iostream>
#include <string>
#include "myDirtyString.hpp"
using namespace std;
int main(void) {
	myDirtyString a = "ababacd cdefgh", b = 'b';
	occur c = a.freq(b);
	cout << c << endl;
	return 0;
}