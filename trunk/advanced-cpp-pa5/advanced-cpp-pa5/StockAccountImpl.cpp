#include "StockAccountImpl.h"

StockAccountImpl::StockAccountImpl(int accountNumber, int savingPeriod, double percentOnDeposit, const cDate_t& openingDate) :
AccountImpl(accountNumber,savingPeriod,percentOnDeposit,openingDate) { }

StockAccountImpl::~StockAccountImpl() { }

void StockAccountImpl::Update() {
	cout << "Updated Stock account:" << endl;
	cout << *getMesssage() << endl;
}

AccountType StockAccountImpl::getAccountType() const {
	return 1;
}