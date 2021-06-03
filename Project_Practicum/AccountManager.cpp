#include "AccountManager.h"
#include "ClientManager.h"

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



std::string AccountManager::generateAccountNumber(std::string egn)
{
	ClientManager* clientManager = ClientManager::getClientManagerInstance();
	std::string temp = "00MYBANK" + egn.substr(6, 10) + std::to_string(clientManager->getClientByEgn(egn)->getAccountsCount());
}
