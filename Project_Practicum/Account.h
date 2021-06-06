#pragma once
#include <string>
#include "Card.h"
#include <vector>
class Account
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
};

