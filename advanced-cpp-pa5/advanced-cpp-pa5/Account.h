#pragma once

#include "cDate_t.h"

typedef AccountType int;

class AccountImpl;


class Account {
public:
        
    virtual ~Account(void);
    Account(AccountType accountType, int savingPeriod, double getPercentOnDeposit, cDate_t openingDate);
    Account(AccountType accountType, int savingPeriod, double getPercentOnDeposit);
   
    virtual void Update();

    int getSavingPeriod();
    cDate_t getOpeningDate();
    double getPercentOnDeposit();
    AccountType getAccountType();
    
protected:
    
    AccountImpl* accountImpl;
};