#pragma once

#include "VCRPlayer.h"

class SonyVCRPlayer : public VCRPlayer {
public:
	friend class SonyPlayerFactory;

	virtual void start();
	virtual void stop();
	virtual void forward();
	virtual void rewind();
		
private:
	SonyVCRPlayer() {}
	SonyVCRPlayer(const SonyVCRPlayer&);
	SonyVCRPlayer& operator=(const SonyVCRPlayer&);
};