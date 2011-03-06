#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {

	intArray_t::intArray_t arr;

	while(1) {
		cout << "\n| n | fst | lst | empty | ins | rmv | RmvAll |A|P| < | : ";
		char c;
		cin >> c;

		if (c!='n' && c!='f' && c!='l' && c!='e' && c!='i' && c!='r' && c!='R' && c!='<' && c!='A' && c!='P' )   
			break;

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
				// insert
				break;
			case 'r' :  
				// remove
				break;
			case 'R' :  
				// remove all
				break;
			case 'A' :  
				// append
				break;
			case 'P' : 
				// prepend
				break;
			case '<' : 
				// print array
				break;
		}
	}

	return 0;
}

