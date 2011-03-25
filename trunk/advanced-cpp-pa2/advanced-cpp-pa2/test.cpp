#include "cDate_t.h"
#include "cTime_t.h"
#include "cTimeDate_t.h"

using namespace std;

void cTime_t_test() {
	cTime_t tArr[2];
	char answer;
	int choice;
	bool quit = false;
	while (!quit) {
		cout << "n:new , a:add , s:set , p:print , q:quit" << endl;
		cin >> answer;
		switch (answer) {
			case 'n':
				cout << "choose t var to apply on (1 or 2):" << endl;
				cin >> choice;
				choice--;
				int n;
				cout << "choose CTOR: 1 - reg , 2 - Copy CTOR , 3 - Set time CTOR:" << endl;
				cin >> n;
				switch (n) {
					case 1:
						tArr[choice] = cTime_t();
						break;
					case 2:
						tArr[choice] = cTime_t(tArr[(choice+1)%2]);
						break;
					case 3:
						int hour;
						int min;
						int sec;
						cout << "choose hour:" << endl;
						cin >> hour;
						cout << "choose min:" << endl;
						cin >> min;
						cout << "choose sec:" << endl;
						cin >> sec;
						try {
							tArr[choice] = cTime_t(hour,min,sec);
						} catch (const char* e) {
							cout << e << endl;
						}
						break;
				}
				break;
			case 'a':
				cout << "choose t var to apply on (1 or 2):" << endl;
				cin >> choice;
				tArr[choice] += tArr[(choice+1)%2];
				break;
			case 's':
				cout << "choose t var to apply on (1 or 2):" << endl;
				cin >> choice;
				int hour;
				int min;
				int sec;
				cout << "choose hour:" << endl;
				cin >> hour;
				cout << "choose min:" << endl;
				cin >> min;
				cout << "choose sec:" << endl;
				cin >> sec;
				try {
					tArr[choice].setTime(hour,min,sec);	
				} catch (const char* e) {
					cout << e << endl;
				}
				break;
			case 'p':
				cout << "choose t var to apply on (1 or 2):" << endl;
				cin >> choice;
				int format;
				cout << "choose format:" << endl;
				cin >> format;
				tArr[choice].printTime(format);
				break;
			case 'q':
				quit = true;
				break;
			default:
				quit = true;
		}
	}
}

