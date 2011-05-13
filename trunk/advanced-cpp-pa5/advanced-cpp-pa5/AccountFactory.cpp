#include "AccountFactory.h"

static AccountImpl* AccountFactory::createAccount(AccountType accountType, int savingPeriod, double getPercentOnDeposit, cDate_t openingDate) {
	switch (accountType) {
		case 1:
			return new StockAccountImpl(savingPeriod, getPercentOnDeposit, openingDate);			
		case 2:
			return new NormalAccountImpl(savingPeriod, getPercentOnDeposit, openingDate);
		case 3:
			return new FamilyAccountImpl(savingPeriod, getPercentOnDeposit, openingDate);
	}			
}

static void AccountFactory::destroyAccount(AccountImpl* account) {
	delete account;			
}
