#pragma once

#include "Observer.h"

class AccountImpl;

class Account : public Observer {
public:
		
	virtual ~Account(void);
	Account();

protected:
	
	AccountImpl* accountImpl;


};
