#pragma once

#include "Player.h"

using namespace std;

class VCRPlayer : public Player {
public:
	virtual void start() { cout << "VCR Starting" << endl; }
	virtual void stop() { cout << "VCR Stoping" << endl; }
	virtual void forward() { cout << "VCR forwarding" << endl; }
	virtual void rewind() { cout << "VCR rewinding" << endl; }

};