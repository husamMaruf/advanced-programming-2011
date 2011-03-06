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

void intArray_t::expand(int addedCapacity) {
	cap += addedCapacity;
	int** newIntArray = new int*[cap];
	for (int i=0; i<length; i++) {
		newIntArray[i] = intArray[i];
	}
	delete[] intArray;
	intArray = newIntArray;
}

int intArray_t::append(int index, int* element) {
	return addElement(index, element, false);
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