#pragma once

#include "AbsConsoleFactory.h"
#include "DVDPlayer.h"
#include "CDPlayer.h"
#include "VCRPlayer.h"

class DellConsoleFactory : public AbsConsoleFactory {
public:
	Player* CreatePlayer(int type) {
		Player* player = 0;
		switch (type) {
			case 1:
				player = new DVDPlayer("Dell");
				break;
			case 2:
				player = new CDPlayer("Dell");
				break;
			case 3:
				player = new VCRPlayer("Dell");
				break;
		}
		return player;
	}
};