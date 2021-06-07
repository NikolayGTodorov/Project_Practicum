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

void Account::serialize(std::ostream& os)
{
	int ownerEgnStringLength = mOwnerEgn.length();
	int accountNumberStringLength = mAccountNumber.length();

	os.write((const char*)&ownerEgnStringLength, sizeof(int));
	os.write(mOwnerEgn.c_str(), ownerEgnStringLength);

	os.write((const char*)&accountNumberStringLength, sizeof(int));
	os.write(mAccountNumber.c_str(), accountNumberStringLength);
	os.write((const char*)&mBalance, sizeof(double));
}

void Account::deserialize(std::istream& is)
{
	int ownerEgnStringLength = 0;
	int accountNumberStringLength = 0;

	is.read((char*)&ownerEgnStringLength, sizeof(int));
	char* tempEgn = new char[ownerEgnStringLength + 1];
	is.read(tempEgn, ownerEgnStringLength);
	tempEgn[ownerEgnStringLength] = '\0';
	mOwnerEgn = tempEgn;

	is.read((char*)&accountNumberStringLength, sizeof(int));
	char* tempAccountNumber = new char[accountNumberStringLength + 1];
	is.read(tempAccountNumber, accountNumberStringLength);
	tempAccountNumber[accountNumberStringLength] = '\0';
	mAccountNumber = tempAccountNumber;

	is.read((char*)&mBalance, sizeof(double));

	delete[] tempEgn;
	delete[] tempAccountNumber;

}


