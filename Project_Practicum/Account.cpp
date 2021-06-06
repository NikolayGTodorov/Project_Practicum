#include "Account.h"
#include "CardManager.h"

Account::Account(std::string ownerEgn, std::string accountNumber, double balance) :
	mOwnerEgn{ ownerEgn }, mAccountNumber{ accountNumber }, mBalance{ balance }
{
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
	CardManager* cardManager = CardManager::getCardManagerInstance();
	return cardManager->getCardsCountByAccountNumber(mAccountNumber);
}

double Account::getBalance() const
{
	return mBalance;
}

void Account::addBalance(double toAdd)
{
	mBalance += toAdd;
}


