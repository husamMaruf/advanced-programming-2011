#pragma once

#include "DVDPlayer.h"

class DellDVDPlayer : public DVDPlayer {
public:
	virtual void start();
	virtual void stop();
	virtual void forward();
	virtual void rewind();
};