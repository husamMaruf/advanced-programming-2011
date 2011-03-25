#pragma once

#include <iostream>
#include <time.h> 
#include "cTime_t.h"
#include "cDate_t.h"

class cTimeDate_t:public cTime_t,public cDate_t {
public:
	const cTime_t& operator+=(const cTime_t&);
}

