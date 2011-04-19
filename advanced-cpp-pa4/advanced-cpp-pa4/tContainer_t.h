#pragma once
#include <algorithm> 
#include <string>

using namespace std;

template <class T,class Container>
class tContainer_t {
public:
	tContainer_t();
	tContainer_t(const tContainer_t& tContainer);
	~tContainer_t();

	const tContainer_t& operator=(const tContainer_t& tContainer);
	T* operator[](unsigned index) const; // retrieve[]
	const tContainer_t& operator+=(const tContainer_t& tContainer);

	bool isEmpty() const;
	int size() const;
	void append(const T* element);
	T* getFirst() const;
	T* getLast() const;
	T* find(const T& element) const;
	bool remove(const T& element);
	void removeAll();
};

ostream& operator<<(ostream& os, const tContainer_t&); //not needed but may be good for testing



