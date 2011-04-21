#include "tContainer_t.h"
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <string>

using namespace std;

// abstract class to generate values for testing
template<class T>
class Generator {
public:
	virtual T operator()() = 0;
};

// int implementation of Generator<int>
class IntGenerator : public Generator<int> {
public:
	IntGenerator() : value(0) { }
	int operator()() {
		int result = value;
		value += 1;
		return result;
	}

protected:
	int value;
};

// sample class
class DataContainer {
public:
	DataContainer() : id(0), ch('a') { }
	DataContainer(int _id, char _ch) : id(_id), ch(_ch) { }
	bool operator==(const DataContainer& other) {
		return (id==other.id && ch==other.ch);
	}
	friend ostream& operator<<(ostream& os, const DataContainer& cont) {
		return os << "DC(" << cont.id << ", " << cont.ch << ")";
	}
	friend istream& operator>>(istream& is, DataContainer& cont) {
		int id;
		char ch;
		cout << "enter id:" << endl;
		is >> id;
		cout << "enter ch: " << endl;
		is >> ch;
		cont.id = id;
		cont.ch = ch;
		return is;
	}
private:
	int id;
	char ch;
};

// DataContainer implementation for Generator<DataContainer>
class DataContainerGenerator : public Generator<DataContainer> {
public:
	DataContainerGenerator() : id(0), ch('a') { }
	DataContainer operator()() {
		int oldId = id;
		char oldChar = ch;
		id += 1;
		ch = ch == 'z' ? 'a' : ch+1;
		return DataContainer(oldId,oldChar);
	}
private:
	int id;
	char ch;
};

template<class T, class Container>
void test(tContainer_t<T,Container>& cont, Generator<T>& generator) {
	
	char answer;
	bool quit = false;
	int index;
	
	T* value;
	T actualValue;

	tContainer_t<T,Container>* c1 = 0;
	tContainer_t<T,Container> c2;

	while(!quit) {
		
		cout << "Make your choice:" << endl;
		cout << "[a] Default CTOR" << endl;
		cout << "[b] Copy CTOR" << endl;
		cout << "[c] operator=" << endl;
		cout << "[d] operator[] (retrieve value)" << endl;
		cout << "[e] operator[] (assign value)" << endl;
		cout << "[f] operator+=" << endl;
		cout << "[g] empty" << endl;
		cout << "[h] size" << endl;
		cout << "[i] append" << endl;
		cout << "[j] front" << endl;
		cout << "[k] back" << endl;
		cout << "[l] find" << endl;
		cout << "[m] remove" << endl;
		cout << "[n] remove all" << endl;
		cout << "[p] print cont" << endl;
		cout << "[q] quit" << endl;

		cin >> answer;

		switch(answer) {
			
			case 'a':
				c1 = new tContainer_t<T,Container>();
				cout << "Called default CTOR" << endl;
				cout << *c1 << endl;
				delete c1;
				break;
			case 'b':

				break;
			case 'c':
				c2 = cont;
				cout << "Called operator=" << endl;
				cout << c2 << endl;
				break;
			case 'd':
				cout << "enter index:" << endl;
				cin >> index;
				value = cont[index];
				if (value == 0) cout << "Not found" << endl;
				else cout << "Value: " << *value << endl;
				break;
			case 'e':
				cout << "enter index:" << endl;
				cin >> index;
				value = new T;
				*value = generator();
				cout << "Before: " << cont << endl;
				cont[index] = value;
				cout << "updated container" << endl;
				cout << "After: " << cont << endl;
				break;
			case 'f':
				c2.removeAll();
				value = new T;
				*value = generator();
				c2.append(value);
				value = new T;
				*value = generator();
				c2.append(value);
				cout << "Before: " << cont << endl;
				cont += c2;
				cout << "Moved elements from one container to another" << endl;
				cout << "After: " << cont << endl;
				break;
			case 'g':
				cout << "cont is empty? " << (cont.empty() ? "true" : "false") << endl;
				break;
			case 'h':
				cout << "cont size: " << cont.size() << endl;
				break;
			case 'i':
				value = new T;
				*value = generator();
				cout << "Before: " << cont << endl;
				cont.append(value);
				cout << "added new element to cont" << endl;
				cout << "After: " << cont << endl;
				break;
			case 'j':
				if (cont.empty()) cout << "empty" << endl;
				else cout << "Value: " << *cont.front() << endl;
				break;
			case 'k':
				if (cont.empty()) cout << "empty" << endl;
				else cout << "Value: " << *cont.back() << endl;				
				break;
			case 'l':
				cout << "enter value to find: " << endl;
				cin >> actualValue;
				value = cont.find(actualValue);
				if (value == 0) cout << "Not found" << endl;
				else cout << "Found Value: " << *value << endl;
				break;
			case 'm':
				cout << "enter value to remove: " << endl;
				cin >> actualValue;
				cout << "Before: " << cont << endl;
				value = cont.remove(actualValue);
				if (value == 0) cout << "Not found" << endl;
				else cout << "Removed Value: " << *value << endl;
				cout << "After: " << cont << endl;
				break;
			case 'n':
				cout << "Before: " << cont << endl;
				cont.removeAll();
				cout << "remove all elements from cont" << endl;
				cout << "After: " << cont << endl;
				break;
			case 'p':
				cout << cont << endl;
				break;
			case 'q':
				quit = true;
				break;
			default:
				cout << "Bad choice, try again" << endl;

		}

		cout << "\n\n";
	}
}


int main(int argc, char** argv) {

	IntGenerator intGenerator;
	tContainer_t<int,list<int*>> intListContainer;

	DataContainerGenerator dcGenerator;
	tContainer_t<DataContainer,deque<DataContainer*>> dcDeqContainer;

	char choice;

	cout << "Choose a test: " << endl;
	cout << "[1]: int with list" << endl;
	cout << "[2]: DataContainer with deque" << endl;
	cin >> choice;

	switch(choice) {
		case '1':
			test(intListContainer, intGenerator);
			break;
		case '2':
			test(dcDeqContainer, dcGenerator);
			break;
		default:
			cout << "bad choice, better luck next time" << endl;

	}

	return 0;

}