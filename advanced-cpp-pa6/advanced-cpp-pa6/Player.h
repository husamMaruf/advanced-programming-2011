#pragma once

#include <iostream>

class Player {
public:

	Player() { }
	virtual ~Player() { }

	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void forward() = 0;
	virtual void rewind() = 0;

};