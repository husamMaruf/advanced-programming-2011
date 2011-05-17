#pragma once

#include "Observer.h"
#include "Subject.h"
#include "cDate_t.h"

typedef int AccountType;

class AccountImpl;

class Account : public Observer {
public:
        
    Account(Subject* subject, AccountType accountType, int accountNumber, int savingPeriod, double percentOnDeposit, const cDate_t& openingDate);
    Account(Subject* subject, AccountType accountType, int accountNumber, int savingPeriod, double percentOnDeposit);
	virtual ~Account();
		
	virtual void Update(Subject* ChngSubject);

    int getSavingPeriod() const;
    const cDate_t& getOpeningDate() const;
    double getPercentOnDeposit() const;
	AccountType getAccountType() const;
	void postMessage(const std::string& message);
	int getAccountNumber() const;

protected:
    AccountImpl* accountImpl;
};