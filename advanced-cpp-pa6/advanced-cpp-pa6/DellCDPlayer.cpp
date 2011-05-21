#include "DellCDPlayer.h"

using namespace std;

void DellCDPlayer::start() {
	Player::start();
	cout << "Playing DellCDPlayer" << endl;
}

void DellCDPlayer::stop() {
	Player::stop();
	cout << "Stopping DellCDPlayer" << endl;
}

void DellCDPlayer::forward() {
	Player::forward();
	cout << "Forward DellCDPlayer" << endl;
}

void DellCDPlayer::rewind() {
	Player::rewind();
	cout << "Rewind DellCDPlayer" << endl;
}