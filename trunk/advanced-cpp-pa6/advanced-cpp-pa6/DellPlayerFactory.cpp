#include "DellPlayerFactory.h"

Player* DellPlayerFactory::createPlayer(int type) {
	Player* player = 0;
	switch (type) {
		case 1:
			player = new DellDVDPlayer();
			break;
		case 2:
			player = new DellCDPlayer();
			break;
		case 3:
			player = new DellVCRPlayer();
			break;
	}
	return player;
}