#pragma once
#include <vector>
#include "Account.h"
#include "ISerializable.h"
class AccountManager
{
	std::vector<Account*> mAccounts;
	AccountManager();
	~AccountManager();
	static AccountManager* accountManager;
public:
	static AccountManager* getAccountManagerInstance();
	static void releaseAccountManagerInstance();
	void readAccountsFromFile();
	void writeAccountsToFile();

	std::string generateAccountNumber(std::string egn);
	void open();
	void close();
	void addCard();
	void deleteCard();
};

