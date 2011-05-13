#pragma once

#include <iostream>
#include <time.h> 
#include <string>
#include <sstream>

using namespace std;

class cDate_t {
public:

	// These values are throw as exceptions from different functions
	static const int ILLEGAL_DATE_PARAMS = 1;
	static const int ILLEGAL_INCREMENT_VALUE = 2;
	static const int ILLEGAL_DECREMENT_VALUE = 3;
	static const int OPERATION_BOUND_ERROR = 4;

	enum PrintFormat {
		Text,
		European,
		American
	};

	cDate_t();
	cDate_t(const cDate_t& cDate);

	// throws ILLEGAL_DATE_PARAMS
	cDate_t(const int& day, const int& month, const int& year) throw(int);
	
	// ~cDate_t(); no extra memory is allocated

	const cDate_t& operator=(const cDate_t& cDate);

	// throws ILLEGAL_INCREMENT_VALUE and OPERATION_BOUND_ERROR
	const cDate_t& operator+=(const int& increment) throw(int);
	
	// throws ILLEGAL_DECREMENT_VALUE and OPERATION_BOUND_ERROR
	const cDate_t& operator-=(const int& decrement) throw(int);

	// throws ILLEGAL_DATE_PARAMS
	void setDate(const int& day, const int& month, const int& year) throw(int);

	const int& getDay() const;
	const int& getMonth() const;
	const int& getYear() const;
	const int& getDayOfYear() const;

	const bool& isLeapYear() const;

	const char* getDayName() const;
	const char* getMonthName() const; 

	void printDate(const PrintFormat& format); // not const because we modify printFormat
	void setPrintFormat(const PrintFormat& format);
	const PrintFormat& getPrintFormat() const;

private:
	
	static const char* monthNames[];
	static const char* dayNames[];
	static const PrintFormat DEFAULT_PRINT_FORMAT;

	void defaultInit();

	friend ostream& operator<<(ostream& os, const cDate_t& cDate);

	struct tm current_time;
	PrintFormat printFormat;

};

string pad(const int& num);