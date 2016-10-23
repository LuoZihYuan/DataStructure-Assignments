#include <iostream>
#include <string>
#include "myDirtyString.hpp"
using namespace std;
int main(void) {
	myDirtyString a = "ababacd cdefghcda";
	char b = 'a';
	cout << a.del(b) << endl;
	return 0;
}