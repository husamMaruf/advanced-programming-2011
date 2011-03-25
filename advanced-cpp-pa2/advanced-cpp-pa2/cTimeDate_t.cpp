#include "cTimeDate_t.h"

const cTimeDate_t& cTimeDate_t::add(const cTime_t& otherTime) {
	cTime_t::add(otherTime);
	if (isAddCarry()) {
		cDate_t::operator+=(1);
	}
	return *this;
}

const cTimeDate_t& cTimeDate_t::operator+=(const cTime_t& otherTime) {
	return add(otherTime);
}

ostream& operator<<(ostream& os, const cTimeDate_t& t) {
	return os << cTime_t(t) << cDate_t(t) ;
}