#pragma once

#include "Player.h"

class AbsPlayerFactory {
public:
	virtual Player* createPlayer(int type) = 0;
	virtual void destroyPlayer(Player* player) { delete player; }
};