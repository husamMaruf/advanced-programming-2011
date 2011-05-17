#pragma once

#include "cDate_t.h"
#include <string.h>

typedef int AccountType;

class AccountImpl {
	
	friend class AccountFactory;

public:
   
    virtual void Update() = 0;
	virtual AccountType getAccountType() const = 0;

    int getSavingPeriod() const;
    const cDate_t& getOpeningDate() const;
    double getPercentOnDeposit() const;
    
	int getAccountNumber() const;

	void setMessage(const string& message);

protected:

	AccountImpl(int accountNumber, int savingPeriod, double percentOnDeposit, const cDate_t& openingDate);
    virtual ~AccountImpl();
	const string* getMesssage() const;

private:

    double percentOnDeposit;
    cDate_t openingDate;
    int savingPeriod;
	string* message;
	int accountNumber;

};