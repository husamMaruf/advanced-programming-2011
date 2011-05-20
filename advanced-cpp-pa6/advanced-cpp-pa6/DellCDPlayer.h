#pragma once

#include "CDPlayer.h"

class DellCDPlayer : public CDPlayer {
public:
	virtual void start();
	virtual void stop();
	virtual void forward();
	virtual void rewind();
};