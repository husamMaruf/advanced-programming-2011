#include "FamilyAccountImpl.h"

FamilyAccountImpl::FamilyAccountImpl(int savingPeriod, double percentOnDeposit, cDate_t openingDate) :
AccountImpl(savingPeriod,percentOnDeposit,openingDate) { }

FamilyAccountImpl::~FamilyAccountImpl() { }

void FamilyAccountImpl::Update() {
	cout << "Updated Family account" << endl;
}

AccountType FamilyAccountImpl::getAccountType() {
	return 3;
}