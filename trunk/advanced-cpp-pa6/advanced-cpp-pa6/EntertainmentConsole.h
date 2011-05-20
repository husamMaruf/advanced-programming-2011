#pragma once

#include "Player.h"
#include "DVDPlayer.h"
#include "CDPlayer.h"
#include "VCRPlayer.h"
#include "AbsConsoleFactory.h"
#include "DellConsoleFactory.h"
#include "LGConsoleFactory.h"
#include "SongConsoleFactory.h"

#include <map>
#include <iostream>
#include <string>

using namespace std;

class EntertainmentConsole {
public:
	explicit EntertainmentConsole(): idCounter(0) {}
	virtual ~EntertainmentConsole() {}

	int createPlayer(string brand, int type);
	bool removePlayer(int playerID);

	void playPlayer(int playerID);
	void stopPlayer(int playerID);
	void forwardPlayer(int playerID);
	void rewindPlayer(int playerID);

private:
	map<int,Player> players;
	int idCounter;
};
