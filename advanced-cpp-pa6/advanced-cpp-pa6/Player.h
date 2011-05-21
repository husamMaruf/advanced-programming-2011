#pragma once

#include <iostream>

class Player {
public:
	friend class AbsPlayerFactory;

	enum PlayerState {
		PLAY,
		STOP,
		FORWARD,
		REWIND
	};

	virtual void start() = 0 { setState(PLAY); }
	virtual void stop() = 0 { setState(STOP); }
	virtual void forward() = 0 { setState(FORWARD); }
	virtual void rewind() = 0 { setState(REWIND); }

	PlayerState getState() { return state; }
	void setState(PlayerState _state) { state = _state; }

protected:
	Player(): state(STOP) {}
	virtual ~Player() {}

private:
	PlayerState state;

};