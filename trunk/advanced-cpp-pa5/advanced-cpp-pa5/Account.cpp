#include "Account.h"
#include "AccountImpl.h"
#include "AccountFactory.h"

Account::Account(AccountType accountType, int savingPeriod, double percentOnDeposit, cDate_t& openingDate) {
	accountImpl = AccountFactory::createAccount(accountType, savingPeriod, percentOnDeposit, openingDate);
}

Account::Account(AccountType accountType, int savingPeriod, double percentOnDeposit) {
	accountImpl = AccountFactory::createAccount(accountType, savingPeriod, percentOnDeposit, cDate_t());
}

Account::~Account() {
	AccountFactory::destoryAccount(accountImpl);
	accountImpl = 0;
}

void Account::Update() {
	accountImpl->Update();
}

AccountType Account::getAccountType() {
	return accountImpl->getAccountType();
}

cDate_t& Account::getOpeningDate() {
	return accountImpl->getOpeningDate();
}

double Account::getPercentOnDeposit() {
	return accountImpl->getPercentOnDeposit();
}

int Account::getSavingPeriod() {
	return accountImpl->getSavingPeriod();
}