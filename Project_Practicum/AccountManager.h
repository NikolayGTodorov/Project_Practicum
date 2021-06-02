#pragma once
#include <vector>
#include "Account.h"
#include "ISerializable.h"
class AccountManager
{
	std::vector<Account*> accounts;
	AccountManager();
	static AccountManager* accountManager;
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

