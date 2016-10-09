#include <iostream>
#include "myString.hpp"
#include <string>
using namespace std;
int main(void) {
	string a = "111";
	cout << a.replace(-1, 1, "23", 5) << endl;
	return 0;
}