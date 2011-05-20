#pragma once

#include "Player.h"

using namespace std;

class VCRPlayer : public Player {
public:
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void forward() = 0;
	virtual void rewind() = 0;
};