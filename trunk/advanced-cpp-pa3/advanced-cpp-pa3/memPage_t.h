#pragma once
#include <cstring>
#include "common.h"

class memPage_t {
public:

	const static int DEFAULT_PAGE_SIZE = 1024;

	static const int ILLEGAL_POSITION = 1;
	static const int ILLEGAL_PAGE_SIZE = 2;
	static const int ILLEGAL_READ_SIZE = 3;
	static const int ILLEGAL_WRITE_SIZE = 4;

	memPage_t() throw(int);

	// throws ILLEGAL_PAGE_SIZE
	memPage_t(int _pageSize) throw(int);
	
	~memPage_t();

	// throws ILLEGAL_POSITION
	void setPosition(int position) throw(int);

	const int getPosition() const { return currentPosition; };
	const bool isEmpty() const { return actualSize == 0; };
	const bool isFull() const { return actualSize == pageSize; };
	const int getActualSize() { return actualSize; };
	const int getPageCapacity() const { return pageSize; };
	
	// these are not const corrected because they modify currentPosition
	// throws : ILLEGAL_POSITION, ILLEGAL_READ_SIZE (for read), ILLEGAL_WRITE_SIZE (for write)
	template<class T> const int read(T& elem, int size, int position) throw (int);
	template<class T> const int write(const T& elem, int size, int position) throw(int);
	template<class T> const int read(T& elem, int size) throw(int) { return read(elem,size,currentPosition); }
	template<class T> const int write(const T& elem, int size) throw(int) { return write(elem,size,currentPosition); }
	
private:
	
	friend class memPool_t;

	memPage_t(const memPage_t& page);
	const memPage_t& operator=(const memPage_t& page);

	int actualSize;
	int currentPosition;
	int pageSize;
	byte* pageBuffer;
};

template<class T> const int memPage_t::read(T& elem, int size, int position) throw(int) {
	if (size == 0) {
		return 0;
	}
	if (size < 0) {
		throw ILLEGAL_READ_SIZE;
	}
	if (position < 0 || position + size > actualSize) {
		throw ILLEGAL_POSITION;
	}
	
	memcpy(&elem, pageBuffer+position, size);
	setPosition(position+size);
	return size;
}

template<class T> const int memPage_t::write(const T& elem, int size, int position) throw(int) {
	if (size == 0) {
		return 0;
	}
	if (position < 0 || position > actualSize) {
		throw ILLEGAL_POSITION;
	}
	if (size < 0 || position + size > pageSize) {
		throw ILLEGAL_WRITE_SIZE;
	}

	memcpy(pageBuffer+position, &elem, size);
	int newPosition = position + size;
	actualSize = max(actualSize, newPosition);
	setPosition(newPosition);
	return size;
}

