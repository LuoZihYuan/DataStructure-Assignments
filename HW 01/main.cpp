#include <iostream>
#include <string>
#include "myString.hpp"
using namespace std;
int main(void) {
	myString a = "123";
	if(a=="125") {
		cout << "true" << endl;
	}else {
		cout << "false" << endl;
	}
	return 0;
}