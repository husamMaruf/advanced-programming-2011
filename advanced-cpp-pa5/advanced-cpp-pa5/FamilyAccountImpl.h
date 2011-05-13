#pragma once
#include "AccountImpl.h"

class FamilyAccountImpl : public AccountImpl {
	friend class AccountFactory;
public:
	virtual AccountType getAccountType();
    virtual void Update();
protected:
    FamilyAccountImpl(int savingPeriod, double percentOnDeposit, cDate_t openingDate);
    virtual ~FamilyAccountImpl();
};