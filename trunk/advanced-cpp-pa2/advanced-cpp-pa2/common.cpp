#include "common.h"

string pad(const int& num) {
	ostringstream buffer;
	buffer << ((num < 10) ? "0" : "") << num;
	return buffer.str();
}