#include "StockAccountImpl.h"

StockAccountImpl::StockAccountImpl(int accountNumber, int savingPeriod, double percentOnDeposit, cDate_t openingDate) :
AccountImpl(accountNumber,savingPeriod,percentOnDeposit,openingDate) { }

StockAccountImpl::~StockAccountImpl() { }

void StockAccountImpl::Update() {
	cout << "Updated Stock account:" << endl;
	cout << *getMesssage() << endl;
}

AccountType StockAccountImpl::getAccountType() {
	return 1;
}