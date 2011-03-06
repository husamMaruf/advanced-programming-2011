#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {

	intArray_t arr;

	while(1) {
		cout << "\n| n | fst | lst | empty | ins | rmv | RmvAll |A|P| < | : ";
		char c;
		cin >> c;

		if (c!='n' && c!='f' && c!='l' && c!='e' && c!='i' && c!='r' && c!='R' && c!='<' && c!='A' && c!='P' )   
			break;
		int* val = new int;
		int succ;
		int index;
		switch (c) {
			case 'n' : 
				cout << arr.numOfItems() << endl; 
				break;
			case 'f' :  
				cout << *arr.first() << endl;   
				break;
			case 'l' : 
				cout << *arr.last() << endl;      
				break;
			case 'e' : 
				cout << (arr.isEmpty() ? "Empty" : "No") << endl; 
				break;
			case 'i' :  
				cout << "Enter int:"; 
				cin >> *val;
				arr.insert(val);
				break;
			case 'r' :  
				cout << "Enter int:"; 
				cin >> *val;
				arr.insert(val);
				break;
			case 'R' :  
				arr.removeAll();
				break;
			case 'A' :  
				cout << "Enter int value and int index:"; 
				cin >> *val >> index;
				succ = arr.append(index,val);
				cout << (succ ? "Success" : "Failed");
				break;
			case 'P' : 
				cout << "Enter int value and int index:"; 
				cin >> *val >> index;
				succ = arr.prepend(index,val);
				cout << (succ ? "Success" : "Failed");
				break;
			case '<' : 
				arr.printArray();
				break;
		}
	}

	return 0;
}

