#pragma once

#include "CDPlayer.h"

class LGCDPlayer : public CDPlayer {
public:
	virtual void start();
	virtual void stop();
	virtual void forward();
	virtual void rewind();
};