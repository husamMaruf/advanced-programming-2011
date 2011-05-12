#pragma once

class AccountImpl;

class Account {
public:
        
    virtual ~Account(void);
    Account();
   
    virtual void Update();

    SavingPeriod getSavingPeriod();
    Date getOpeningDate();
    double getPercentOnDeposit();
    AccountType getAccountType();
    

protected:
    
    AccountImpl* accountImpl;
};

enum SavingPeriod {
    ThreeYears = 3,
    SevenYears = 7,
    TenYears = 10;
}

enum AccountType {
    FamilyAccount,
    NormalAccount,
    StockAccount;
}

struct Date {
    int day;
    int month;
    int year;
}