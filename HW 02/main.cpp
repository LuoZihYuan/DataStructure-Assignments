#include <iostream>
#include "serviceQueue.hpp"
using namespace std;
int main(void) {
	baseClient a[10];
	serviceQueue nov20;
	cout << "INPUT:" << endl;
	cout << "1. type in 3 seperate times for each client at once" << endl;
	cout << "2. seperate each time by space" << endl;
	cout << "3. type in negative time to end input" << endl;
	cout << "format: [Arrival time] [Service time] [Allowable waiting time]" << endl << endl;
	for(int i = 0; i < 10; i++) {
		cout << "Client" << ((i != 9)? "  ": " ") << i+1 << ": ";
		cin >> a[i];
		if(a[i].arrival_time < 0 || a[i].service_time <= 0 || a[i].waiting_time < 0)
			break;
		nov20.add(&a[i]);
	}
	cout << endl << "OUTPUT:" << endl;
	cout << "           Served or not? | Departure time" << endl;
	for(int i = 0; i < 10; i++) {
		if(a[i].arrival_time >= 0 && a[i].service_time >= 0 && a[i].waiting_time >= 0) {
			cout << "Client" << ((i != 9)? "  ": " ") << i+1 << ": ";
			if(a[i].isServed()) {
				cout << "YES            | " << a[i].getDepartureTime() << endl;
			} else
				cout << "NO             | -" << endl;
		} else
			break;
	}
	cout << endl;
	return 0;
}