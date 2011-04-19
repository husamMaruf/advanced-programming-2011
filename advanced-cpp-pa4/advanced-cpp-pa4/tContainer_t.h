#pragma once
#include <algorithm> 

using namespace std;

template <class T,class Container>
class tContainer_t {
public:

	typedef typename Container::const_iterator iter_t;

	tContainer_t() { } // nothing to do

	tContainer_t(const tContainer_t<T,Container>& tContainer) { 
		c = tContainer.c;
	}
	
	// ~tContainer_t(); // default DTOR 

	const tContainer_t& operator=(const tContainer_t<T,Container>& tContainer) {
		if (this != &tContainer) {
			c = tContainer.c;
		}
		return *this;
	}
	
	T* operator[](unsigned index) const {
		iter_t it = c.begin();
		for(int i=0; it != c.end() && i<index; i++, it++);
		if (it == c.end()) {
			return 0;
		}
		return *it;
	}
	
	const tContainer_t& operator+=(tContainer_t<T,Container>& tContainer) {
		while (!tContainer.empty()) {
			append(tContainer.front());
			tContainer.c.pop_front();
		}
		return *this;
	}

	bool empty() const {  return (c.empty()); }

	int size() const { return (c.size()); }

	void append(const T* element) { c.push_back((T*)element); }

	T* front() const { return (c.front()); }

	T* back() const { return (c.back()); }
	
	T* find(const T& element) const {
		iter_t it = find_if(c.begin(), c.end(), Pred(element));
		if (it == c.end()) {
			return 0;
		}
		return *it;
	}
	
	T* remove(const T& element) {
		iter_t it = find_if(c.begin(), c.end(), Pred(element));
		if (it == c.end()) {
			return 0;
		}
		T* pElement = *it;
		c.erase(it);
		return pElement;
	}
	
	void removeAll() { c.clear(); }

private:

	struct Pred {
		Pred(const T& _elem) : elem(_elem) { }
		bool operator()(const T* other) { return elem == *other; }
		T elem;
	};

	Container c;

};

//ostream& operator<<(ostream& os, const tContainer_t<T,Container>&);
