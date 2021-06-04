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
