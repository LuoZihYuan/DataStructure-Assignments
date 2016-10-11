#include "myDirtyString.hpp"
/* override operator << */
std::ostream& operator<< (std::ostream &os, const occur &status) {
	os << status.count;
	os << " - (";
	if(status.count)
		for(int i = 0; i < status.count; i++) {
			os << status.loc[i];
			if(i != status.count - 1)
				os << ", ";
		}
	os << ")";
	return os;
}

/* myDirtyString.freq() */
occur myDirtyString::freq(char c) {
	occur status;
	char *pch = strchr(string, c);
	while(pch != NULL) {
		status.count += 1;
		int *buffer = status.loc;
		status.loc = new int[status.count];
		memcpy(status.loc, buffer, status.count - 1);
		status.loc[status.count - 1] = (pch - string);
		delete[] buffer;
		pch = strchr(pch + 1, c);
	}
	return status;
}
occur myDirtyString::freq(const char *s) {
	occur status;
	char *pch = strstr(string, s);
	while(pch != NULL) {
		status.count += 1;
		int *buffer = status.loc;
		status.loc = new int[status.count];
		memcpy(status.loc, buffer, status.count - 1);
		status.loc[status.count - 1] = (pch - string);
		delete[] buffer;
		pch = strstr(pch + 1, s);
	}
	return status;
}
occur myDirtyString::freq(const myDirtyString &str) {
	occur status;
	char *pch = strstr(string, str.string);
	while(pch != NULL) {
		status.count += 1;
		int *buffer = status.loc;
		status.loc = new int[status.count];
		memcpy(status.loc, buffer, status.count - 1);
		status.loc[status.count - 1] = (pch - string);
		delete[] buffer;
		pch = strstr(pch + 1, str.string);
	}
	return status;
}
/* myDirtyString.del() */
// myDirtyString& myDirtyString::del(char c) {
// 	return *this;
// }
// myDirtyString& myDirtyString::del(const char *s) {
// 	return *this;
// }
// myDirtyString& myDirtyString::del(const myDirtyString &str) {
// 	return *this;
// }
/* del() */
// myDirtyString del(const myDirtyString &lhs, char rhs) {

// }
// myDirtyString del(const myDirtyString &lhs, const char *rhs) {

// }
// myDirtyString del(const char *lhs, const myDirtyString &rhs) {

// }
// myDirtyString del(const myDirtyString &lhs, const myDirtyString &rhs) {

// }