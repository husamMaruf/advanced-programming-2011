#pragma once
#include <list>
#include "common.h"
#include "memPage_t.h"

using namespace std;

class memPool_t {
public:
	memPool_t();
	memPool_t(const int& numOfEmptyPages);
	~memPool_t();
	bool isEmpty() const { return actualSize == 0; }
	const int& getActualSize() const { return actualSize; }
	const int& getCapacity() const { return capacity; }
	const int& getNumOfPages() const { return pages.size(); }
	const memPage_t* getFirstPage() const { return &(*pages.begin()); }
	const memPage_t* getLastPage() const { return &(*(pages.end()-1)); }
	const memPage_t* getCurrentPage() const { return &(*currentPageIter;) }
	template<class T> int read(T& elem, const int& size, const int& position) const ;
	template<class T> int write(const T& elem, const int& size, const int& position);
	void createPages(const int& amount);
	const int& getDefaultPageSize() const { return memPage_t::defaultPageSize; }
	void setDefaultPageSize(const int& pageSize) { memPage_t::defaultPageSize = pageSize; }
private:
	memPool_t(const memPool_t& memPool);
	int capacity;
	int actualSize;
	list<memPage_t> pages;
	list<memPage_t>::iterator currentPageIter;
};