#include "stdafx.h"
#include "intArray_t.h"

using namespace std;

intArray_t::intArray_t() {
	intArray = new int*[CAPACITY_EXPAND_FACTOR];
	cap = CAPACITY_EXPAND_FACTOR;
	length = 0;
}

intArray_t::intArray_t(int initCapacity) {
	intArray = new int*[initCapacity];
	cap = initCapacity;
	length = 0;
}

intArray_t::~intArray_t() {
	delete[] intArray;
}

int intArray_t::isEmpty() {
	return length == 0; 
}

int intArray_t::numOfItems() {
	return length; 
}

int intArray_t::capacity() { 
	return cap; 
}

int* intArray_t::first() { 
	return intArray[0]; 
}

int* intArray_t::last() {
	return intArray[length-1]; 
}

void intArray_t::expand(int addedCapacity) {
	cap += addedCapacity;
	int** newIntArray = new int*[cap];
	for (int i=0; i<length; i++) {
		newIntArray[i] = intArray[i];
	}
	delete[] intArray;
	intArray = newIntArray;
}

int* intArray_t::remove(int value) {
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

void intArray_t::insert(int* element) {
	append(length-1, element);
}

int intArray_t::append(int index, int* element) {
	return addElement(index, element, false);
}

void intArray_t::removeAll() {
	length = 0;
}

int intArray_t::removeAndDelete(int value) {
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
	delete[] intArray;
	cap = 0;
	length = 0;
}

int intArray_t::prepend(int index, int* element) {
	return addElement(index, element, true);
}

int intArray_t::addElement(int index, int* element, bool isPrepend) {
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

int* intArray_t::find(int value) {
	for (int i=0; i<length; i++) {
		if (*intArray[i] == value) {
			return intArray[i];
		}
	}
	return 0;
}

void intArray_t::printArray() {
	cout << "[";
	if (length > 0) {
		cout << *intArray[0];
		for (int i=1; i<length; i++) {
			cout << ", " << *intArray[i];
		}
	}
	cout << "]";
}