#pragma once

#include "Player.h"

using namespace std;

class DVDPlayer : public Player {
public:
	virtual void start() { cout << "DVD Starting" << endl; }
	virtual void stop() { cout << "DVD Stoping" << endl; }
	virtual void forward() { cout << "DVD forwarding" << endl; }
	virtual void rewind() { cout << "DVD rewinding" << endl; }

};