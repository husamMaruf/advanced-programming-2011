#include "FamilyAccountImpl.h"

FamilyAccountImpl::FamilyAccountImpl(int accountNumber, int savingPeriod, double percentOnDeposit, cDate_t openingDate) :
AccountImpl(accountNumber,savingPeriod,percentOnDeposit,openingDate) { }

FamilyAccountImpl::~FamilyAccountImpl() { }

void FamilyAccountImpl::Update() {
	cout << "Updated Family account:" << endl;
	cout << *getMesssage() << endl;
}

AccountType FamilyAccountImpl::getAccountType() {
	return 3;
}