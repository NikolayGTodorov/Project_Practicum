#pragma once
#include <vector>
#include "Account.h"
#include "ISerializable.h"
class AccountManager
{
	static AccountManager* accountManager;
	std::vector<Account*> accounts;
	AccountManager();
public:
	static AccountManager* getAccountManagerInstance();

	void readAccountsFromFile();
	void writeAccountsToFile();

	std::string generateAccountNumber();
	void open();
	void close();
	void addCard();
	void deleteCard();
};

