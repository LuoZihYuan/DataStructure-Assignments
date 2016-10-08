#include <iostream>
#include "myString.hpp"
using namespace std;
int main(void) {
	myString a = "123";
	myString b = "123";
	if(a==b) {
		cout << "false" << endl;
	}
	return 0;
}