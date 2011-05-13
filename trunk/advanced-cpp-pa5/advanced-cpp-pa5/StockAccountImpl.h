#pragma once
#include "AccountImpl.h"

class StockAccountImpl : public AccountImpl {
	friend class AccountFactory;
public:
	virtual AccountType getAccountType();
    virtual void Update();
protected:
    StockAccountImpl(int savingPeriod, double percentOnDeposit, cDate_t openingDate);
    virtual ~StockAccountImpl();
};
