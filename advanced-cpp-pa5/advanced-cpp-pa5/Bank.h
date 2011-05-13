#pragma once

#include <iostream>
#include <vector>
#include "Subject.h"
#include "Account.h"
#include "cDate_t.h"

using namespace std;

class Bank : public Subject {
public:

    static Bank* getInstance();
    static void destroyInstance();

	void investInStockExchange();
	void giveBonusToFamiliesAccounts();
	void arrangeMeetingWithClerk();

private:

    static Bank* instance;
	vector<Account*> m_accounts; 

    Bank();
    Bank(const Bank& bank);
    void operator=(const Bank& bank);
    virtual ~Bank();
};