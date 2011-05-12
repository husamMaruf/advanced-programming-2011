#pragma once

class AccountImpl {
public:
    AccountImpl(void);
    virtual ~AccountImpl(void);
    
    virtual void Update() = 0;
    
    SavingPeriod getSavingPeriod();
    Date getOpeningDate();
    double getPercentOnDeposit();
    AccountType getAccountType() = 0;
    
private:
    
    double percentOnDeposit;
    Date openedDate;
    SavingPeriod savingPeriod;

};
