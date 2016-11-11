#include <iostream>
#include "serviceQueue.hpp"
using namespace std;
int main(void) {
	client a;
	a.client_name = "1235";
	a.arrival_time = 1;
	a.service_time = 2;
	a.waiting_time = 3;
	client b = a;
	cout << b << endl;
	return 0;
}