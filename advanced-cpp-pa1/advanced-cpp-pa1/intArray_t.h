#pragma once
#include "stdafx.h"
#include <iostream>

#define CAPACITY_EXPAND_FACTOR 16

using namespace std;

class intArray_t {
public:
	intArray_t();
	intArray_t(int initCapacity);
	intArray_t(const intArray_t &arr);
	~intArray_t();

	int isEmpty() const;
	int numOfItems() const;
	int capacity() const;
	void insert(int* element);
	int* first() const;
	int* last() const;
	int* find(int value) const;
	int* remove(int value);
	void removeAll();
	int removeAndDelete(int value);
	void removeAndDeleteAll();
	int append(int index, int* element);
	int prepend(int index, int* element);
	ostream& printToStream(ostream& os) const;
private:
	void expand(int addedCapacity);
	int addElement(int index, int* element, bool isPrepend);
	int** intArray;
	int cap;
	int length;
};

ostream &operator<<(ostream& os, const intArray_t& intArray);