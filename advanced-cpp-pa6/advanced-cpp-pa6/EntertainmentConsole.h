#pragma once

#include "Player.h"
#include "DVDPlayer.h"
#include "CDPlayer.h"
#include "VCRPlayer.h"
#include "AbsPlayerFactory.h"
#include "DellPlayerFactory.h"
#include "LGPlayerFactory.h"
#include "SonyPlayerFactory.h"

#include <iostream>
#include <string>

using namespace std;

class EntertainmentConsole {
public:
	explicit EntertainmentConsole();
	virtual ~EntertainmentConsole();

	bool switchPlayer(const string& brand, int type);

	void play();
	void stop();
	void forward();
	void rewind();

private:

	void handleSwitchPlayer(Player* previousPlayer);

	Player* currentPlayer;

	DellCDPlayer* dellCDPlayer;
	DellDVDPlayer* dellDVDPlayer;
	DellVCRPlayer* dellVCRPlayer;
	LGCDPlayer* lgCDPlayer;
	LGDVDPlayer* lgDVDPlayer;
	SonyDVDPlayer* sonyDVDPlayer;
	SonyVCRPlayer* sonyVCRPlayer;

};
