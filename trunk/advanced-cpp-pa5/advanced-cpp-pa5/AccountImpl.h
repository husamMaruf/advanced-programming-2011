#pragma once

#include "cDate_t.h"
#include <string.h>

typedef int AccountType;

class AccountImpl {
	
	friend class AccountFactory;

public:
   
    virtual void Update() = 0;
	virtual AccountType getAccountType() = 0;

    int getSavingPeriod();
    cDate_t getOpeningDate();
    double getPercentOnDeposit();
    
	string* getMesssage();
	int getAccountNumber();

	void setMessage(const string& message);

protected:

	AccountImpl(int accountNumber, int savingPeriod, double percentOnDeposit, cDate_t openingDate);
    virtual ~AccountImpl();

private:

    double percentOnDeposit;
    cDate_t openingDate;
    int savingPeriod;
	string* message;
	int accountNumber;

};