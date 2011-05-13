#pragma once

#include "cDate_t.h"

typedef int AccountType;

class AccountImpl {
	
	friend class AccountFactory;

public:
   
    virtual void Update() = 0;
    
    int getSavingPeriod();
    cDate_t getOpeningDate();
    double getPercentOnDeposit();
    
protected:

	AccountImpl(int savingPeriod, double percentOnDeposit, cDate_t openingDate);
    virtual ~AccountImpl();

private:

    double percentOnDeposit;
    cDate_t openingDate;
    int savingPeriod;

};