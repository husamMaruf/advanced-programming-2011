#include "EntertainmentConsole.h"

using namespace std;

int EntertainmentConsole::createPlayer(string brand, int type) {
	AbsConsoleFactory* factory;
	if (brand == "Dell") {
		factory = new DellConsoleFactory();
	} else if (brand == "LG") {
		factory = new LGConsoleFactory();
	} else if (brand == "Sony") {
		factory = new SonyConsoleFactory();
	}
	players[idCounter] = factory->CreatePlayer(type);
	delete factory;
}

bool EntertainmentConsole::removePlayer(int playerID) {
	//TODO
}

void EntertainmentConsole::playPlayer(int playerID) {
	players[playerID].start():
}

void EntertainmentConsole::stopPlayer(int playerID) {
	players[playerID].stop():
}

void EntertainmentConsole::forwardPlayer(int playerID) {
	players[playerID].forward():
}

void EntertainmentConsole::rewindPlayer(int playerID) {
	players[playerID].rewind():
}
