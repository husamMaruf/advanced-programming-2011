#pragma once
#include <algorithm> 
#include <string>

using namespace std;

template <class T,class Container>
class tContainer_t {
public:
	tContainer_t();	//TODO Alon
	tContainer_t(const tContainer_t<T,Container>& tContainer); //TODO Dan
	~tContainer_t(); //TODO Dan

	const tContainer_t& operator=(const tContainer_t<T,Container>& tContainer); //TODO Alon
	T* operator[](unsigned index) const; // retrieve[] //TODO Dan
	const tContainer_t& operator+=(const tContainer_t<T,Container>& tContainer); //TODO Alon

	bool isEmpty() const; //TODO Alon
	int size() const;	//TODO Dan
	void append(const T* element); //TODO Alon
	T* getFirst() const; //TODO Dan
	T* getLast() const; //TODO Dan
	T* find(const T& element) const; //TODO Dan
	bool remove(const T& element); //TODO Alon
	void removeAll(); //TODO Alon

	typedef typename Container::iterator iter_t;

private:
	Container c;
};

ostream& operator<<(ostream& os, const tContainer_t<T,Container>&);



