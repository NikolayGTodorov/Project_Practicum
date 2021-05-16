#pragma once
#include <string>
#include "Card.h"
class Account
{
	std::string mAccountNumber;
	double mBalance;
	Card* cards;
};

