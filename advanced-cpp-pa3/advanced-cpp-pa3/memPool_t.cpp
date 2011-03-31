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

template<class T> int memPool_t::read(T& elem, const int& size) const {
	if (actualSize < currentPosition + size || size < 1) {
		return -1;
	}

	memPage_t* currentPage = getCurrentPage();
	int bytesToRead = min(currentPage->getActualSize() - currentPage->getPosition(),size);
	currentPage->read(elem,bytesToRead);
	int readSize = bytesToRead;
	while (readSize < size) {
		currentPageIter++;
		currentPage = getCurrentPage();
		bytesToRead = min(currentPage->actualSize, size - readSize);
		currentPage->read(*(&elem + readSize),bytesToRead,0);
		readSize += bytesToRead;
	}
	
	if (currentPage->getPosition() == currentPage->getPageCapacity()) {
		currentPageIter++;
	}
	currentPosition += readSize;
	return readSize;
}

template<class T> int memPool_t::write(const T& elem, const int& size) {
	if (getNumOfPages() == 0) {
		createPages(1);
	}
	
	memPage_t* currentPage = getCurrentPage();
	int position = currentPage->getPosition();

	int freeSpaceInCurrentPage = currentPage->getPageCapacity() - currentPage->getActualSize();
	int writtenSize = 0;
	while (writtenSize < size) {
		int bytesToWriteInCurrentPage = min(freeSpaceInCurrentPage, size-writtenSize);
		currentPage->write(*(&elem + writtenSize), bytesToWriteInCurrentPage, position);
		writtenSize += bytesToWriteInCurrentPage;
		if (writtenSize < size) {
			currentPageIter++;
			if (currentPageIter == pages.end()) {
				createPages(1);
				currentPageIter = getLastPage();
			}
			currentPage = (memPage_t*)getCurrentPage();
			freeSpaceInCurrentPage = currentPage->getPageCapacity();
			position = 0;
		}
	}

	currentPosition += writtenSize;
	actualSize = max(actualSize, currentPosition);
	return writtenSize;
}

void memPool_t::setCurrentPosition(const int& position) throw(int) {
	if (position < 0 || position > actualSize) {
		throw ILLEGAL_POSITION;
	}

	currentPosition = 0;

	list<memPage_t*>::iterator iter = pages.begin();
	memPage_t* currentPage;
	int currentPosition = 0;
	for (currentPage = *iter; iter != pages.end(); currentPage = *iter++) {
		if (currentPosition <= position && currentPosition + currentPage->getPageCapacity() >= position) {
			break;
		}
		currentPosition += currentPage->getPageCapacity();
	}

	currentPageIter = iter;
	currentPage->setPosition(position-currentPosition);

}