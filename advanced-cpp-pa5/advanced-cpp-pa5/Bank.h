#pragma once

#include <iostream>
#include <vector>
#include "Account.h"
#include "cDate_t.h"

using namespace std;

class Bank {
public:

    static Bank* getInstance();
    static void destroyInstance();
    
    struct Predicate {
        boolean operator()(Account* account) = 0;
    };

protected:
    virtual ~Bank();
    
    virtual void Attach(Account*);
    virtual void Detach(Account*);
    virtual void Notify(Predicate& pred);

private:

    static Bank* instance;

    Bank();
    Bank(const Bank& bank);
    void operator=(const Bank& bank);
    
    vector<Account*> m_accounts; 

	struct FamilyAccountFilter: public Predicate {
        boolean operator()(Account* account);
    };

	struct LongPeriodAccountFilter: public Predicate {
        boolean operator()(Account* account);
    };

	struct NormalAccountExpireFilter: public Predicate {
        boolean operator()(Account* account);
    };
};