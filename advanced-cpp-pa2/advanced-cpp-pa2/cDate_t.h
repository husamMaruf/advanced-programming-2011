#pragma once

#include <iostream>
#include <time.h> 

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
	cDate_t(int day, int month, int year) throw(int);
	
	// ~cDate_t(); no extra memory is allocated

	const cDate_t& operator=(const cDate_t& cDate);

	// throws ILLEGAL_INCREMENT_VALUE and OPERATION_BOUND_ERROR
	const cDate_t& operator+=(int increment) throw(int);
	
	// throws ILLEGAL_DECREMENT_VALUE and OPERATION_BOUND_ERROR
	const cDate_t& operator-=(int decrement) throw(int);

	// throws ILLEGAL_DATE_PARAMS
	void setDate(int day, int month, int year) throw(int);

	int getCurrentDay() const;
	int getCurrentMonth() const;
	int getCurrentYear() const;
	int getDayOfYear() const;

	bool isLeapYear() const;

	const char* getDayName() const;
	const char* getMonthName() const; 

	void printDate(PrintFormat format); // not const because we modify printFormat
	void setPrintFormat(PrintFormat format);
	PrintFormat getPrintFormat() const;

private:
	
	static const char* monthNames[];
	static const char* dayNames[];
	static const PrintFormat DEFAULT_PRINT_FORMAT;

	void defaultInit();

	friend ostream& operator<<(ostream& os, const cDate_t& cDate);

	struct tm current_time;
	PrintFormat printFormat;

};

