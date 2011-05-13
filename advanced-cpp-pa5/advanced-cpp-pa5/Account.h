#pragma once

#include "Observer.h"
#include "Subject.h"
#include "cDate_t.h"

typedef int AccountType;

class AccountImpl;

class Account : public Observer {
public:
        
    Account(Subject* subject, AccountType accountType, int accountNumber, int savingPeriod, double percentOnDeposit, cDate_t& openingDate);
    Account(Subject* subject, AccountType accountType, int accountNumber, int savingPeriod, double percentOnDeposit);
	virtual ~Account();
		
	virtual void Update(Subject* ChngSubject);

    int getSavingPeriod();
    cDate_t& getOpeningDate();
    double getPercentOnDeposit();
	AccountType getAccountType();
	void postMessage(const std::string& message);
	int getAccountNumber();

protected:
    AccountImpl* accountImpl;
};