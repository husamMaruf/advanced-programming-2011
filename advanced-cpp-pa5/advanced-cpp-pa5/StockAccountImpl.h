#pragma once
#include "AccountImpl.h"

class StockAccountImpl : public AccountImpl {
	friend class AccountFactory;
public:
    virtual void Update();
	virtual AccountType getAccountType() const;
protected:
    StockAccountImpl(int accountNumber, int savingPeriod, double percentOnDeposit, const cDate_t& openingDate);
    virtual ~StockAccountImpl();
};
