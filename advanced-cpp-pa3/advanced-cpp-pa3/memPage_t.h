#pragma once

//TODO: move to common
typedef char byte;

class memPage_t {
public:

	static const int DEFAULT_PAGE_SIZE = 1024;

	memPage_t();
	memPage_t(const int& pageSize);

	~memPage_t();

	void setPosition(const int& position);
	const int& getPosition() const { return currentPosition; };
	const bool& isEmpty() const;
	const bool& isFull() const;
	const int& getActualSize();
	const int& getPageCapacity() const { return pageSize; };
	
	template<class T> const int& read(T& elem, const int& size, const int& position) const;
	template<class T> const int& write(const T& elem, const int& size, const int& position);
	template<class T> const int& read(T& elem, const int& size) const;
	template<class T> const int& write(const T& elem, const int& size);
	
private:
	memPage_t(const memPage_t& page);
	const memPage_t& operator=(const memPage_t& page);

	memPage_t* next;

	byte pageBuffer[DEFAULT_PAGE_SIZE]; // TODO change and define in CTOR
	int currentPosition;
	int pageSize;

};
