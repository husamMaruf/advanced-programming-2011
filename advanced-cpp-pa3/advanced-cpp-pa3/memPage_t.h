#pragma once
#include <cstring>
#include "common.h"


class memPage_t {
public:

	static const int ILLEGAL_POSITION = 1;
	static const int ILLEGAL_PAGE_SIZE = 2;
	static const int ILLEGAL_READ_SIZE = 3;

	memPage_t() throw(int);
	memPage_t(const int& pageSize) throw(int);
	~memPage_t();

	void setPosition(const int& position) throw(int);
	const int& getPosition() const { return currentPosition; };
	const bool isEmpty() const { return actualSize == 0; };
	const bool isFull() const { return actualSize == pageSize; };
	const int& getActualSize() { return actualSize; };
	const int& getPageCapacity() const { return pageSize; };
	
	const memPage_t* getPreviousPage() { return previous; }
	const memPage_t* getNextPage() { return next; }

	template<class T> const void read(T& elem, const int& size, const int& position) const throw (int);
	template<class T> const void write(const T& elem, const int& size, const int& position) throw(int); //ALON
	template<class T> const void read(T& elem, const int& size) throw(int);
	template<class T> const void write(const T& elem, const int& size) throw(int);	//ALON
	
private:
	
	friend class memPool_t;

	static int defaultPageSize;

	memPage_t(const memPage_t& page);
	const memPage_t& operator=(const memPage_t& page);

	memPage_t* previous;
	memPage_t* next;

	int actualSize;
	int currentPosition;
	int pageSize;
	byte* pageBuffer;

};
