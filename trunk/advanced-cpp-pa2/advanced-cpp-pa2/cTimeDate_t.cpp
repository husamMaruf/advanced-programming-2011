#include "cTime_t.h"
#include "cDate_t.h"


virtual const cTime_t& cTimeDate_t::operator+=(const cTime_t& otherTime) {
	cTime_t::operator+=(otherTime);
	if (isAddCarry()) {
		cDate_t::operator+=(1);
	}
	return *this;
}
