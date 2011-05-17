#include "AccountFactory.h"

AccountImpl* AccountFactory::createAccount(AccountType accountType, int accountNumber, int savingPeriod, double getPercentOnDeposit, const cDate_t& openingDate) {
	switch (accountType) {
		case 1:
			return new StockAccountImpl(accountNumber, savingPeriod, getPercentOnDeposit, openingDate);			
		case 2:
			return new NormalAccountImpl(accountNumber, savingPeriod, getPercentOnDeposit, openingDate);
		case 3:
			return new FamilyAccountImpl(accountNumber, savingPeriod, getPercentOnDeposit, openingDate);
	}			
}

void AccountFactory::destroyAccount(AccountImpl* account) {
	delete account;			
}
