#pragma once

#include "AbsConsoleFactorty.h"
#include "DVDPlater.h"
#include "VCRPlater.h"

class SonyConsoleFactory : public AbsConsoleFactory {
public:
	Player* CreatePlayer(int type) {
		Player* player = 0;
		switch (type) {
			case 1:
				player = new DVDPlayer("Sony");
				break;
			case 3:
				player = new VCRPlayer("Sony");
				break;
		}
		return player;
	}
};