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

	bool accountWithNumberExists(std::string accountNumber);
	std::string generateAccountNumber(std::string egn);
	void addAccount(std::string egn, double balance);
	bool removeAccount(std::string egn, std::string accountNumber);
	void addCard();
	void deleteCard();
};

