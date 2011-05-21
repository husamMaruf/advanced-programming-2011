#include "EntertainmentConsole.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	char answer;
	bool quit = false;
	int index;
	string temp;
	bool success;

	EntertainmentConsole console;

	while(!quit) {
		cout << "Make your choice:" << endl;
		cout << "[c] change player" << endl;
		cout << "[p] Play current player" << endl;
		cout << "[s] Stop current player" << endl;
		cout << "[f] Forward current player" << endl;
		cout << "[r] Rewind current player" << endl;
		cout << "[q] Quit" << endl;

		cin >> answer;

		switch(answer) {
		case 'c':
			cout << "Choose player brand: ([1] Dell, [2] LG, [3] Sony)" << endl;
			cin >> index;
			switch(index) {
			case 1:
				temp = "Dell";
				break;
			case 2:
				temp = "LG";
				break;
			case 3:
				temp = "Sony";
				break;
			default:
				cout << "Bad choice, try again next time" << endl;
				continue;
			}
			cout << "Choose player type: [1] DVD, [2] CD, [3] VCR" << endl;
			cin >> index;
			if (index < 1 || index > 3) {
				cout << "Bad choice, try again next time" << endl;
				continue;
			}
			success = console.switchPlayer(temp, index);
			if (success) {
				cout << "Changed successfully" << endl;
			} else {
				cout << "Failed changing, device probably doesn't exist" << endl;
			}
			break;
		case 'p':
			console.play();
			break;
		case 's':
			console.stop();
			break;
		case 'f':
			console.forward();
			break;
		case 'r':
			console.rewind();
			break;
		case 'q':
			quit = true;
			break;
		default:
			cout << "Bad choice, try again" << endl;
		}

		cout << "\n\n";
	}

}