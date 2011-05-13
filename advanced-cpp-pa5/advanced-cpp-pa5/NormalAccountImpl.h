#pragma once
#include "AccountImpl.h"

class NormalAccountImpl : public AccountImpl {
public:
    NormalAccountImpl(int savingPeriod, double percentOnDeposit, cDate_t openingDate);
    virtual ~NormalAccountImpl();
    
    virtual AccountType getAccountType();
    virtual void Update();
};