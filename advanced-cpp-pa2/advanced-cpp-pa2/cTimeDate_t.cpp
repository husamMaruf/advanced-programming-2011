#include "cTime_t.h"
#include "cDate_t.h"


virtual const cTime_t& cTime_t::operator+=(const cTime_t& otherTime) {
	cTime_t::operator+=(therTime);
	if (isAddCarry) {
		cDate_t::operator+=(1);
	}
	return *this;
}
