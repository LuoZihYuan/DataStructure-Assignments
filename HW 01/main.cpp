#include <iostream>
#include <string>
#include "baseString.hpp"
using namespace std;
int main(void) {
	baseString a = "123", b = "abc";
	cout << a.replace(1, 1, b, 1, -1) << endl;
	return 0;
}