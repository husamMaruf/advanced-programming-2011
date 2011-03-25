#pragma once
#include <time.h>
#include <iostream>
#include <string>

using namespace std;

#define DEFAULT_FORMAT 1

class cTime_t {
public:
	cTime_t();
	cTime_t(const cTime_t&);
	cTime_t(const int& hour, const int& minutes, const int& seconds) throw(const char*);
	//~cTime_t(); // Default DTOR because we don't allocate memory on heap
	const cTime_t& operator=(const cTime_t&);
	const cTime_t& operator+=(const cTime_t&);
	void setTime(const int& hour, const int& minutes, const int& seconds) throw(const char*);
	void printTime(const int& format);
	const int& getHour() const { return current_time.tm_hour; }
	const int& getMinute() const { return current_time.tm_min; }
	const int& getSecond() const { return current_time.tm_sec; }
	const int& getFormat() const { return format; }
	void setFormat(const int& new_format) throw(const char*);
	const bool& isAddCarry() const { return addCarry; }
	virtual const cTime_t& add(const cTime_t& otherTime) { return operator+=(otherTime); }
private:
	int format;
	bool addCarry;
	struct tm current_time;
};

ostream& operator<<(ostream& os, const cTime_t&);
