#include "StockAccountImpl.h"

StockAccountImpl::StockAccountImpl(int savingPeriod, double percentOnDeposit, cDate_t openingDate) :
AccountImpl(savingPeriod,percentOnDeposit,openingDate) { }

StockAccountImpl::~StockAccountImpl() { }

void StockAccountImpl::Update() {
	cout << "Updated Stock account" << endl;
}

