#pragma once
#include "AccountImpl.h"

class NormalAccountImpl : public AccountImpl {
	friend class AccountFactory;
public:
    virtual void Update();
	virtual AccountType getAccountType();
protected:
	NormalAccountImpl(int accountNumber, int savingPeriod, double percentOnDeposit, cDate_t openingDate);
    virtual ~NormalAccountImpl();
};