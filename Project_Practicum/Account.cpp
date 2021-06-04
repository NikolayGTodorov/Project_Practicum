#include "Account.h"

Account::Account(std::string ownerEgn, std::string accountNumber, double balance) :
	mOwnerEgn{ ownerEgn }, mAccountNumber{ accountNumber }, mBalance{ balance }
{
	//fill cards...
}

std::string Account::getOwnerEgn() const
{
	return mOwnerEgn;
}

std::string Account::getAccountNumber() const
{
	return mAccountNumber;
}

int Account::getCardsCount() const
{
	return mCards.size();
}
