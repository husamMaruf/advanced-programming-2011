#pragma once

#include "cDate_t.h"

typedef AccountType int;

class AccountImpl {
public:

    AccountImpl(int savingPeriod, double percentOnDeposit, cDate_t openingDate);
    virtual ~AccountImpl();
    
    virtual void Update() = 0;
    
    int getSavingPeriod();
    cDate_t getOpeningDate();
    double getPercentOnDeposit();
    virtual AccountType getAccountType() = 0;
    
private:
    
    double percentOnDeposit;
    cDate_t openedDate;
    int savingPeriod;

};