#include "Bank.h"

Bank* Bank::instance = 0;

Bank::Bank(): accountNumberCounter(1) { }

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

int Bank::openNewAccount(AccountType accountType, int savingPeriod, double percentOnDeposit) {
	m_accounts.push_back(new Account(this,accountType,accountNumberCounter,savingPeriod,percentOnDeposit));
	accountNumberCounter++;
	return accountNumberCounter-1;
}

void Bank::removeAccount(int accountNumber) {
	vector<Account*>::iterator iter = m_accounts.begin();
	while (iter != m_accounts.end()) {
		if ((*iter)->getAccountNumber() == accountNumber) {
			Account* account = *iter;
			m_accounts.erase(iter);
			delete account;
			break;
		} else {
			iter++;
		}
	}
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
