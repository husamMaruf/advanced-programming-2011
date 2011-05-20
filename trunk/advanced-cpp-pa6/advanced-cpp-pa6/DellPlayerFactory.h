#pragma once

#include "AbsPlayerFactory.h"
#include "DellDVDPlayer.h"
#include "DellCDPlayer.h"
#include "DellVCRPlayer.h"

class DellPlayerFactory : public AbsPlayerFactory {
public:
	Player* createPlayer(int type);
};

