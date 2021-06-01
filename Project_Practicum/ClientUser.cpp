#include "ClientUser.h"

ClientUser::ClientUser(std::vector<Account*> userAccounts, std::string egn, std::string firstName, std::string secondName, std::string lastName, BirthDate birthDate, std::string address) :
	User(egn, firstName, secondName, lastName, birthDate, address), mUserAccounts{ userAccounts }
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
