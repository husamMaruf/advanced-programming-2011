#pragma once

#include "Bank.h"
#include <string.h>

using namespace std;

class Tester {
public:
	Account* getAccount(int accountNumber) {
		vector<Account*>::iterator iter = Bank::getInstance()->m_accounts.begin();
		while (iter != Bank::getInstance()->m_accounts.end()) {
			if ((*iter)->getAccountNumber() == accountNumber) {
				return *iter;
			} else {
				iter++;
			}
		}
		return 0;
	}

	int openNewAccountWithDate(AccountType accountType, int savingPeriod, double percentOnDeposit, const cDate_t& openingDate) {
		return Bank::getInstance()->openNewAccount(accountType, savingPeriod, percentOnDeposit, openingDate);
	}
};

void main() {
		
	char answer;
	bool quit = false;
	int index;
	Tester tester;
	Account* account;
	string temp;

	AccountType accountType;
	double percentOnDeposit;
	int savingPeriod;

	int day;
	int month;
	int year;

	int accountNumber;

	Bank* bank = Bank::getInstance();

	while(!quit) {
		
		cout << "Make your choice:" << endl;
		cout << "[a] Open new account" << endl;
		cout << "[b] Remove account" << endl;
		cout << "[c] Invest in stock exchange and notify" << endl;
		cout << "[d] Give bonus to families accounts and notify" << endl;
		cout << "[e] Arrange meeting with clerk and notify" << endl;
		cout << "[f] Get saving period" << endl;
		cout << "[g] Get opening date" << endl;
		cout << "[h] Get percent on deposit" << endl;
		cout << "[i] Get account type" << endl;
		cout << "[j] Post message" << endl;
		cout << "[k] Notify " << endl;
		cout << "[q] quit" << endl;

		cin >> answer;

		switch(answer) {
			case 'a':
				cout << "Enter saving period: 3,7,10" << endl;
				cin >> savingPeriod;
				cout << "Enter percent on deposit" << endl;
				cin >> percentOnDeposit;
				cout << "Enter account type: 1,2,3" << endl;
				cin >> accountType;
				cout << "[1] with auto generated date" << endl;
				cout << "[2] with manully entered date" << endl;
				cin >> index;
				if (index == 1) {
					accountNumber = bank->openNewAccount(accountType,savingPeriod,percentOnDeposit);
				} else { // assuming 2 was entered, doesn't really matter
					cout << "enter day of month" << endl;
					cin >> day;
					cout << "enter month" << endl;
					cin >> month;
					cout << "enter year" << endl;
					cin >> year;
					accountNumber = tester.openNewAccountWithDate(accountType,savingPeriod,percentOnDeposit, cDate_t(day,month,year));
				}
				cout << "New account number: " << accountNumber << endl;
				break;
			case 'b':
				cout << "Enter account number:" << endl;
				cin >> index;
				bank->removeAccount(index);
				cout << "Finished" << endl;
				break;
			case 'c':
				bank->investInStockExchange();
				cout << "Finished" << endl;
				break;
			case 'd':
				bank->giveBonusToFamiliesAccounts();
				cout << "Finished" << endl;
				break;
			case 'e':
				bank->arrangeMeetingWithClerk();
				cout << "Finished" << endl;
				break;
			case 'f':
				cout << "Enter account number:" << endl;
				cin >> index;
				account = tester.getAccount(index);
				cout << "The saving period is:" << account->getSavingPeriod() << endl;
				break;
			case 'g':
				cout << "Enter account number:" << endl;
				cin >> index;
				account = tester.getAccount(index);
				cout << "The Opening date is:" << account->getOpeningDate() << endl;
				break;
			case 'h':
				cout << "Enter account number:" << endl;
				cin >> index;
				account = tester.getAccount(index);
				cout << "The percent on deposit:" << account->getPercentOnDeposit() << endl;
				break;
			case 'i':
				cout << "Enter account number:" << endl;
				cin >> index;
				account = tester.getAccount(index);
				switch (account->getAccountType()) {
					case 1:
						temp = "Stock Account";
						break;
					case 2:
						temp = "Normal Account";
						break;
					case 3:
						temp = "Family Account";
						break;
				}
				cout << "The account type is:" << temp << endl;
				break;
			case 'j':
				cout << "Enter account number:" << endl;
				cin >> index;
				cout << "Enter message:" << endl;
				cin >> temp;
				account = tester.getAccount(index);
				account->postMessage(temp);
				cout << "Message posted" << endl;
				break;
			case 'k':
				bank->Notify();
				cout << "Finished" << endl;
				break;
			case 'q':
				quit = true;
				break;
			default:
				cout << "Bad choice, try again" << endl;

		}

		cout << "\n\n";
	}
}
