#include "Account.h"
#include "AccountImpl.h"
#include "AccountFactory.h"

Account::Account(Subject* subject, AccountType accountType, int savingPeriod, double percentOnDeposit, cDate_t& openingDate) {
	sbj = subject;
	sbj->Attach(this);
	accountImpl = AccountFactory::createAccount(accountType, savingPeriod, percentOnDeposit, openingDate);
}

Account::Account(Subject* subject, AccountType accountType, int savingPeriod, double percentOnDeposit) {
	sbj = subject;
	sbj->Attach(this);
	accountImpl = AccountFactory::createAccount(accountType, savingPeriod, percentOnDeposit, cDate_t());
}

Account::~Account() {
	sbj->Detach(this); 
	AccountFactory::destroyAccount(accountImpl);
	accountImpl = 0;
}

void Account::Update(Subject* ChngSubject) {
	if(sbj == ChngSubject) {
		accountImpl->Update();
	}
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