#pragma once

#include "DVDPlayer.h"

class SonyDVDPlayer : public DVDPlayer {
public:
	friend class SonyPlayerFactory;

	virtual void start();
	virtual void stop();
	virtual void forward();
	virtual void rewind();
	
private:

	SonyDVDPlayer() {}
};