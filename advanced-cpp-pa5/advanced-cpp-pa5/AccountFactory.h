#pragma once

class AccountImpl;

class AccountFactory {

	static AccountImpl* createAccount();

private:
	AccountFactory();
	~AccountFactory();
};
