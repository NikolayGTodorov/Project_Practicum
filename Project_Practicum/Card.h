#pragma once
#include <string>
#include "ISerializable.h"

class Card : public ISerializable
{
	std::string mAccountAssociatedWith;
	std::string mCardNumber;
	short int mPin;
public:
	Card(std::string accountAssociatedWith, std::string cardNumber, short int pin);
	std::string getAccountAssociatedWith() const;
	std::string getCardNumber() const;
	short int getPin() const;

	// Inherited via ISerializable
	virtual void serialize(std::ostream& os) override;
	virtual void deserialize(std::istream& is) override;
};

