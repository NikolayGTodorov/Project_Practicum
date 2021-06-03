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
};

