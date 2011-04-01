#include "common.h"
#include "memPage_t.h"
#include "memPool_t.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class DataContainer {
public:
	DataContainer(int _id, char _ch) : id(_id), ch(_ch) { }
	~DataContainer() { }
	const int& getId() const { return id; }
	const char getChar() const { return ch; }
private:
	int id;
	char ch;
};

enum entryType {
	INT,DOUBLE,CHAR,DATA_CONTAINER
};

struct poolEntry {
	int entrySize;
	int position;
	entryType type;
};

void handleException(const int& e) {
	switch (e) {
		case memPage_t::ILLEGAL_POSITION:
			cout << "ILLEGAL POSITION" << endl;
			break;
		case memPage_t::ILLEGAL_PAGE_SIZE:
			cout << "ILLEGAL PAGE SIZE" << endl;
			break;
		case memPage_t::ILLEGAL_READ_SIZE:
			cout << "ILLEGAL READ SIZE" << endl;
			break;
		case memPage_t::ILLEGAL_WRITE_SIZE:
			cout << "ILLEGAL WRITE SIZE" << endl;
			break;
		case memPool_t::ILLEGAL_NUMBER_OF_PAGES:
			cout << "ILLAGAL NUMBER OF PAGES" << endl;
			break;
		case memPool_t::ILLEGAL_POSITION:
			cout << "ILLGAL POSITION" << endl;
			break;
	}
}

void test1() {

	int n;
	cout << "Entry start pages size" << endl;
	cin >> n;
	if (n<1) {
		cout << "Bad choice... better luck next time" << endl;
	}
	memPool_t::setDefaultPageSize(n);

	vector<poolEntry*> entries;
	memPool_t pool;
	char answer;
	bool quit = false;

	int intType;
	double doubleType;
	int id = 0;
	char ch = 'd';
	DataContainer containerType(id, ch);
	DataContainer* container;
	char charType;
	while (!quit) {
		cout << "Make your choice:" << endl;
		cout << "[r] read" << endl;
		cout << "[w] write" << endl;
		cout << "[a] actual_size" << endl; 
		cout << "[c] capacity" << endl;
		cout << "[n] num_of_pages" << endl;
		cout << "[e] is_empty" << endl;
		cout << "[s] set_page_size" << endl; 
		cout << "[p] create_pages" << endl;
		cout << "[q] quit" << endl;
		cin >> answer;
		switch (answer) {
			case 'r':
				cout << "choose entry number (in list)" << endl;
				cin >> n;
				try {
					if (n < 0 || n > entries.size()-1) {
						cout << "n is too big or too small" << endl;
						continue;
					}

					poolEntry* entry = entries[n];

					pool.setCurrentPosition(entry->position);
					int size = entry->entrySize;

					switch(entry->type) {
						case INT:
							pool.read(intType,size);
							cout << "Read: " << intType << endl;
							break;
						case DOUBLE:
							pool.read(doubleType, size);
							cout << "Read: " << doubleType << endl;
							break;
						case CHAR:
							pool.read(charType, size);
							cout << "Read: " << charType << endl;
							break;
						case DATA_CONTAINER:
							pool.read(containerType, size);
							cout << "Read: DataContainer(" << containerType.getId() << "," << containerType.getChar() << ")" << endl;
							break;
					}

				} catch (const int& e) {
					handleException(e);
				}
				break;
			case 'w':
				cout << "choose type:" << endl;
				cout << "[1] int" << endl;
				cout << "[2] double" << endl;
				cout << "[3] char" << endl;
				cout << "[4] data container" << endl;
				cin >> n;
				try {
					poolEntry* entry = new poolEntry;
					entry->position = pool.getCurrentPosition();
					entries.push_back(entry);
					cout << "write value:" << endl;
					switch (n) {
						case 1:
							cin >> intType;
							entry->entrySize = sizeof(int);
							entry->type = INT;
							pool.write(intType,sizeof(int));
							break;
						case 2:
							cin >> doubleType;
							entry->entrySize = sizeof(double);
							entry->type = DOUBLE;
							pool.write(doubleType,sizeof(double));
							break;
						case 3:
							cin >> charType;
							entry->entrySize = sizeof(char);
							entry->type = CHAR;
							pool.write(charType,sizeof(char));
							break;
						case 4:
							entry->entrySize = sizeof(DataContainer);
							entry->type = DATA_CONTAINER;
							cout << "write id: (should be int)" << endl;
							cin >> id;
							cout << "write char:" << endl;
							cin >> ch;
							container = new DataContainer(id,ch);
							pool.write(*container, sizeof(DataContainer));
							delete container;
						default:
							cout << "Enter a valid number" << endl;
							continue;
					}
				} catch (const int& e) {
					handleException(e);
				}
				break;
			case 'a':
				cout << "Actual size: " << pool.getActualSize() << endl;
				break;
			case 'c':
				cout << "Capacity: " << pool.getCapacity() << endl;
				break;
			case 'n':
				cout << "Num of pages: " << pool.getNumOfPages() << endl;
				break;
			case 'e':
				cout << "Is empty: " << pool.isEmpty() << endl;
				break;
			case 's':
				cout << "choose page size: " << endl;
				cin >> n;
				try {
					pool.setDefaultPageSize(n);
				} catch (const int& e) {
					handleException(e);
				}
				break;
			case 'p':
				cout << "choose num of pages to create: " << endl;
				cin >> n;
				pool.createPages(n);
				break;
			case 'q':
				quit = true;
				break;
			default:
				quit = true;
		}
	}
}

