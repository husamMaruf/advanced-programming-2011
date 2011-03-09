#include "stdafx.h"
#include "intArray_t.h"

using namespace std;

intArray_t::intArray_t() {
	intArray = new int*[CAPACITY_EXPAND_FACTOR];
	cap = CAPACITY_EXPAND_FACTOR;
	length = 0;
}

intArray_t::intArray_t(const int& initCapacity) {
	intArray = new int*[initCapacity];
	cap = initCapacity;
	length = 0;
}

intArray_t::~intArray_t() {
	delete[] intArray;
}

int intArray_t::isEmpty() const {
	return length == 0; 
}

int intArray_t::numOfItems() const {
	return length; 
}

int intArray_t::capacity() const { 
	return cap; 
}

int* intArray_t::first() const { 
	if (length == 0) {
		return NULL;
	}
	
	return intArray[0]; 
}

int* intArray_t::last() const {
	if (length == 0) {
		return NULL;
	}

	return intArray[length-1]; 
}

void intArray_t::expand(const int& addedCapacity) {
	cap += addedCapacity;
	int** newIntArray = new int*[cap];
	for (int i=0; i<length; i++) {
		newIntArray[i] = intArray[i];
	}
	delete[] intArray;
	intArray = newIntArray;
}

void intArray_t::insert(int* element) {
	if (length == cap) {
		expand(CAPACITY_EXPAND_FACTOR);
	}
	intArray[length] = element;
	length++;
}

int intArray_t::append(const int& index, int* element) {
	return addElement(index, element, false);
}

int intArray_t::prepend(const int& index, int* element) {
	return addElement(index, element, true);
}

// helper function for append and prepend (array has to contains at least 1 element)
int intArray_t::addElement(const int& index, int* element, bool isPrepend) {
	if (index < 0 || index > length-1) {
		return 0;
	}
	if (length == cap) {
		expand(CAPACITY_EXPAND_FACTOR);
	}
	int location = isPrepend ? index : index + 1;
	for (int i=length-1; i>=location; i--) {
		intArray[i+1] = intArray[i];
	}
	intArray[location] = element;
	length += 1;
	return 1;
}

int* intArray_t::find(const int& value) const {
	for (int i=0; i<length; i++) {
		if (*intArray[i] == value) {
			return intArray[i];
		}
	}
	return 0;
}

int* intArray_t::remove(const int& value) {
	int i;
	for (i=0; i < length && *(intArray[i]) != value; i++);
	if (i == length) return NULL;
	int* element = intArray[i];
	for (; i+1 < length; i++) {
		intArray[i] = intArray[i+1];
	}
	length--;
	return element;
}

void intArray_t::removeAll() {
	length = 0;
}

int intArray_t::removeAndDelete(const int& value) {
	int* element = remove(value);
	if (element) {
		delete element;
		return 1;
	}
	return 0;
}

void intArray_t::removeAndDeleteAll() {
	for (int i=0; i < length; i++) {
		delete intArray[i];
	}
	length = 0;
}

ostream& intArray_t::printToStream(ostream& os) const {
	os << "[";
	if (length > 0) {
		os << *intArray[0];
		for (int i=1; i<length; i++) {
			os << ", " << *intArray[i];
		}
	}
	os << "]";
	return os;
}

ostream &operator<<(ostream& os, const intArray_t& intArray) {
	return intArray.printToStream(os);
}