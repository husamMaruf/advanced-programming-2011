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
	try {
		setTime(hour,minutes,seconds);
	} catch(const char* ex) {	
		delete current_time;
		throw;
	}
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
	setTime((getHour() + otherTime.getHour() + carry) % 24, newMin % 60, newSec % 60);
	return *this;
}

void cTime_t::setTime(const int& hour, const int& minutes, const int& seconds) {
	if (hour < 0 || hour >= 24 || minutes < 0 || minutes >= 60 || seconds < 0 || seconds >= 60) {
		throw ("Illegal arguments");
	}
	current_time->tm_hour = hour;
	current_time->tm_min = minutes;
	current_time->tm_sec = seconds;
}

void cTime_t::setFormat(const int& new_format) {
	if (new_format != 1 && new_format != 2) {
		throw ("Illegal arguments");
	}
	format = new_format;
}

void cTime_t::printTime(const int& format) {
	setFormat(format);
	cout << *this;
}

//TEST PROGRAM
int main( int argc, char *argv[] ) {
	//CTOR test:
	cTime_t t1;
	cout << t1;
	cTime_t t2(8,8,8);
	cout << t2;
	cTime_t t3(t2);
	cout << t3;
	cout << endl;

	//Print test:
	t1.printTime(2);
	t2.printTime(2);
	cout << endl;

	//Assignment test:
	cTime_t t4 = t1;
	cout << t4;
	cout << endl;

	//Add test:
	t2.printTime(1);
	t2 += t2;
	cout << t2;
	t2 += t2;
	cout << t2;
	t2 += t2;
	cout << t2;
	cout << endl;

	//Add with carry test:
	cTime_t t5(20,58,59);
	cTime_t t6(0,0,1);
	cTime_t t7(0,0,59);
	cout << t5;
	t5 += t6;
	cout << t5;
	t5 += t7;
	cout << t5;
	t5 += t6;
	cout << t5;
	cout << endl;

	//Exception test:
	try {
		cTime_t t8(26,8,8);
	} catch(const char* ex) {
		cout << ex << endl;
	}

	system("Pause");
}
