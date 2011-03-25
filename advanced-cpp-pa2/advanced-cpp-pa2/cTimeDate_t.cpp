#include "cTimeDate_t.h"

const cTime_t& cTimeDate_t::operator+=(const cTime_t& otherTime) {
	cTime_t::operator+=(otherTime);
	if (isAddCarry()) {
		cDate_t::operator+=(1);
	}
	return *this;
}
