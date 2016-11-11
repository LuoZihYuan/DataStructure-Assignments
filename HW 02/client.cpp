#include "client.hpp"
/* Constructor */
client::CLIENT() {
}
client::CLIENT(const CLIENT &cli) {
	client_name = cli.client_name;
	arrival_time = cli.arrival_time;
	service_time = cli.service_time;
	waiting_time = cli.waiting_time;
}
client::CLIENT(const std::string &name, const int &arrival, const int &service, const int &wait) {
	client_name = name;
	arrival_time = arrival;
	service_time = service;
	waiting_time = wait;
}
/* Destructor */
client::~CLIENT() {
	client_name.clear();
}
/* overload operator << */
std::ostream& operator<< (std::ostream &os, const CLIENT &cli) {
	os << "CLIENT NAME: " << cli.client_name << std::endl;
	os << "Arrival Time: " << cli.arrival_time << std::endl;
	os << "Service Time: " << cli.service_time << std::endl;
	os << "Waiting Time: " << cli.waiting_time << std::endl;
	return os;
}
/* overload operator >> */
std::istream& operator>> (std::istream &is, CLIENT &cli) {
	is >> cli.client_name >> cli.arrival_time >> cli.service_time >> cli.waiting_time;
	return is;
}
std::istream& getline (std::istream &is, CLIENT &cli) {
	getline(is, cli.client_name);
	is >> cli.arrival_time >> cli.service_time >> cli.waiting_time;
	return is;
}
/* client.clear() */
void client::clear() {
	client_name.clear();
	arrival_time = 0;
	service_time = 0;
	waiting_time = 0;
}