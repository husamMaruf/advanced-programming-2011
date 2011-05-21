#pragma once

#include "VCRPlayer.h"

class DellVCRPlayer : public VCRPlayer {
public:
	friend class DellPlayerFactory;

	virtual void start();
	virtual void stop();
	virtual void forward();
	virtual void rewind();
	
private:

	DellVCRPlayer() {}
};