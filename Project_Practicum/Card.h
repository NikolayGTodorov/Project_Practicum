#pragma once
#include <string>
class Card
{
	std::string mAccountAssociatedWith;
	std::string mCardNumber;
	short int mPin;
public:
	Card(std::string accountAssociatedWith, std::string cardNumber, short int pin);
	std::string getAccountAssociatedWith() const;
	std::string getCardNumber() const;
	std::string getPin() const;
};

