#pragma once

#include "CDPlayer.h"

class LGCDPlayer : public CDPlayer {
public:
	friend class LGPlayerFactory;

	virtual void start();
	virtual void stop();
	virtual void forward();
	virtual void rewind();

private:

	LGCDPlayer() {}
};