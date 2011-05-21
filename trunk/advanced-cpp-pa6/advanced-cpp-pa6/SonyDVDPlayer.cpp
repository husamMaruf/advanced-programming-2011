#include "SonyDVDPlayer.h"

using namespace std;

void SonyDVDPlayer::start() {
	Player::start();
	cout << "Playing SonyDVDPlayer" << endl;
}

void SonyDVDPlayer::stop() {
	Player::stop();
	cout << "Stopping SonyDVDPlayer" << endl;
}

void SonyDVDPlayer::forward() {
	Player::forward();
	cout << "Forward SonyDVDPlayer" << endl;
}

void SonyDVDPlayer::rewind() {
	Player::rewind();
	cout << "Rewind SonyDVDPlayer" << endl;
}