#pragma once

#include <iostream>
#include <time.h> 


class cTimeDate_t: public cTime_t, public cDate_t {
public:
	virtual const cTime_t& operator+=(const cTime_t&);
}

