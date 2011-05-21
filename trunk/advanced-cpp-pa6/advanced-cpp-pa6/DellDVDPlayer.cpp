#include "DellDVDPlayer.h"

using namespace std;

void DellDVDPlayer::start() {
	Player::start();
	cout << "Playing DellDVDPlayer" << endl;
}

void DellDVDPlayer::stop() {
	Player::stop();
	cout << "Stopping DellDVDPlayer" << endl;
}

void DellDVDPlayer::forward() {
	Player::forward();
	cout << "Forward DellDVDPlayer" << endl;
}

void DellDVDPlayer::rewind() {
	Player::rewind();
	cout << "Rewind DellDVDPlayer" << endl;
}