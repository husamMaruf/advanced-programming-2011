#include "SonyVCRPlayer.h"

using namespace std;

void SonyVCRPlayer::start() {
	Player::start();
	cout << "Playing SonyVCRPlayer" << endl;
}

void SonyVCRPlayer::stop() {
	Player::stop();
	cout << "Stopping SonyVCRPlayer" << endl;
}

void SonyVCRPlayer::forward() {
	Player::forward();
	cout << "Forward SonyVCRPlayer" << endl;
}

void SonyVCRPlayer::rewind() {
	Player::rewind();
	cout << "Rewind SonyVCRPlayer" << endl;
}