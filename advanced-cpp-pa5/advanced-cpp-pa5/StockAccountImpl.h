#pragma once
#include "AccountImpl.h"

class StockAccountImpl : public AccountImpl {
public:
    StockAccountImpl(int savingPeriod, double percentOnDeposit, cDate_t openingDate);
    virtual ~StockAccountImpl();
    
    virtual AccountType getAccountType();
    virtual void Update();
};
