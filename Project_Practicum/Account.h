#pragma once
#include <string>
#include "Card.h"
#include "ISerializable.h"
#include <vector>
class Account : public ISerializable
{
	std::string mOwnerEgn;
	std::string mAccountNumber;
	double mBalance;
public:
	Account(std::string ownerEgn, std::string accountNumber, double balance);
	std::string getOwnerEgn() const;
	std::string getAccountNumber() const;
	int getCardsCount() const;
	double getBalance() const;
	void addBalance(double toAdd);

	virtual void serialize(std::ostream& os) override;
	virtual void deserialize(std::istream& is) override;
};

