//#include "intArray_t.h"
#include "stdafx.h"
#include <iostream>
using namespace std;

class intArray_t {
public:
	intArray_t(); //Default CTOR
	intArray_t(int initCapacity);
	~intArray_t();

	int isEmpty() { return length == 0; }
	int numOfItems() { return length; }
	int capacity() { return cap; }
	void insert(int* element);
	int* first() { return intArray[0]; }
	int* last() { return intArray[length-1]; }
	int* find(int value);
	int* remove(int value);
	void removeAll();
	int removeAndDelete(int value);
	void removeAndDeleteAll();
	int append(int index, int* element);
	int prepend(int index, int* element);

private:
	int** intArray;
	int cap;
	int length;
};

intArray_t::intArray_t(int initCapacity) {
	intArray = new int*[initCapacity];
}



