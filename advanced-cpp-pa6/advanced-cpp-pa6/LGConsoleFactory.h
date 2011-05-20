#pragma once

#include "AbsConsoleFactorty.h"
#include "DVDPlater.h"
#include "CDPlater.h"

class LGConsoleFactory : public AbsConsoleFactory {
public:
	Player* CreatePlayer(int type) {
		Player* player = 0;
		switch (type) {
			case 1:
				player = new DVDPlayer("LG");
				break;
			case 2:
				player = new CDPlayer("LG");
				break;
		}
		return player;
	}
};