void cDate_t_test() {
	cDate_t* dArr[2];
	dArr[0] = new cDate_t();
	dArr[1] = new cDate_t();

	int inc = 1;
	int dec = 1;
	int num = 0;
	int day = 1;
	int month = 1;
	int year = 1970;
	char answer;
	char answer2;
	int choice;
	bool quit = false;
	while (!quit) {
		cout << "c: CTOR, =: Assignemnt Operator, +: Increment, -: Decrement" << endl;
		cout << "s: set, g: info/getters(apply all), p: print, q: quit" << endl;

		cin >> answer;

		switch(answer) {

			case 'c':
				
				cout << "Choose constructor type" << endl;
				cout << "[1] Default" << endl;
				cout << "[2] Copy" << endl;
				cout << "[3] Set date" << endl;

				cin >> answer;

				if (answer != '1' && answer != '2' && answer != '3') {
					cout << "Unsupported operation" << endl;
					continue;
				}

				cout << "Choose which date to construct (1 or 2)" << endl;
				cin >> answer2;

				if (answer2 != '1' && answer2 != '2') {
					cout << "Choose proper date object next time" << endl;
					continue;
				}

				num = answer2 - '1';
				delete dArr[num];

				switch(answer) {
					case '1':
						dArr[num] = new cDate_t();
						cout << "Created with default CTOR" << endl;
						cout << *dArr[num] << endl;
						continue;
					case '2':
						dArr[num] = new cDate_t(*dArr[1-num]);
						cout << "Created with copy CTOR from other date object" << endl;
						cout << *dArr[num] << endl;
						continue;
					case '3':
						cout << "Enter day of month" << endl;
						cin >> day;
						cout << "Enter month" << endl;
						cin >> month;
						cout << "Enter year" << endl;
						cin >> year;

						try {
							dArr[num] = new cDate_t(day,month,year);
							cout << "Created with passed parameters" << endl;
							cout << *dArr[num] << endl;
						} catch (int ex) {
							cout << "error num: " << ex << ", Invalid data params";
						}
						continue;

					default:
						cout << "Unsupported operation" << endl;
						continue;
				}

				continue;
			case '=':
				
				cout << "Choose which object will be the one updated (from the other) (1 or 2)" << endl;
				cin >> answer;
				if (answer != '1' && answer != '2') {
					cout << "Choose proper date object next time" << endl;
					continue;
				}

				num = answer - '1';

				*dArr[num] = *dArr[1-num];

				cout << "Object 1: " << *dArr[0] << endl;
				cout << "Object 2: " << *dArr[1] << endl;

				continue;
			case '+':

				cout << "Choose which object will be the one updated (1 or 2)" << endl;
				cin >> answer;
				if (answer != '1' && answer != '2') {
					cout << "Choose proper date object next time" << endl;
					continue;
				}

				num = answer - '1';

				cout << "choose a positive number to increment by" << endl;
				cin >> inc;

				if (inc < 1) {
					cout << "number is negative" << endl;
					continue;
				}

				try {
					*dArr[num] += inc;
					cout << "Increment date" << endl;
					cout << *dArr[num] << endl;
				} catch (int ex) {
					cout << "Exception num: " << ex << ". date result too big" << endl;
				}

				continue;
			case '-':

				cout << "Choose which object will be the one updated (1 or 2)" << endl;
				cin >> answer;
				if (answer != '1' && answer != '2') {
					cout << "Choose proper date object next time" << endl;
					continue;
				}

				num = answer - '1';

				cout << "choose a positive number to decrement by" << endl;
				cin >> dec;

				if (dec < 1) {
					cout << "number is negative" << endl;
					continue;
				}

				try {
					*dArr[num] -= dec;
					cout << "Decrement date" << endl;
					cout << *dArr[num] << endl;
				} catch (int ex) {
					cout << "Exception num: " << ex << ". date result too small" << endl;
				}

				continue;
			case 's':

				cout << "Choose which object will be the one updated (1 or 2)" << endl;
				cin >> answer;
				if (answer != '1' && answer != '2') {
					cout << "Choose proper date object next time" << endl;
					continue;
				}

				num = answer - '1';

				cout << "Enter day of month" << endl;
				cin >> day;
				cout << "Enter month" << endl;
				cin >> month;
				cout << "Enter year" << endl;
				cin >> year;

				try {
					dArr[num]->setDate(day,month,year);
					cout << "Set with passed parameters" << endl;
					cout << *dArr[num] << endl;
				} catch (int ex) {
					cout << "error num: " << ex << ", Invalid data params" << endl;
				}

				continue;
			case 'g':

				for (int i=0; i<2; i++) {
					cout << "Date " << (i+1) << endl;
					cout << "---------------------------------" << endl;
					cout << "Day: " << dArr[i]->getDay() << endl;
					cout << "Month: " << dArr[i]->getMonth() << endl;
					cout << "Year: " << dArr[i]->getYear() << endl;
					cout << "Day name: " << dArr[i]->getDayName() << endl;
					cout << "Day of year: " << dArr[i]->getDayOfYear() << endl;
					cout << "Month name: " << dArr[i]->getMonthName() << endl;
					cout << "Is leap year? " << (dArr[i]->isLeapYear() ? "true" : "false") << endl;
					cout << endl;
				}

				continue;
			case 'p':

				cout << "Choose print format" << endl;
				cout << "[1] Text" << endl;
				cout << "[2] European" << endl;
				cout << "[3] American" << endl;

				cin >> answer;

				cDate_t::PrintFormat printFormat;

				switch(answer) {
					case '1':
						printFormat = dArr[0]->Text;
						break;
					case '2':
						printFormat = dArr[0]->European;
						break;
					case '3':
						printFormat = dArr[0]->American;
						break;
					default:
						cout << "Unsupported operation" << endl;
						continue;
				}

				dArr[0]->setPrintFormat(printFormat);
				dArr[1]->setPrintFormat(printFormat);

				cout << *dArr[0] << endl;
				cout << *dArr[1] << endl;

				continue;
			case 'q':
				quit = true;
				continue;

		}
	}
}

void cTimeDate_t_test() {

	cTimeDate_t timedate;

	int sec;
	int min;
	int hour;

	cout << "Current timedate object state: " << endl;
	cout << timedate << endl;
	cout << endl;

	cout << "Enter seconds to increment" << endl;
	cin >> sec;
	cout << "Enter minutes to increment" << endl;
	cin >> min;
	cout << "Enter hours to increment" << endl;
	cin >> hour;

	cTime_t time(hour,min,sec);

	cout << "Generated time object to be added to timedate: " << time << endl;

	timedate += time;

	cout << "Timedate object after incrementing" << endl;

	cout << timedate << endl;

	system("Pause");

}

int main(int argc, char *argv[]) {

	cout << "Choose type of test program to run:" << endl;
	cout << "[1] cTime_t test" << endl;
	cout << "[2] cDate_t test" << endl;
	cout << "[3] cTimeDate_t test" << endl;

	char choice;
	cin >> choice;

	switch(choice) {
		case '1': 
			cTime_t_test();
			break;
		case '2':
			cDate_t_test();
			break;
		case '3':
			cTimeDate_t_test();
			break;
		default:
			cout << "Unsupported option" << endl;
			break;
	}

}