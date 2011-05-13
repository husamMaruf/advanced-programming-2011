#pragma once

#include <iostream>
#include <vector>
#include "Subject.h"
#include "Account.h"
#include "AccountFactory.h"
#include "cDate_t.h"

using namespace std;

typedef int AccountType;

class Bank : public Subject {
public:

    static Bank* getInstance();
    static void destroyInstance();

	int openNewAccount(AccountType accountType, int savingPeriod, double percentOnDeposit);
	void removeAccount(int accountNumber);

	void investInStockExchange();
	void giveBonusToFamiliesAccounts();
	void arrangeMeetingWithClerk();

private:

    static Bank* instance;
	vector<Account*> m_accounts; 
	int accountNumberCounter;

    Bank();
    Bank(const Bank& bank);
    void operator=(const Bank& bank);
    virtual ~Bank();
};