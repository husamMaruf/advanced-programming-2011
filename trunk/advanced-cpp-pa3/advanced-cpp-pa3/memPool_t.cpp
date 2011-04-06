#include "memPool_t.h"

memPool_t::~memPool_t() {
	list<memPage_t*>::iterator it = pages.begin();
	while(it != pages.end()) {
		delete *it;
		it++;
	}
	pages.clear(); 
}

int memPool_t::defaultPageSize = 32;

const memPage_t* memPool_t::getLastPage() const {
	list<memPage_t*>::const_iterator result = pages.end();
	result--;
	return *result;
}

void memPool_t::setDefaultPageSize(int pageSize) { 
	if (pageSize < 1) {
		throw ILLEGAL_PAGE_SIZE;
	}	

	defaultPageSize = pageSize; 
}

void memPool_t::createPages(int amount) throw(int) {
	if (amount < 1) {
		throw ILLEGAL_NUMBER_OF_PAGES;
	}

	for (int i=0; i<amount; i++) {
		memPage_t* newPage = new memPage_t(getDefaultPageSize());
		pages.push_back(newPage);
		if (getNumOfPages() == 1) {
			currentPageIter = pages.begin();
		}
	}

	capacity += amount * getDefaultPageSize();
}

void memPool_t::setCurrentPosition(int position) throw(int) {
	if (position < 0 || position > actualSize) {
		throw ILLEGAL_POSITION;
	}

	list<memPage_t*>::iterator iter = pages.begin();
	memPage_t* currentPage = *iter;
	for (currentPosition = 0; currentPosition + currentPage->getPageCapacity() <= position;
		currentPosition += currentPage->getPageCapacity(), currentPage = *(++iter));

	currentPageIter = iter;
	if (currentPageIter != pages.end()) {
		currentPage->setPosition(position-currentPosition);
	}
	currentPosition = position;
}