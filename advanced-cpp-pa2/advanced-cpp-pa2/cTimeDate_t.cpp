#include "cTimeDate_t.h"

const cTime_t& cTimeDate_t::add(const cTime_t& otherTime) {
	cTime_t::add(otherTime);
	if (isAddCarry()) {
		cDate_t::operator+=(1);
	}
	return *this;
}
