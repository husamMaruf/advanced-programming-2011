#include "AccountImpl.h"

AccountImpl::AccountImpl(int _accountNumber, int _savingPeriod, double _percentOnDeposit, const cDate_t& _openingDate) :
	savingPeriod(_savingPeriod), 
	percentOnDeposit(_percentOnDeposit), 
	openingDate(_openingDate),
	message(new string("")),
	accountNumber(_accountNumber) { }

AccountImpl::~AccountImpl() {
	delete message;
}

const cDate_t& AccountImpl::getOpeningDate() const {
	return openingDate;
}

int AccountImpl::getSavingPeriod() const {
	return savingPeriod;
}

double AccountImpl::getPercentOnDeposit() const {
	return percentOnDeposit;
}

const string* AccountImpl::getMesssage() const {
	return message;
}

void AccountImpl::setMessage(const string& _message) {
	delete message;
	message = new string(_message);
}

int AccountImpl::getAccountNumber() const {
	return accountNumber;
}