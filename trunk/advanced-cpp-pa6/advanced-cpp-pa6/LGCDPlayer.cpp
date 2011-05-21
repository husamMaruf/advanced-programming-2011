#include "LGCDPlayer.h"

using namespace std;

void LGCDPlayer::start() {
	Player::start();
	cout << "Playing LGCDPlayer" << endl;
}

void LGCDPlayer::stop() {
	Player::stop();
	cout << "Stopping LGCDPlayer" << endl;
}

void LGCDPlayer::forward() {
	Player::forward();
	cout << "Forward LGCDPlayer" << endl;
}

void LGCDPlayer::rewind() {
	Player::rewind();
	cout << "Rewind LGCDPlayer" << endl;
}