#pragma once
#include <algorithm> 
#include <string>
#include <queue>

using namespace std;

template <class T,class Container>
class tContainer_t {
public:
	tContainer_t();
	tContainer_t(const tContainer_t<T,Container>& tContainer);
	~tContainer_t();

	const tContainer_t& operator=(const tContainer_t<T,Container>& tContainer);
	T* operator[](unsigned index) const; // retrieve[]
	const tContainer_t& operator+=(const tContainer_t<T,Container>& tContainer);

	bool isEmpty() const;
	int size() const;
	void append(const T* element);
	T* getFirst() const;
	T* getLast() const;
	T* find(const T& element) const;
	bool remove(const T& element);
	void removeAll();

	typedef typename Container::iterator iter_t;
private:
	Container c;
};

ostream& operator<<(ostream& os, const tContainer_t<T,Container>&); //not needed but may be good for testing



