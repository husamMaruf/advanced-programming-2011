#include "Account.h"
#include "AccountImpl.h"
#include "AccountFactory.h"

Account::Account(Subject* subject, AccountType accountType, int accountNumber, int savingPeriod, double percentOnDeposit, const cDate_t& openingDate) {
	sbj = subject;
	sbj->Attach(this);
	accountImpl = AccountFactory::createAccount(accountType, accountNumber, savingPeriod, percentOnDeposit, openingDate);
}

Account::Account(Subject* subject, AccountType accountType, int accountNumber, int savingPeriod, double percentOnDeposit) {
	sbj = subject;
	sbj->Attach(this);
	accountImpl = AccountFactory::createAccount(accountType, accountNumber, savingPeriod, percentOnDeposit, cDate_t()); //Maybe should be on heap???
}

Account::~Account() {
	sbj->Detach(this); 
	AccountFactory::destroyAccount(accountImpl);
	accountImpl = 0;
}

void Account::Update(Subject* ChngSubject) {
	if(sbj == ChngSubject) {
		accountImpl->Update();
		clearChanged();
	}
}

const cDate_t& Account::getOpeningDate() const {
	return accountImpl->getOpeningDate();
}

double Account::getPercentOnDeposit() const {
	return accountImpl->getPercentOnDeposit();
}

int Account::getSavingPeriod() const {
	return accountImpl->getSavingPeriod();
}

AccountType Account::getAccountType() const {
	return accountImpl->getAccountType();
}

void Account::postMessage(const std::string& message) {
	setChanged();
	accountImpl->setMessage(message);
}

int Account::getAccountNumber() const {
	return accountImpl->getAccountNumber();
}