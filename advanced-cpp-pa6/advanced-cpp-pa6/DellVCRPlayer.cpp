#include "DellVCRPlayer.h"

using namespace std;

void DellVCRPlayer::start() {
	Player::start();
	cout << "Playing DellVCRPlayer" << endl;
}

void DellVCRPlayer::stop() {
	Player::stop();
	cout << "Stopping DellVCRPlayer" << endl;
}

void DellVCRPlayer::forward() {
	Player::forward();
	cout << "Forward DellVCRPlayer" << endl;
}

void DellVCRPlayer::rewind() {
	Player::rewind();
	cout << "Rewind DellVCRPlayer" << endl;
}