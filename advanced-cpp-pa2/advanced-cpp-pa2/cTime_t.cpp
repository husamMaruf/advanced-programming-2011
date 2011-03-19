#include "cTime_t.h"

using namespace std;

cTime_t::cTime_t() {
	time_t 	time_date = time(0);
	current_time = new tm(*localtime(&time_date));
	format = DEFAULT_FORMAT;
}

cTime_t::cTime_t(const cTime_t& otherTime) {
	current_time = new tm;
	setTime(otherTime.getHour(), otherTime.getMinute(), otherTime.getSecond());
	format = otherTime.getFormat();
}

cTime_t::cTime_t(const int& hour, const int& minutes, const int& seconds) {
	current_time = new tm;
	setTime(hour,minutes,seconds);
	format = DEFAULT_FORMAT;
}

cTime_t::~cTime_t() {
	delete current_time;
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
		string str;
		if (formatedHour > 12) {
			formatedHour -= 12;
			str = "PM";
		} else {
			str = "AM";
		}
		return os << formatedHour << ":" << t.getMinute() << ":" << t.getSecond() << " " << str << endl;
	}
}

const cTime_t& cTime_t::operator+=(const cTime_t& otherTime) {
	setTime((getHour() + otherTime.getHour()) % 24, 
			(getMinute() + otherTime.getMinute()) % 60, 
			(getSecond() + otherTime.getSecond()) % 60);
	return *this;
}

void cTime_t::setTime(const int& hour, const int& minutes, const int& seconds) {
	current_time->tm_hour = hour;
	current_time->tm_min = minutes;
	current_time->tm_sec = seconds;
}

void cTime_t::setFormat(const int& new_format) {
	if (new_format >= 1 && new_format <= 2) {
		format = new_format;
	}
}

void cTime_t::printTime(const int& format) {
	setFormat(format);
	cout << *this;
}

//TEST PROGRAM
int main( int argc, char *argv[] ) {
	cTime_t t1;
	cout << t1;
	cTime_t t2(8,8,8);
	cout << t2;
	cTime_t t3(t2);
	cout << t3;
	cout << endl;

	t1.printTime(2);
	t2.printTime(2);
	cout << endl;

	cTime_t t4 = t1;
	cout << t4;
	cout << endl;

	t2.printTime(1);
	t2 += t2;
	cout << t2;
	t2 += t2;
	cout << t2;
	t2 += t2;
	cout << t2;
		cout << endl;

	system("Pause");
}
