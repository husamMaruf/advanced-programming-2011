#pragma once

#include <iostream>
#include <time.h> 
#include "cTime_t.h"
#include "cDate_t.h"

class cTimeDate_t:public cTime_t,public cDate_t {
public:
	//cTimeDate_t(); // Default CTOR that calls cTime_t and cDate_t default CTOR
	//~cTimeDate_t(); // Default DTOR because we don't allocate memory on heap
	virtual const cTimeDate_t& add(const cTime_t& otherTime) throw(int);
	const cTimeDate_t& operator+=(const cTime_t&);
};

ostream& operator<<(ostream& os, const cTimeDate_t& t);