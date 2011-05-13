#include "Bank.h"

Bank* Bank::instance = 0;

Bank::Bank() {}

Bank::~Bank() {}

Bank* Bank::getInstance() {
    if (instance == 0) {
        instance = new Bank;
    }
    return instance;
}

void Bank::destroyInstance() {
    delete instance;
	instance = 0;
}
