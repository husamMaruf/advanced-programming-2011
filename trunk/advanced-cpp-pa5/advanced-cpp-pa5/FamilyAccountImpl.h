#pragma once
#include "AccountImpl.h"

class FamilyAccountImpl : public AccountImpl {
	friend class AccountFactory;
public:
    virtual void Update();
	virtual AccountType getAccountType();
protected:
    FamilyAccountImpl(int accountNumber, int savingPeriod, double percentOnDeposit, cDate_t openingDate);
    virtual ~FamilyAccountImpl();
};