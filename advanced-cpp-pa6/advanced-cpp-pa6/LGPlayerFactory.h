#pragma once

#include "AbsPlayerFactory.h"
#include "LGDVDPlayer.h"
#include "LGCDPlayer.h"

class LGPlayerFactory : public AbsPlayerFactory {
public:
	Player* createPlayer(int type);
};