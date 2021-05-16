#pragma once
#include <vector>
#include <string>
#include "Card.h"
class CardManager
{
	static CardManager* accountManager;
	std::vector<Card*> accounts;
	CardManager();
public:
	static CardManager* getCardManagerInstance();

	void readCardsFromFile();
	void writeCardsToFile();

	std::string generateCardNumber();
	short int generateRandomPIN();
};

