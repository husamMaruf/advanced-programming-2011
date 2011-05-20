#pragma once

#include "Player.h"

class AbsConsoleFactory {
public:
	virtual Player* CreatePlayer(int type) = 0;
	virtual void DestroyPlayer(Player* player) { delete player; }
};