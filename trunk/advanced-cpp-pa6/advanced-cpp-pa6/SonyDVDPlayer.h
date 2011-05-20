#pragma once

#include "DVDPlayer.h"

class SonyDVDPlayer : public DVDPlayer {
public:
	virtual void start();
	virtual void stop();
	virtual void forward();
	virtual void rewind();
};