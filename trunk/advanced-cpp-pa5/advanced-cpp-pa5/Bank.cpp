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

void Bank::Attach (Account* account) { 
    m_accounts.push_back(ob); 
} 

void Bank::Detach (Account* account) { 
    int i=0; 
    for (i = 0; i < m_accounts.size(); i++) 
        if (m_accounts[i] == ob) break; 
    m_accounts.erase(m_accounts.begin() + i); 
} 

void Bank::Notify (Predicate& pred) { 
    for (int i = 0; i < m_accounts.size(); i++) {
        if (pred(m_accounts[i]) {      
            (m_accounts[i])->Update(this); 
        }
    }
}

struct NoFilter: public Predicate {
    boolean operator()(const Account& account) { 
		return true; 
	}
}

struct FamilyAccountFilter: public Predicate {
	boolean operator()(const Account& account) {
		return account.getAccountType() == 3;
	}
}

struct LongPeriodAccountFilter: public Predicate {
	boolean operator()(const Account& account) {
		if (account.getSavingPeriod() == 10) {
			return account.getOpeningDate().calcYearsElapsed() <= 5;
		}
		return false;
	}
}

struct NormalAccountExpireFilter: public Predicate {
	boolean operator()(const Account& account) {
		if (account.getAccountType()) {
			return account.getOpeningDate().calcYearsElapsed() >= 2;
		}
		return false;
	}
}

