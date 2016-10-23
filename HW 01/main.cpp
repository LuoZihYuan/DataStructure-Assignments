#include <iostream>
#include <string>
#include "myString.hpp"
using namespace std;
int main(void) {
	myString a = "123", b = "456";
	a = b;
	cout << a[0] << endl;
	return 0;
}