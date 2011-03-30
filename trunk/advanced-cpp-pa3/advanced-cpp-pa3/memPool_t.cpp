#include "memPool_t.h"

memPool_t::~memPool_t() {
	for_each(pages.rbegin(), pages.rend(), &deleteMemPagePtr);
}

void deleteMemPagePtr(memPage_t&  page) {
	delete &page;
}

const memPage_t* memPool_t::getLastPage() const {
	list<memPage_t>::iterator result = pages.end();
	result--;
	return &(*result);
}

void memPool_t::createPages(const int& amount) {
	//TODO ALON
	capacity+= amount;
}
