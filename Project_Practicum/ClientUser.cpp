#include "ClientUser.h"
#include "AccountManager.h"
#include "CardManager.h"

ClientUser::ClientUser(std::string egn, std::string firstName, std::string secondName, std::string lastName, BirthDate birthDate, std::string address) :
	User(egn, firstName, secondName, lastName, birthDate, address)
{
}

ClientUser::ClientUser() : User()
{
}

void ClientUser::serialize(std::ostream& os)
{
	static_cast<User&>(*this).serialize(os);
}

void ClientUser::deserialize(std::istream& is)
{
	static_cast<User&>(*this).deserialize(is);
}

int ClientUser::getAccountsCount() const
{
	return getAccounts().size();
}

const std::vector<Account*> ClientUser::getAccounts() const
{
	AccountManager* accountManager = AccountManager::getAccountManagerInstance();
	return accountManager->getAllAccountsByEgn(mEgn);
}

int ClientUser::getCardsCount() const
{
	int count = 0;
	for (Account* acc : getAccounts()) {
		count += acc->getCardsCount();
	}
	return count;
}

void ClientUser::deposit(std::string accountNumber)
{
	double toAdd;
	std::cin >> toAdd;
	if (toAdd > 0) {
		AccountManager* accountManager = AccountManager::getAccountManagerInstance();
		accountManager->addCashToAccount(accountNumber, toAdd);
		std::cout << "Successfully added " << toAdd << " to your account!\n";
	}
	else {
		std::cout << "You can only deposit positive amount...\n";
	}

}

void ClientUser::withdraw(std::string accountNumber)
{
	double toWithdraw;
	std::cin >> toWithdraw;
	if (toWithdraw > 0 && checkBalance(accountNumber) - toWithdraw > 0) {
		AccountManager* accountManager = AccountManager::getAccountManagerInstance();
		accountManager->substractCashToAccount(accountNumber, toWithdraw);
		std::cout << "Successfully withdrawed " << toWithdraw << " from your account!\n";
	}
	else {
		std::cout << "Insufficient balance or non-positive input...\n";
	}
}

double ClientUser::checkBalance(std::string accountNumber)
{
	AccountManager* accountManager = AccountManager::getAccountManagerInstance();
	return accountManager->getAccountBalanceByNumber(accountNumber);
}

std::istream& operator>>(std::istream& is, ClientUser& client)
{
	is >> static_cast<User&>(client);
	return is;
}

std::ostream& operator<<(std::ostream& os, ClientUser& client)
{
	os << static_cast<User&>(client);
	os << "Number of accounts: " << client.getAccountsCount() << '\n';
	AccountManager* accountManager = AccountManager::getAccountManagerInstance();
	CardManager* cardManager = CardManager::getCardManagerInstance();
	int index = 0;
	int innerIndex = 0;
	for (Account* account : accountManager->getAllAccountsByEgn(client.getUserEgn())) {
		index++;
		os << "Account" << index << '\n';
		os << "Account Number: " << account->getAccountNumber() << '\n'
			<< "Balance: " << account->getBalance() << '\n'
			<< "Number of cards: " << account->getCardsCount() << '\n';
		for (Card* card : cardManager->getAllCardsByAccountNumber(account->getAccountNumber())) {
			innerIndex++;
			os << "Card" << innerIndex << '\n';
			os << "Card number: " << card->getCardNumber() << "\nPIN: " << card->getPin() << '\n';
		}
	}
	return os;
}
