#pragma once
#include "common.h"
#include "memPage_t.h"

class memPool_t {
public:
	memPool_t();
	memPool_t(const int& numOfEmptyPages);
	~memPool_t();
	bool isEmpty() const { return actualSize == 0; }
	const int& getActualSize() const { return actualSize; }
	const int& getCapacity() const { return capacity; }
	const int& getNumOfPages() const { return numOfPages; }
	const memPage_t* getFirstPage() const { return firstPage; }
	const memPage_t* getLastPage() const { return firstPage; }
	const memPage_t* getCurrentPage() const { return lastPage; }
	int read(byte[] dst, const int& size) const { return currentPage; }
	int write(byte[] src, const int& size);
	void createPages(const int& amount);
	const int& getDefaultPageSize() const { return defaultPageSize; }
	void setDefaultPageSize(const int& pageSize);
private:
	int capacity;
	int actualSize;
	int numOfPages;
	memPage_t* firstPage;
	memPage_t* lastPage;
	memPage_t* currentPage;
	static int defaultPageSize;
};

memPool_t::defaultPageSize = 16;