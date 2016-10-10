#include <iostream>
#include "baseString.hpp"
using namespace std;
int main(void) {
	baseString a = "123";
	a = "456";
	a += "789";
	cout << a << endl;
	return 0;
}