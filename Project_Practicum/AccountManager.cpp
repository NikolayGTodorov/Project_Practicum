#include "AccountManager.h"
#include "ClientManager.h"

AccountManager* AccountManager::accountManager = 0;

AccountManager::AccountManager() :
	mAccounts{ std::vector<Account*>() }
{
	//read all employees from File
	//set initialEmployeesCount to number of account read from file
}

AccountManager::~AccountManager()
{
	for (Account* acc : mAccounts) {
		delete acc;
	}
	mAccounts.clear();
}

AccountManager* AccountManager::getAccountManagerInstance()
{
	if (!accountManager) {
		accountManager = new AccountManager();
	}
	return accountManager;
}

void AccountManager::releaseAccountManagerInstance()
{
	delete accountManager;
}



bool AccountManager::accountWithNumberExists(std::string accountNumber)
{
	for (Account* acc : mAccounts) {
		if (acc->getAccountNumber() == accountNumber) {
			return 1;
		}
	}
	return 0;
}

std::string AccountManager::generateAccountNumber(std::string egn)
{
	ClientManager* clientManager = ClientManager::getClientManagerInstance();
	std::string temp = "00MYBANK" + egn.substr(6, 10) + std::to_string(clientManager->getClientByEgn(egn)->getAccountsCount());
	return temp;
}

void AccountManager::addAccount(std::string egn, double balance)
{
	std::string accountNumber = generateAccountNumber(egn);
	mAccounts.push_back(new Account(egn, accountNumber, balance));
	std::cout << "Account number" << accountNumber << '\n';
}

bool AccountManager::removeAccount(std::string egn, std::string accountNumber)
{
	if (accountWithNumberExists(accountNumber)) {
		int index = 0;
		for (Account* acc : mAccounts) {
			index++;
			if (acc->getAccountNumber() == accountNumber && acc->getOwnerEgn() == egn) {
				delete mAccounts[index];
				mAccounts.erase(mAccounts.begin() + index);
				return 1;
			}
		}
		return 0;
	}
	else {
		return 0;
	}
	
}
