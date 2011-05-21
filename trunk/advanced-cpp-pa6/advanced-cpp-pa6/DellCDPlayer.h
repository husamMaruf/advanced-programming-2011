#pragma once

#include "CDPlayer.h"

class DellCDPlayer : public CDPlayer {
public:
	friend class DellPlayerFactory;

	virtual void start();
	virtual void stop();
	virtual void forward();
	virtual void rewind();

private:
	DellCDPlayer() {}
	DellCDPlayer(const CDPlayer&);
	DellCDPlayer& operator=(const CDPlayer&);
};