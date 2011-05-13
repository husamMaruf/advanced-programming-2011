#pragma once
#include "AccountImpl.h"

class StockAccountImpl : public AccountImpl {
	friend class AccountFactory;
public:
    virtual void Update();
	virtual AccountType getAccountType();
protected:
    StockAccountImpl(int accountNumber, int savingPeriod, double percentOnDeposit, cDate_t openingDate);
    virtual ~StockAccountImpl();
};
