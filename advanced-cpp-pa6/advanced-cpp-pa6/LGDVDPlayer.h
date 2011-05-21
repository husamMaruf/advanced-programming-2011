#pragma once

#include "DVDPlayer.h"

class LGDVDPlayer : public DVDPlayer {
public:
	friend class LGPlayerFactory;

	virtual void start();
	virtual void stop();
	virtual void forward();
	virtual void rewind();

private:

	LGDVDPlayer() {}
};