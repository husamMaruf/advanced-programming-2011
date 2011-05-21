#pragma once

#include "DVDPlayer.h"

class DellDVDPlayer : public DVDPlayer {
public:
	friend class DellPlayerFactory;

	virtual void start();
	virtual void stop();
	virtual void forward();
	virtual void rewind();

private:
	DellDVDPlayer() {}
	DellDVDPlayer(const DellDVDPlayer&);
	DellDVDPlayer& operator=(const DellDVDPlayer&);
};