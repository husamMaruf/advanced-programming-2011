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

void memPool_t::createPages(const int& amount) {
	for (int i=0; i<amount; i++) {
		pages.push_back(new memPage_t());
	}
	capacity+= amount;
}
