#pragma once

#include "Subject.h"

class Bank : public Subject {
public:

	static Bank* getInstance();
	static void destroyInstance();

protected:
	virtual ~Bank();

private:

	static Bank* instance;

	Bank();
	Bank(const Bank& bank);
	void operator=(const Bank& bank);
};
