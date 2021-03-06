#pragma once
#include <algorithm> 

using namespace std;

template <class T,class Container>
class tContainer_t {
public:

	typedef typename Container::const_iterator cIter_t;
	typedef typename Container::iterator iter_t;

	tContainer_t() {} // nothing to do

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
	
	T*& operator[](unsigned index) {
		if (index < 0 || index >= size()) {
			static T* result;
			result = 0; // Because the user can change it
			return result;
		}
		cIter_t it = c.begin();
		for(int i=0; i<index; i++, it++);
		return (T*)*it;
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
		cIter_t it = find_if(c.begin(), c.end(), Pred(element));
		if (it == c.end()) {
			return 0;
		}
		return *it;
	}
	
	T* remove(const T& element) {
		cIter_t it = find_if(c.begin(), c.end(), Pred(element));
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

	friend ostream& operator<<(ostream& os, const tContainer_t<T,Container>& tContainer) {
		os << "[";
		if (!tContainer.empty()) {
			cIter_t it = tContainer.c.begin();
			os << **it << "(" << *it << ")";
			it++;
			for(; it != tContainer.c.end(); it++) {
				os << ", " << **it << "(" << *it << ")";
			}
		}
		os << "]";
		return os;
	}

};

