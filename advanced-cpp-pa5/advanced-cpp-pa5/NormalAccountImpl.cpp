#include "NormalAccountImpl.h"

NormalAccountImpl::NormalAccountImpl(int savingPeriod, double percentOnDeposit, cDate_t openingDate) :
AccountImpl(savingPeriod,percentOnDeposit,openingDate) { }

NormalAccountImpl::~NormalAccountImpl() { }

void NormalAccountImpl::Update() {
	cout << "Updated Normal account:" << endl;
	cout << *getMesssage() << endl;
}

AccountType NormalAccountImpl::getAccountType() {
	return 2;
}