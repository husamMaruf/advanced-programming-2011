#pragma once

#include "AbsPlayerFactory.h"
#include "SonyDVDPlayer.h"
#include "SonyVCRPlayer.h"

class SonyPlayerFactory : public AbsPlayerFactory {
public:
	Player* createPlayer(int type);
};

