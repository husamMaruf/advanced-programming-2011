#include "EntertainmentConsole.h"

using namespace std;

EntertainmentConsole::EntertainmentConsole() {
	// setup console
	DellPlayerFactory* dellPlayerFactory = new DellPlayerFactory();
	LGPlayerFactory* lgPlayerFactory = new LGPlayerFactory();
	SonyPlayerFactory* sonyPlayerFactory = new SonyPlayerFactory();

	dellDVDPlayer = (DellDVDPlayer*)dellPlayerFactory->createPlayer(1);
	dellCDPlayer = (DellCDPlayer*)dellPlayerFactory->createPlayer(2);
	dellVCRPlayer = (DellVCRPlayer*)dellPlayerFactory->createPlayer(3);

	lgDVDPlayer = (LGDVDPlayer*)lgPlayerFactory->createPlayer(1);
	lgCDPlayer = (LGCDPlayer*)lgPlayerFactory->createPlayer(2);

	sonyDVDPlayer = (SonyDVDPlayer*)sonyPlayerFactory->createPlayer(1);
	sonyVCRPlayer = (SonyVCRPlayer*)sonyPlayerFactory->createPlayer(3);

	delete dellPlayerFactory;
	delete lgPlayerFactory;
	delete sonyPlayerFactory;

	// arbitrarily choose a player as current player
	currentPlayer = dellDVDPlayer;

}

EntertainmentConsole::~EntertainmentConsole() {

	if (currentPlayer != 0) {
		currentPlayer->stop();
	}

	DellPlayerFactory* dellPlayerFactory = new DellPlayerFactory();
	LGPlayerFactory* lgPlayerFactory = new LGPlayerFactory();
	SonyPlayerFactory* sonyPlayerFactory = new SonyPlayerFactory();

	dellPlayerFactory->destroyPlayer(dellDVDPlayer);
	dellPlayerFactory->destroyPlayer(dellCDPlayer);
	dellPlayerFactory->destroyPlayer(dellVCRPlayer);

	lgPlayerFactory->destroyPlayer(lgDVDPlayer);
	lgPlayerFactory->destroyPlayer(lgCDPlayer);

	sonyPlayerFactory->destroyPlayer(sonyDVDPlayer);
	sonyPlayerFactory->destroyPlayer(sonyVCRPlayer);

	delete dellPlayerFactory;
	delete lgPlayerFactory;
	delete sonyPlayerFactory;

}

bool EntertainmentConsole::switchPlayer(const string& brand, int type) {
	
	Player* previousPlayer = currentPlayer;
	
	if (brand == "Dell" && (type == 1 || type == 2 || type == 3)) {
		switch(type) {
		case 1: 
			currentPlayer = dellDVDPlayer;
			break;
		case 2:
			currentPlayer = dellCDPlayer;
			break;
		case 3:
			currentPlayer = dellVCRPlayer;
			break;
		}
		handleSwitchPlayer(previousPlayer);
	} else if (brand == "LG" && (type == 1 || type == 2)) {
		switch(type) {
		case 1:
			currentPlayer = lgDVDPlayer;
			break;
		case 2:
			currentPlayer = lgCDPlayer;
			break;
		}
		handleSwitchPlayer(previousPlayer);
	} else if (brand == "Sony" && (type == 1 || type == 3)) {
		switch(type) {
		case 1:
			currentPlayer = sonyDVDPlayer;
			break;
		case 3:
			currentPlayer = sonyVCRPlayer;
			break;
		}
		handleSwitchPlayer(previousPlayer);
	} else {
		return false;
	}

	return true;
}

void EntertainmentConsole::play() {
	currentPlayer->start();
}

void EntertainmentConsole::stop() {
	currentPlayer->stop();
}

void EntertainmentConsole::forward() {
	currentPlayer->forward();
}

void EntertainmentConsole::rewind() {
	currentPlayer->rewind();
}

void EntertainmentConsole::handleSwitchPlayer(Player* previousPlayer) {
	if (previousPlayer != 0) {
		// this is an idempotent instruction so we don't really care if
		// the player is actually doing something
		previousPlayer->stop();
	}
}

void main() { }