#include "AccountImpl.h"

AccountImpl::AccountImpl(int _savingPeriod, double _percentOnDeposit, cDate_t _openingDate) :
	savingPeriod(_savingPeriod), 
	percentOnDeposit(_percentOnDeposit), 
	openingDate(_openingDate) { }

AccountImpl::~AccountImpl() {

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