#pragma once
#include "AccountImpl.h"

class FamilyAccountImpl : public AccountImpl {
public:
    FamilyAccountImpl(int savingPeriod, double percentOnDeposit, cDate_t openingDate);
    virtual ~FamilyAccountImpl();
   
    virtual AccountType getAccountType();
    virtual void Update();
};