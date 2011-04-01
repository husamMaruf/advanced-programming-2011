#include "memPool_t.h"

memPool_t::~memPool_t() {
	for_each(pages.rbegin(), pages.rend(), &deleteMemPagePtr);
}

void deleteMemPagePtr(memPage_t* page) {
	delete page;
}

const memPage_t* memPool_t::getLastPage() const {
	list<memPage_t*>::const_iterator result = pages.end();
	result--;
	return *result;
}

void memPool_t::createPages(const int& amount) throw(int) {

	if (amount < 1) {
		throw ILLEGAL_NUMBER_OF_PAGES;
	}

	for (int i=0; i<amount; i++) {
		memPage_t* newPage = new memPage_t();
		if (getNumOfPages() > 0) {
			memPage_t* lastPage = (memPage_t*)getLastPage();
			lastPage->next = newPage;
			newPage->previous = lastPage;
		}
		pages.push_back(newPage);
		if (getNumOfPages() == 1) {
			currentPageIter = pages.begin();
		}
	}

	capacity += amount * getDefaultPageSize();
}

void memPool_t::setCurrentPosition(const int& position) throw(int) {
	if (position < 0 || position > actualSize) {
		throw ILLEGAL_POSITION;
	}

	currentPosition = 0;

	list<memPage_t*>::iterator iter = pages.begin();
	memPage_t* currentPage;
	int currentPosition = 0;
	for (currentPage = *iter; iter != pages.end(); currentPage = *iter) {
		if (currentPosition <= position && currentPosition + currentPage->getPageCapacity() >= position) {
			break;
		}
		currentPosition += currentPage->getPageCapacity();
		iter++;
	}

	currentPageIter = iter;
	currentPage->setPosition(position-currentPosition);
	currentPosition = position;

}