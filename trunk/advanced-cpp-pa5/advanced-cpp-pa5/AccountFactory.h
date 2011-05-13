#pragma once

#include "AccountImpl.h"
#include "FamilyAccountImpl.h"
#include "NormalAccountImpl.h"
#include "StockAccountImpl.h"
#include "cDate_t.h"

typedef int AccountType;

class AccountImpl;

class AccountFactory {

public:
	static AccountImpl* createAccount(AccountType accountType, int accountNumber, int savingPeriod, double getPercentOnDeposit, cDate_t openingDate);
	static void destroyAccount(AccountImpl* account);

private:
	AccountFactory();
	AccountFactory(const AccountFactory&);
	AccountFactory& operator=(const AccountFactory&);
	~AccountFactory();
};
