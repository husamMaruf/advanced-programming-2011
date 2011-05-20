#include "LGPlayerFactory.h"

Player* LGPlayerFactory::createPlayer(int type) {
	Player* player = 0;
	switch (type) {
		case 1:
			player = new LGDVDPlayer();
			break;
		case 2:
			player = new LGCDPlayer();
			break;
	}
	return player;
}