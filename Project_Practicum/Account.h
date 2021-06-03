#pragma once
#include <string>
#include "Card.h"
#include <vector>
class Account
{
	std::string mOwnerEgn;
	std::string mAccountNumber;
	double mBalance;
	std::vector<Card*> mCards;
public:
	Account(std::string ownerEgn, std::string accountNumber, double balance);
	std::string getAccountNumber() const;
};

