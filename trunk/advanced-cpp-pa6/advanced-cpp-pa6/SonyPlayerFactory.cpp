#include "SonyPlayerFactory.h"

Player* SonyPlayerFactory::createPlayer(int type) {
	Player* player = 0;
	switch (type) {
		case 1:
			player = new SonyDVDPlayer();
			break;
		case 3:
			player = new SonyVCRPlayer();
			break;
	}
	return player;
}