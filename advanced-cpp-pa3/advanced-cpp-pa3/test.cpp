#include "common.h"
#include "memPage_t.h"
#include "memPool_t.h"
#include <iostream>

using namespace std;

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
	}
}

int main(int argc, char *argv[]) {
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

