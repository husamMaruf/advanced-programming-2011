#include "stdafx.h"
#include <iostream>

using namespace std;

bool safeIntegerInput(int &value) {
	cin >> value;
	if (cin.fail()) {
		cin.clear(); 
		cin.ignore(1000, '\n'); 
		cout << "Bad user input" << endl;
		return false;
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[]) {

	intArray_t arr;

	while(1) {
		cout << "\n| n(numOfElements) | f(first) | l(last) | e(empty) | c(capacity) |";
		cout << "\n  i(insert) | r(remove) | R(removeAll) | A(append) |";
		cout << "\n  P(prepend) | <(print) | d(removeAndDelete) | D(removeAndDelete) : ";
		char c;
		cin >> c;

		if (c!='n' && c!='f' && c!='l' && c!='e' && c!='i' && c!='r' && c!='R' && c!='<' && c!='A' && c!='P' && c!='c' 
			&& c!='d' && c!='D')   
			break;
		int* val = new int;
		int value;
		int succ;
		int index;
		switch (c) {
			case 'n' : 
				cout << arr.numOfItems() << endl; 
				break;
			case 'f' :  
				if (!arr.isEmpty()) {
					cout << *arr.first() << endl;   
				} else {
					cout << "Array is empty" << endl;
				}
				break;
			case 'l' : 
				if (!arr.isEmpty()) { 
					cout << *arr.last() << endl;
				} else {
					cout << "Array is empty" << endl;
				}
				break;
			case 'c':
				cout << arr.capacity() << endl;
				break;
			case 'e' : 
				cout << (arr.isEmpty() ? "Empty" : "Not empty") << endl; 
				break;
			case 'i' :  
				cout << "Enter int value:" << endl; 
				if (safeIntegerInput(*val)) {
					arr.insert(val);
					cout << "Put " << *val << " in array" << endl;
				} 
				break;
			case 'r' :  
				cout << "Enter int value to remove:" << endl; 
				if (safeIntegerInput(value)) {
					cout << "Removed:" << *arr.remove(value) << endl;
				} 
				break;
			case 'R' :  
				arr.removeAll();
				cout << "Removed all" << endl;
				break;
			case 'A' :  
				cout << "Enter int index followed by an int value:" << endl; 
				if (safeIntegerInput(index) && safeIntegerInput(*val)) {
					succ = arr.append(index,val);
					cout << (succ ? "Success" : "Failed") << endl;
				} 				
				break;
			case 'P' : 
				cout << "Enter int index followed by an int value:" << endl; 
				if (safeIntegerInput(index) && safeIntegerInput(*val)) {
					succ = arr.prepend(index,val);
					cout << (succ ? "Success" : "Failed") << endl;
				} 
				break;
			case 'd':
				cout << "Enter int value to remove and delete:" << endl; 
				if (safeIntegerInput(value)) {
					succ = arr.removeAndDelete(value);
					cout << (succ ? "Success" : "Failed") << endl;
				} 
				break;
			case 'D':
				arr.removeAndDeleteAll();
				cout << "Removed and deleted all elements in array" << endl;
				break;
			case '<' : 
				cout << arr << endl;
				break;
			default :
				continue;
		}
	}

	return 0;
}

