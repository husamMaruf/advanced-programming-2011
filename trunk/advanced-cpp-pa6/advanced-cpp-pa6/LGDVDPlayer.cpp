#include "LGDVDPlayer.h"

using namespace std;

void LGDVDPlayer::start() {
	Player::start();
	cout << "Playing LGDVDPlayer" << endl;
}

void LGDVDPlayer::stop() {
	Player::stop();
	cout << "Stopping LGDVDPlayer" << endl;
}

void LGDVDPlayer::forward() {
	Player::forward();
	cout << "Forward LGDVDPlayer" << endl;
}

void LGDVDPlayer::rewind() {
	Player::rewind();
	cout << "Rewind LGDVDPlayer" << endl;
}