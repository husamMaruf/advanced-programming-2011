#include "cDate_t.h"
#include "cTime_t.h"
#include "cTimeDate_t.h"

using namespace std;

//TEST PROGRAM
int cTime_t_main(int argc, char *argv[]) {
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

	return 0;
}

int main(int argc, char *argv[]) {
	//return cTime_t_main(argc,argv);

	cTimeDate_t timedate;
	
	cTime_t time(23,59,59);
	
	cout << timedate << endl;

	timedate += time;

	cout << timedate << endl;

	int i;
	cin >> i;

}