#include "baseClient.hpp"
/* Constructor */
baseClient::baseClient() {
	served = false;
	departure_time = -1;
	// identifier = "";
	arrival_time = -1;
	service_time = -1;
	waiting_time = -1;
}
baseClient::baseClient(const baseClient &cli) {
	served = cli.served;
	departure_time = cli.departure_time;
	// identifier = cli.identifier;
	arrival_time = cli.arrival_time;
	service_time = cli.service_time;
	waiting_time = cli.waiting_time;
}
baseClient::baseClient(const time_t &arrival, const time_t &service, const time_t &wait) {
	arrival_time = arrival;
	service_time = service;
	waiting_time = wait;
}
// baseClient::baseClient(const std::string &id, const time_t &arrival, const time_t &service, const time_t &wait) {
// 	identifier = id;
// 	arrival_time = arrival;
// 	service_time = service;
// 	waiting_time = wait;
// }
/* Destructor */
baseClient::~baseClient() {
	// identifier.clear();
}
/* overload operator = */
baseClient& baseClient::operator= (const baseClient &cli) {
	served = cli.served;
	departure_time = cli.departure_time;
	// identifier = cli.identifier;
	arrival_time = cli.arrival_time;
	service_time = cli.service_time;
	waiting_time = cli.waiting_time;
	return *this;
}
/* overload operator << */
std::ostream& operator<< (std::ostream &os, const baseClient &cli) {
	// os << "Identifier: " << cli.identifier << std::endl;
	os << "Arrival Time: " << cli.arrival_time << std::endl;
	os << "Service Time: " << cli.service_time << std::endl;
	os << "Waiting Time: " << cli.waiting_time << std::endl;
	return os;
}
/* overload operator >> */
std::istream& operator>> (std::istream &is, baseClient &cli) {
	is >> cli.arrival_time >> cli.service_time >> cli.waiting_time;
	// is >> cli.identifier >> cli.arrival_time >> cli.service_time >> cli.waiting_time;
	return is;
}
// std::istream& getline (std::istream &is, baseClient &cli) {
// 	getline(is, cli.identifier);
// 	is >> cli.arrival_time >> cli.service_time >> cli.waiting_time;
// 	return is;
// }
/* baseClient.isServed() */
bool baseClient::isServed() {
	return served;
}
/* baseClient.getDepartureTime() */
time_t baseClient::getDepartureTime() {
	return departure_time;
}
/* baseClient.clear() */
void baseClient::clear() {
	served = false;
	departure_time = -1;
	// identifier.clear();
	arrival_time = -1;
	service_time = -1;
	waiting_time = -1;
}