#pragma once
#include <list>
#include "common.h"
#include "memPage_t.h"

using namespace std;

class memPool_t {
public:
	memPool_t();	//Alon
	memPool_t(const int& numOfEmptyPages);	//Alon
	~memPool_t();	//Dan
	bool isEmpty() const { return actualSize == 0; }
	const int& getActualSize() const { return actualSize; }
	const int& getCapacity() const { return capacity; }
	const int& getNumOfPages() const { return pages.size(); }
	const memPage_t* getFirstPage() const { return &(*pages.begin()); }
	const memPage_t* getLastPage() const;	//ALON
	const memPage_t* getCurrentPage() const { return &(*currentPageIter); }
	template<class T> int read(T& elem, const int& size, const int& position) const ;	//ALON
	template<class T> int write(const T& elem, const int& size, const int& position);	//DAN
	void createPages(const int& amount);	//ALON
	const int& getDefaultPageSize() const { return memPage_t::defaultPageSize; }
	void setDefaultPageSize(const int& pageSize) { memPage_t::defaultPageSize = pageSize; }
private:
	memPool_t(const memPool_t& memPool);
	int capacity;
	int actualSize;
	list<memPage_t> pages;
	list<memPage_t>::iterator currentPageIter;
};