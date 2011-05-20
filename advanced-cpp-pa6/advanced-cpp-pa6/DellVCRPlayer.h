#pragma once

#include "VCRPlayer.h"

class DellVCRPlayer : public VCRPlayer {
public:
	virtual void start();
	virtual void stop();
	virtual void forward();
	virtual void rewind();
};