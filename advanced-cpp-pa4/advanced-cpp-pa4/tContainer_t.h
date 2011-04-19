#pragma once
#include <algorithm> 
#include <string>

using namespace std;

template <class T,class Container>
class tContainer_t {
public:
	//tContainer_t(); //default CTOR
	tContainer_t(const tContainer_t<T,Container>& tContainer); //TODO Dan
	~tContainer_t(); //TODO Dan

	const tContainer_t& operator=(const tContainer_t<T,Container>& tContainer);
	T* operator[](unsigned index) const; // retrieve[] //TODO Dan
	const tContainer_t& operator+=(const tContainer_t<T,Container>& tContainer);

	bool empty() const { return (c.empty()); }
	int size() const;	//TODO Dan
	void append(const T* element) { c.push_back(element); }
	T* front() const; //TODO Dan
	T* back() const; //TODO Dan
	T* find(const T& element) const; //TODO Dan
	bool remove(const T& element);
	void removeAll() { c.clear(); }

	typedef typename Container::iterator iter_t;

private:
	Container c;

	const Container& getContainer() const { return c; }
};

ostream& operator<<(ostream& os, const tContainer_t<T,Container>&);

bool tContainer_t::remove(const T& element) {
	for (iter_t iter = c.begin(); iter != c.end(); iter++) {
		if (**iter == element) {
			c.erase(iter);
			return true;
		}
	}
	return false;
}

const tContainer_t& operator=(const tContainer_t<T,Container>& tContainer) {
	c = tContainer.getContainer();
	return *this;
}

const tContainer_t& tContainer_t::operator+=(const tContainer_t<T,Container>& tContainer) {
	while (!tContainer.empty()) {
		c.append(tContainer.front());
		tContainer.getContainer().pop_front();
	}
	return *this;
}

