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

void Bank::investInStockExchange() {
	for (int i = 0; i < m_accounts.size(); i++) {
		if (m_accounts[i]->getSavingPeriod() == 10 && m_accounts[i]->getOpeningDate().calcYearsElapsed() <= 5) {
			m_accounts[i]->postMessage("We invested money in stock exchange for your account");
			m_accounts[i]->setChanged();
		}
	}
	Bank::Notify();
}

void Bank::giveBonusToFamiliesAccounts() {
	for (int i = 0; i < m_accounts.size(); i++) {
		if (m_accounts[i]->getAccountType() == 3) {
			m_accounts[i]->postMessage("Your account was granted with a 500 Shakels bonus");
			m_accounts[i]->setChanged();
		}	
	}
	Bank::Notify();
}


void Bank::arrangeMeetingWithClerk() {
	for (int i = 0; i < m_accounts.size(); i++) {
		if (m_accounts[i]->getAccountType() == 1 && m_accounts[i]->getOpeningDate().calcYearsElapsed() >= 2) {
			m_accounts[i]->postMessage("Please come to the bank for a meeting with our clerk");
			m_accounts[i]->setChanged();
		}
	}
	Bank::Notify();
}
