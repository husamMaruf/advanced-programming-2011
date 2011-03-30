#include "memPool_t.h"

memPool_t::~memPool_t() {

}

const memPage_t* memPool_t::getLastPage() const {
	list<memPage_t>::iterator result = pages.end();
	result--;
	return *result;
}

void memPool_t::createPages(const int& amount) {
	//TODO ALON
	capacity+= amount;
}