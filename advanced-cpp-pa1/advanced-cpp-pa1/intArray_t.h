#pragma once
#include "stdafx.h"
#include <iostream>

#define CAPACITY_EXPAND_FACTOR 16

using namespace std;

class intArray_t {
public:
	intArray_t();
	intArray_t(const int& initCapacity);
	~intArray_t();
	int isEmpty() const;
	int numOfItems() const;
	int capacity() const;
	void insert(int* element);
	int* first() const;
	int* last() const;
	int* find(const int& value) const;
	int* remove(const int& value);
	void removeAll();
	int removeAndDelete(const int& value);
	void removeAndDeleteAll();
	int append(const int& index, int* element);
	int prepend(const int& index, int* element);
	ostream& printToStream(ostream& os) const;
private:
	intArray_t(const intArray_t&);
	intArray_t& operator= (const intArray_t&);
	void expand(const int& addedCapacity);
	int addElement(const int& index, int* element, bool isPrepend);
	int** intArray;
	int cap;
	int length;
};

ostream &operator<<(ostream& os, const intArray_t& intArray);