void test2() {
	memPool_t pool;
	char answer;
	bool quit = false;
	int n;
	int intType;
	double doubleType;
	char charType;
	while (!quit) {
		cout << "r:read , w:write , a:actual_size , c:capacity , n:num_of_pages , e:is_empty , s:set_page_size, p:create_pages , q:quit" << endl;
		cin >> answer;
		switch (answer) {
			case 'r':
				cout << "choose type: 1 - int , 2 - double , 3 - char" << endl;
				cin >> n;
				try {
					switch (n) {
						case 1:
							pool.read(intType,sizeof(int));
							cout << "result: " << intType << endl;
							break;
						case 2:
							pool.read(doubleType,sizeof(double));
							cout << "result: " << doubleType << endl;
							break;
						case 3:
							pool.read(charType,sizeof(char));
							cout << "result: " << charType << endl;
							break;
					}
				} catch (const int& e) {
					handleException(e);
				}
				break;
			case 'w':
				cout << "choose type: 1 - int , 2 - double , 3 - char" << endl;
				cin >> n;
				try {
					cout << "write value:" << endl;
					switch (n) {
						case 1:
							cin >> intType;
							pool.write(intType,sizeof(int));
							break;
						case 2:
							cin >> doubleType;
							pool.write(doubleType,sizeof(double));
							break;
						case 3:
							cin >> charType;
							pool.write(charType,sizeof(char));
							break;
					}
				} catch (const int& e) {
					handleException(e);
				}
				break;
			case 'a':
				cout << "Actual size: " << pool.getActualSize() << endl;
				break;
			case 'c':
				cout << "Capacity: " << pool.getCapacity() << endl;
				break;
			case 'n':
				cout << "Num of pages: " << pool.getNumOfPages() << endl;
				break;
			case 'e':
				cout << "Is empty: " << pool.isEmpty() << endl;
				break;
			case 's':
				cout << "choose page size: " << endl;
				cin >> n;
				try {
					pool.setDefaultPageSize(n);
				} catch (const int& e) {
					handleException(e);
				}
				break;
			case 'p':
				cout << "choose num of pages to create: " << endl;
				cin >> n;
				pool.createPages(n);
				break;
			case 'q':
				quit = true;
				break;
			default:
				quit = true;
		}
	}
}

int main(int argc, char *argv[]) {
	
	char choice;
	
	cout << "Which test to run?" << endl;
	cout << "[1] memPool manual test" << endl;
	cout << "[2] memPool manual test2" << endl;

	cin >> choice;

	switch(choice) {
		case '1':
			test1();
			break;
		case '2':
			test2();
			break;
		default:
			cout << "Bad choice, better luck next time" << endl;
			break;
	}

	system("PAUSE");
}

