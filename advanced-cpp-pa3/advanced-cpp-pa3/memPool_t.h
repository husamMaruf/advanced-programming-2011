#pragma once
#include <list>
#include <algorithm>
#include "common.h"
#include "memPage_t.h"
#include <iostream>

using namespace std;

class memPool_t {
public:

	const static int DEFAULT_INIT_PAGES = 1;

	static const int ILLEGAL_POSITION = 5;
	static const int ILLEGAL_NUMBER_OF_PAGES = 6;
	
	memPool_t() throw(int) :actualSize(0),capacity(0), currentPosition(0) { createPages(DEFAULT_INIT_PAGES); }
	memPool_t(const int& numOfEmptyPages) throw(int) :actualSize(0),capacity(0), currentPosition(0) { createPages(numOfEmptyPages); }
	~memPool_t();

	bool isEmpty() const { return actualSize == 0; }
	const int& getActualSize() const { return actualSize; }
	const int& getCapacity() const { return capacity; }
	const int getNumOfPages() const { return pages.size(); }
	const memPage_t* getFirstPage() const { return *pages.begin(); }
	const memPage_t* getLastPage() const;
	const memPage_t* getCurrentPage() const { return *currentPageIter; }
	template<class T> int read(T& elem, const int& size); // not const because currentPosition changes
	template<class T> int write(const T& elem, const int& size);
	void createPages(const int& amount) throw(int);
	const int& getCurrentPosition() const { return currentPosition; }
	void setCurrentPosition(const int& position) throw(int);

	static const int& getDefaultPageSize() { return memPool_t::defaultPageSize; }
	static void setDefaultPageSize(const int& pageSize) { memPool_t::defaultPageSize = pageSize; }

private:
	memPool_t(const memPool_t& memPool);
	const memPool_t& operator=(const memPool_t& memPool);

	static int defaultPageSize;

	int capacity;
	int actualSize;
	int currentPosition;
	list<memPage_t*> pages;
	list<memPage_t*>::iterator currentPageIter;
};

template<class T> int memPool_t::read(T& elem, const int& size) {
	if (actualSize < currentPosition + size || size < 1) {
		return (size == 0) ? 0 : -1;
	}

	memPage_t* currentPage = *currentPageIter;
	int bytesToRead = min(currentPage->getActualSize() - currentPage->getPosition(),size);
	int readSize = currentPage->read(elem,bytesToRead);
	while (readSize < size) {
		currentPageIter++;
		currentPage = *currentPageIter;
		bytesToRead = min(currentPage->getActualSize(), size - readSize);
		readSize += currentPage->read(*((byte*)(&elem) + readSize),bytesToRead,0);
	}

	if (currentPage->getPosition() == currentPage->getPageCapacity()) {
		currentPageIter++;
		if (currentPageIter != pages.end()) {
			currentPage = *currentPageIter;
			currentPage->setPosition(0);
		}
	}

	currentPosition += readSize;
	return readSize;
}

template<class T> int memPool_t::write(const T& elem, const int& size) {
	if (size < 1) {
		return (size == 0) ? 0 : -1;
	}

	if (getNumOfPages() == 0 || currentPageIter == pages.end()) {
		createPages(1);
		currentPageIter = --(pages.end());
	}

	memPage_t* currentPage = *currentPageIter;
	int bytesToWrite = min(currentPage->getPageCapacity() - currentPage->getPosition(),size);
	int writtenSize = currentPage->write(elem,bytesToWrite);
	while (writtenSize < size) {
		createPages(1);
		currentPageIter++;
		currentPage = *currentPageIter;
		bytesToWrite = min(currentPage->getPageCapacity(), size - writtenSize);
		writtenSize += currentPage->write(*((byte*)(&elem) + writtenSize), bytesToWrite, 0);
	}

	if (currentPage->getPosition() == currentPage->getPageCapacity()) {
		currentPageIter++;
		if (currentPageIter != pages.end()) {
			currentPage = *currentPageIter;
			currentPage->setPosition(0);
		}
	}

	currentPosition += writtenSize;
	actualSize = max(actualSize, currentPosition);
	return writtenSize;
}

void deleteMemPagePtr(memPage_t*  page);