#include "AccountImpl.h"

AccountImpl::AccountImpl(int _savingPeriod, double _percentOnDeposit, cDate_t _openingDate) :
	savingPeriod(_savingPeriod), 
	percentOnDeposit(_percentOnDeposit), 
	openingDate(_openingDate),
	message(new string("")) { }

AccountImpl::~AccountImpl() {
	delete message;
}

cDate_t AccountImpl::getOpeningDate() {
	return openingDate;
}

int AccountImpl::getSavingPeriod() {
	return savingPeriod;
}

double AccountImpl::getPercentOnDeposit() {
	return percentOnDeposit;
}

string* AccountImpl::getMesssage() {
	return message;
}

void AccountImpl::setMessage(const string& _message) {
	delete message;
	message = new string(_message);
}