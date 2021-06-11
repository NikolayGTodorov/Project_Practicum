#include "Card.h"

Card::Card(std::string accountAssociatedWith, std::string cardNumber, short int pin) :
	mAccountAssociatedWith{accountAssociatedWith}, mCardNumber{cardNumber}, mPin{pin}
{
}

std::string Card::getAccountAssociatedWith() const
{
	return mAccountAssociatedWith;
}

std::string Card::getCardNumber() const
{
	return mCardNumber;
}

short int Card::getPin() const
{
	return mPin;
}

void Card::serialize(std::ostream& os)
{
	int accountAssosciatedWithLength = mAccountAssociatedWith.length();
	int cardNumberLength = mCardNumber.length();

	os.write((const char*)&accountAssosciatedWithLength, sizeof(int));
	os.write(mAccountAssociatedWith.c_str(), accountAssosciatedWithLength);

	os.write((const char*)&cardNumberLength, sizeof(int));
	os.write(mCardNumber.c_str(), cardNumberLength);

	os.write((const char*)&mPin, sizeof(short int));
}

void Card::deserialize(std::istream& is)
{
	int accountAssosciatedWithLength;
	int cardNumberLength;

	is.read((char*)&accountAssosciatedWithLength, sizeof(int));
	char* tempAccountNumber = new char[accountAssosciatedWithLength + 1];
	is.read(tempAccountNumber, accountAssosciatedWithLength);
	tempAccountNumber[accountAssosciatedWithLength] = '\0';
	mAccountAssociatedWith = tempAccountNumber;

	is.read((char*)&cardNumberLength, sizeof(int));
	char* tempCardNumber = new char[cardNumberLength + 1];
	is.read(tempCardNumber, cardNumberLength);
	tempCardNumber[cardNumberLength] = '\0';
	mCardNumber = tempCardNumber;

	is.read((char*)&mPin, sizeof(short int));

	delete[] tempAccountNumber;
	delete[] tempCardNumber;
}
