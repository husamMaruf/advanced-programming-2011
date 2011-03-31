#pragma once
#include <list>
#include <algorithm>
#include "common.h"
#include "memPage_t.h"

using namespace std;

class memPool_t {
public:

	const static int DEFAULT_INIT_PAGES = 1;

	static const int ILLEGAL_POSITION = 1;
	static const int ILLEGAL_NUMBER_OF_PAGES = 2;
	
	memPool_t() throw(int) :actualSize(0),capacity(0) { createPages(DEFAULT_INIT_PAGES); }
	memPool_t(const int& numOfEmptyPages) throw(int) :actualSize(0),capacity(0) { createPages(numOfEmptyPages); }
	~memPool_t();

	bool isEmpty() const { return actualSize == 0; }
	const int& getActualSize() const { return actualSize; }
	const int& getCapacity() const { return capacity; }
	const int getNumOfPages() const { return pages.size(); }
	const memPage_t* getFirstPage() const { return *pages.begin(); }
	const memPage_t* getLastPage() const;
	const memPage_t* getCurrentPage() const { return *currentPageIter; }
	template<class T> int read(T& elem, const int& size) const ;
	template<class T> int write(const T& elem, const int& size);
	void createPages(const int& amount) throw(int);
	const int& getDefaultPageSize() const { return memPage_t::defaultPageSize; }
	void setDefaultPageSize(const int& pageSize) { memPage_t::defaultPageSize = pageSize; }
	const int& getCurrentPosition() const { return currentPosition; }
	void setCurrentPosition(const int& position) throw(int);

private:
	memPool_t(const memPool_t& memPool);
	const memPool_t& operator=(const memPool_t& memPool);

	int capacity;
	int actualSize;
	int currentPosition;
	list<memPage_t*> pages;
	list<memPage_t*>::iterator currentPageIter;
};

void deleteMemPagePtr(memPage_t*  page);