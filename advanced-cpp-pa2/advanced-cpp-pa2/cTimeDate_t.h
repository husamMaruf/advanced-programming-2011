#pragma once

#include <iostream>
#include <time.h> 
#include "cTime_t.h"
#include "cDate_t.h"

class cTimeDate_t:public cTime_t,public cDate_t {
public:
	virtual const cTime_t& add(const cTime_t& otherTime);
};

