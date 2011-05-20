#pragma once

#include "Player.h"

using namespace std;

class CDPlayer : public Player {
public:
	virtual void start() { cout << "CD Starting" << endl; }
	virtual void stop() { cout << "CD Stoping" << endl; }
	virtual void forward() { cout << "CD forwarding" << endl; }
	virtual void rewind() { cout << "CD rewinding" << endl; }

};