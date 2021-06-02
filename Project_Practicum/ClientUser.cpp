#include "ClientUser.h"

ClientUser::ClientUser(std::vector<Account*> userAccounts, std::string egn, std::string firstName, std::string secondName, std::string lastName, BirthDate birthDate, std::string address) :
	User(egn, firstName, secondName, lastName, birthDate, address), mUserAccounts{ userAccounts }
{
}

ClientUser::ClientUser() : User(), mUserAccounts{ std::vector<Account*>() }
{
}

void ClientUser::serialize(std::ostream& os)
{
	for (Account* acc : mUserAccounts) {
		// os << accountsCount??
		os << acc;
	}
	os << mEgn << mFirstName << mSecondName << mLastName
		<< mBirthDate << mAddress << '\n';
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

std::istream& operator>>(std::istream& is, ClientUser& client)
{
	is >> static_cast<User&>(client);
}
