#include "NormalAccountImpl.h"

NormalAccountImpl::NormalAccountImpl(int accountNumber, int savingPeriod, double percentOnDeposit, const cDate_t& openingDate) :
AccountImpl(accountNumber,savingPeriod,percentOnDeposit,openingDate) { }

NormalAccountImpl::~NormalAccountImpl() { }

void NormalAccountImpl::Update() {
	cout << "Updated Normal account:" << endl;
	cout << *getMesssage() << endl;
}

AccountType NormalAccountImpl::getAccountType() const {
	return 2;
}