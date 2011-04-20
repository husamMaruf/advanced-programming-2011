#include "tContainer_t.h"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

	int* n = new int;
	*n = 5;

	int* m = new int;
	*m = 6;

	int* l = new int;
	*l = 5;

	tContainer_t<int, vector<int*>> vctContainer;
	vctContainer.append(n);
	vctContainer.append(m);
	vctContainer.append(l);
	
	tContainer_t<int, list<int*>> lstContainer;
	lstContainer.append(n);
	lstContainer.append(m);
	lstContainer.append(l);

	tContainer_t<int, list<int*>> lstContainer2 = lstContainer;

	tContainer_t<int, list<int*>> lstContainer3;
	lstContainer3.append(l);
	lstContainer3.append(m);
	lstContainer3.append(n);

	tContainer_t<int, list<int*>> lstContainer4;
	lstContainer4.append(l);
	lstContainer4.append(m);
	lstContainer4.append(n);
	lstContainer4 = lstContainer;

	int i = 5;
	int* ip1 = vctContainer.find(i);
	int* ip2 = lstContainer.find(i);
	int* ip3 = lstContainer2.find(i);
	int* ip4 = lstContainer3.find(i);
	int* ip5 = lstContainer4.find(i);
	
	cout << (ip1 == ip2) << endl;
	cout << (ip2 == ip3) << endl;
	cout << (ip3 == ip4) << endl;
	cout << (ip4 == ip5) << endl;
	cout << (ip5 == ip3) << endl;
	
	cout << "###" << endl;

	cout << (ip1 == n) << endl;
	cout << (ip1 == m) << endl;
	cout << (ip1 == l) << endl;

	cout << "###" << endl;

	cout << *vctContainer[0] << endl;
	cout << *vctContainer[1] << endl;
	cout << *vctContainer[2] << endl;

	cout << "###" << endl;

	cout << *lstContainer[0] << endl;
	cout << *lstContainer[1] << endl;
	cout << *lstContainer[2] << endl;

	cout << "###" << endl;

	cout << *lstContainer3[0] << endl;
	cout << *lstContainer3[1] << endl;
	cout << *lstContainer3[2] << endl;

	lstContainer += lstContainer3;

	cout << "###" << endl;

	cout << lstContainer.size() << endl;
	cout << lstContainer3.size() << endl;
	cout << lstContainer.empty() << endl;
	cout << lstContainer3.empty() << endl;

	cout << "###" << endl;

	cout << *lstContainer[0] << endl;
	cout << *lstContainer[1] << endl;
	cout << *lstContainer[2] << endl;
	cout << *lstContainer[3] << endl;
	cout << *lstContainer[4] << endl;
	cout << *lstContainer[5] << endl;
	
	cout << (lstContainer[0] == lstContainer[5]) << endl;

	cout << "####" << endl;

	tContainer_t<int, deque<int*>> deqContainer;
	int* i1 = new int;
	int* i2 = new int;
	int* i3 = new int;
	int* i5 = new int;

	*i1 = 1;
	*i2 = 2;
	*i3 = 3;
	*i5 = 5;

	deqContainer.append(i1);
	deqContainer.append(i2);
	deqContainer.append(i3);
	deqContainer.append(i5);

	cout << *deqContainer.front() << endl;
	cout << *deqContainer.back() << endl;

	cout << "###" << endl;

	cout << *deqContainer.find(2) << endl;
	cout << deqContainer.find(4) << endl;

	cout << "###" << endl;
	
	cout << "size: " << deqContainer.size() << endl;
	cout << *deqContainer.remove(2) << endl;
	cout << deqContainer.remove(4) << endl;
	cout << "size: " << deqContainer.size() << endl;

	cout << "###" << endl;

	deqContainer.removeAll();

	cout << deqContainer.empty() << endl;
	cout << deqContainer.size() << endl;

	cout << "###" << endl;
	cout << "vct:  " << vctContainer << endl;
	cout << "lst1: " << lstContainer << endl;
	cout << "lst2: " << lstContainer2 << endl;
	cout << "lst3: " << lstContainer3 << endl;
	cout << "lst4: " << lstContainer4 << endl;
	cout << "deq:  " << deqContainer << endl;

	cout << "###" << endl;

	//vctContainer += lstContainer4;

	cout << vctContainer << endl;
	cout << lstContainer4 << endl;

	system("Pause");

	return 0;

}