#include "cTime_t.h"

using namespace std;

cTime_t::cTime_t():format(DEFAULT_FORMAT),addCarry(false) {
	time_t 	time_date = time(0);
	current_time = *localtime(&time_date);
}

cTime_t::cTime_t(const cTime_t& otherTime):addCarry(false) {
	setTime(otherTime.getHour(), otherTime.getMinute(), otherTime.getSecond());
	format = otherTime.getFormat();
}

cTime_t::cTime_t(const int& hour, const int& minutes, const int& seconds):format(DEFAULT_FORMAT),addCarry(false) {
	setTime(hour,minutes,seconds); // We let the CTOR throw the exception
}

const cTime_t& cTime_t::operator=(const cTime_t& otherTime) {
	if (this != &otherTime) {
		setTime(otherTime.getHour(), otherTime.getMinute(), otherTime.getSecond());
		setFormat(otherTime.getFormat());
	}
	return *this;
}

ostream& operator<<(ostream& os, const cTime_t& t) {
	if (t.getFormat() == 1) {
		return os << t.getHour() << ":" << t.getMinute() << ":" << t.getSecond() << endl;
	} else {
		int formatedHour = t.getHour();
		string str = "AM";
		if (formatedHour > 12) {
			formatedHour -= 12;
			str = "PM";
		}
		return os << formatedHour << ":" << t.getMinute() << ":" << t.getSecond() << " " << str << endl;
	}
}

const cTime_t& cTime_t::operator+=(const cTime_t& otherTime) {
	int newSec = getSecond() + otherTime.getSecond();
	int carry = (newSec >= 60) ? 1 : 0;
	int newMin = getMinute() + otherTime.getMinute() + carry;
	carry = (newMin >= 60) ? 1 : 0;
	int newHour = getHour() + otherTime.getHour() + carry;
	addCarry = (newMin >= 24) ? true : false;
	setTime(newHour % 24, newMin % 60, newSec % 60);
	return *this;
}

void cTime_t::setTime(const int& hour, const int& minutes, const int& seconds) throw(const char*) {
	if (hour < 0 || hour >= 24 || minutes < 0 || minutes >= 60 || seconds < 0 || seconds >= 60) {
		throw ("Illegal arguments");
	}
	current_time.tm_hour = hour;
	current_time.tm_min = minutes;
	current_time.tm_sec = seconds;
}

void cTime_t::setFormat(const int& new_format) throw(const char*) {
	if (new_format != 1 && new_format != 2) {
		throw ("Illegal arguments");
	}
	format = new_format;
}

void cTime_t::printTime(const int& format) {
	setFormat(format);
	cout << *this;
}


