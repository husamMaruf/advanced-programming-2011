#pragma once

#include "cDate_t.h"

typedef int AccountType;

class AccountImpl;

class Account {
public:
        
    virtual ~Account(void);
    Account(AccountType accountType, int savingPeriod, double percentOnDeposit, cDate_t& openingDate);
    Account(AccountType accountType, int savingPeriod, double percentOnDeposit);
   
    virtual void Update();

    int getSavingPeriod();
    cDate_t& getOpeningDate();
    double getPercentOnDeposit();
    AccountType getAccountType();
    
protected:
    
    AccountImpl* accountImpl;
};