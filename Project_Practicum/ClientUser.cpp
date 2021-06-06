#include "ClientUser.h"
#include "AccountManager.h"

ClientUser::ClientUser(std::string egn, std::string firstName, std::string secondName, std::string lastName, BirthDate birthDate, std::string address) :
	User(egn, firstName, secondName, lastName, birthDate, address)
{
}

ClientUser::ClientUser() : User()
{
}

void ClientUser::serialize(std::ostream& os)
{
	//for (Account* acc : mUserAccounts) {
	//	// os << accountsCount??
	//	os << acc;
	//}
	//os << mEgn << mFirstName << mSecondName << mLastName
	//	<< mBirthDate << mAddress << '\n';
}

void ClientUser::deserialize(std::istream& is)
{
	/*int counter;
	is >> counter;
	for (size_t i = 0; i < counter; i++) {
		is >> mUserAccounts[i];
	}
	is >> mEgn >> mFirstName >> mSecondName >> mLastName
		>> mBirthDate.deserialize(is) >> mAddress >> '\n';*/
}

int ClientUser::getAccountsCount() const
{
	return getAccounts().size();
}

std::vector<Account*> ClientUser::getAccounts() const
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

std::istream& operator>>(std::istream& is, ClientUser& client)
{
	is >> static_cast<User&>(client);
	return is;
}
