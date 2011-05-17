#include "Observer.h"

Observer::Observer() : changed(false) { }

Observer::~Observer() { }

void Observer::setChanged() { 
	changed = true;
}

void Observer::clearChanged() {
	changed = false;
}

bool Observer::isChanged() const {
	return changed;
}