#include "memPage_t.h"

memPage_t::memPage_t() : 
	pageSize(DEFAULT_PAGE_SIZE), currentPosition(0), actualSize(0), 
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

void memPage_t::setPosition(const int &position) throw(int) {
	if (position < 0 || position > actualSize) {
		throw ILLEGAL_POSITION;
	}

	currentPosition = position;
}



