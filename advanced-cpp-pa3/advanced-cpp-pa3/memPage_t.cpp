#include "memPage_t.h"

memPage_t::memPage_t() : 
	pageSize(defaultPageSize), currentPosition(0), actualSize(0), 
	previous(0), next(0) {
	if (pageSize <= 0) {
		throw ILLEGAL_PAGE_SIZE;
	}	
	pageBuffer = new byte[pageSize];
	}

memPage_t::memPage_t(const int& _pageSize) throw(int) : 
	pageSize(_pageSize), currentPosition(0), actualSize(0), 
	previous(0), next(0)  { 
	if (pageSize <= 0) {
		throw ILLEGAL_PAGE_SIZE;
	}
	pageBuffer = new byte[pageSize];
}

memPage_t::~memPage_t() {
	delete pageBuffer;
}

int memPage_t::defaultPageSize = 1024;

void memPage_t::setPosition(const int &position) throw(int) {
	if (position < 0 || position > actualSize) {
		throw ILLEGAL_POSITION;
	}

	currentPosition = position;
}


template<class T> const void memPage_t::read(T& elem, const int& size, const int& position) const throw(int) {
	if (size < 1) {
		throw ILLEGAL_READ_SIZE;
	}
	
	if (position < 0 || position + size > actualSize) {
		throw ILLEGAL_POSITION;
	}
	
	memcpy(&elem, pageBuffer+position, size);
}

template<class T> const void memPage_t::read(T& elem, const int& size) {
	read(elem,size,currentPosition);
}

int main(void) {
	return 0;
}