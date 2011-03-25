#include "cDate_t.h"

const char* cDate_t::monthNames[] = { 
	"January", "February", "March", "April", 
	"May", "June", "July", "August", 
	"September", "October", "November", "December" 
};

const char* cDate_t::dayNames[] = { 
	"Sunday", "Monday", "Tuesday", 
	"Wednesday", "Thursday", "Friday", 
	"Saturday" 
};

const cDate_t::PrintFormat cDate_t::DEFAULT_PRINT_FORMAT = European;

void cDate_t::defaultInit() {
	time_t time_date = time(0);
	current_time = *localtime(&time_date);
}

cDate_t::cDate_t() : printFormat(DEFAULT_PRINT_FORMAT) {
	defaultInit();
} 

cDate_t::cDate_t(const cDate_t& cDate) {
	current_time = cDate.current_time;
	printFormat = cDate.printFormat;
}

// if passed parameters are illegal, default date object will be constructed (current date)
cDate_t::cDate_t(int day, int month, int year) throw(int) : printFormat(DEFAULT_PRINT_FORMAT) {

	// this is needed so mktime (in setDate) will work properly
	defaultInit();

	setDate(day,month,year);

}

const cDate_t& cDate_t::operator=(const cDate_t& cDate) {
	if (this != &cDate) {
		current_time = cDate.current_time;
	}

	return *this;
}

const cDate_t& cDate_t::operator+=(int increment) throw(int) {
	if (increment < 0) {
		throw ILLEGAL_INCREMENT_VALUE;
	}
	
	struct tm backup = current_time;
	
	current_time.tm_mday += increment;
	time_t result = mktime(&current_time);
	if (result == -1) {
		current_time = backup;
		throw OPERATION_BOUND_ERROR;
	}
}

const cDate_t& cDate_t::operator-=(int decrement) throw(int) {
	if (decrement < 0) {
		throw ILLEGAL_DECREMENT_VALUE;
	}

	struct tm backup = current_time;

	current_time.tm_mday -= decrement;
	time_t result = mktime(&current_time);
	if (result == -1) {
		current_time = backup;
		throw OPERATION_BOUND_ERROR;
	}
}


// throws an exception if one of the date parameters is illegal
// restores previous state of date object
void cDate_t::setDate(int day, int month, int year) throw(int) {

	if (day < 1 || month < 1 || month > 12 || year < 1970 || year > 3000) {
		throw ILLEGAL_DATE_PARAMS;
	}

	bool illegalDay = false;
	if (month == 2) {
		if (year % 4 == 0) {
			illegalDay = day > 29;
		} else {
			illegalDay = day > 28;
		}
	} else if (month == 4 || month == 6 || month == 9 || month == 11) {
		illegalDay = day > 30;
	} else {
		illegalDay = day > 31;
	}

	if (illegalDay) {
		throw ILLEGAL_DATE_PARAMS;
	}

	struct tm backup = current_time;

	current_time.tm_mday = day;
	current_time.tm_mon = month - 1;
	current_time.tm_year = year - 1900;
	time_t result = mktime(&current_time);
	if (result == -1) {
		current_time = backup;
		throw ILLEGAL_DATE_PARAMS;
	} 

}

int cDate_t::getCurrentDay() const {
	return current_time.tm_mday; 
}

int cDate_t::getCurrentMonth() const {
	return current_time.tm_mon+1;
}

int cDate_t::getCurrentYear() const {
	return current_time.tm_year+1900;
}

int cDate_t::getDayOfYear() const {
	return current_time.tm_yday+1;
}

bool cDate_t::isLeapYear() const {
	return getCurrentYear() % 4 == 0;
}

const char* cDate_t::getDayName() const {
	return dayNames[current_time.tm_wday];
}

const char* cDate_t::getMonthName() const {
	return monthNames[current_time.tm_mon];
}

void cDate_t::printDate(PrintFormat format) {
	setPrintFormat(format);
	cout << *this;	
}

void cDate_t::setPrintFormat(PrintFormat format) {
	printFormat = format;
}

cDate_t::PrintFormat cDate_t::getPrintFormat() const {
	return printFormat;
}

ostream& operator<<(ostream& os, const const cDate_t& cDate) {
	bool padDay = (cDate.current_time.tm_mday < 10);
	bool padMonth = (cDate.current_time.tm_mon+1 < 10);
	
	if (cDate.printFormat == cDate.Text) {
		os << (padDay ? "0" : "") << cDate.current_time.tm_mday << '/';
		for (int i=0; i<3; i++) {
			os << cDate.monthNames[cDate.current_time.tm_mon][i];
		}
	} else if (cDate.printFormat == cDate.European) {
		os << (padDay ? "0" : "") << cDate.current_time.tm_mday << '/';
		os << (padMonth ? "0" : "") << cDate.current_time.tm_mon+1;
	} else { // cDate.printFormat == American
		os << (padMonth ? "0" : "") << cDate.current_time.tm_mon+1 << '/';
		os << (padDay ? "0" : "") << cDate.current_time.tm_mday;
	}

	os << '/' << cDate.current_time.tm_year+1900;

	return os;
}

void main2(void) {



}