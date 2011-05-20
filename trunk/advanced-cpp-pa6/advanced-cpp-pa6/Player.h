#pragma once

#include <iostream>
#include <string>

class Player {
public:
	virtual Player(string _brand): brand(_brand) {}
	virtual ~Player();

	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void forward() = 0;
	virtual void rewind() = 0;

	string getBrand() { return brand; }

private:
	string brand;
};