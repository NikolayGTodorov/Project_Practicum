#include "CardManager.h"
#include <time.h>
#include "ClientManager.h"
#include "AccountManager.h"

CardManager* CardManager::cardManager = 0;

CardManager::CardManager() : 
	mCards{ std::vector<Card*>()}
{
}

CardManager::~CardManager()
{
	for (Card* card : mCards) {
		delete card;
	}
	mCards.clear();
}

CardManager* CardManager::getCardManagerInstance()
{
	if (!cardManager) {
		cardManager = new CardManager();
	}
	return cardManager;
}

void CardManager::releaseCardManagerInstance()
{
	delete cardManager;
}

bool CardManager::cardWithNumberExists(std::string cardNumber)
{
	for (Card* card : mCards) {
		if (card->getCardNumber() == cardNumber) {
			return 1;
		}
	}
	return 0;
}

std::string CardManager::generateCardNumber(std::string egn)
{
	std::string cardNumber;
	ClientManager* clientManager = ClientManager::getClientManagerInstance();
	
	cardNumber = "00" + egn.substr(6, 10) + std::to_string(clientManager->getClientByEgn(egn)->getCardsCount());
	return cardNumber;
}
short int CardManager::generateRandomPIN()
{
	srand(time(0));
	return (rand() % 9000 + 1000);
}

void CardManager::addCard(std::string egn, std::string accountNumber)
{
	short int pin = generateRandomPIN();
	std::string cardNumber = generateCardNumber(egn);
	mCards.push_back(new Card(accountNumber, cardNumber, pin));
	std::cout << "Card number: " << cardNumber << " with PIN: " << pin << '\n';
}

bool CardManager::removeCard(std::string egn, std::string accountNumber, std::string cardNumber)
{
	AccountManager* accountManager = AccountManager::getAccountManagerInstance();
	if (accountManager->accountWithNumberExists(accountNumber) && cardWithNumberExists(cardNumber)) {
		int index = 0;
		for (Card* card : mCards) {
			index++;
			if (card->getCardNumber() == cardNumber && card->getAccountAssociatedWith() == accountNumber) {
				delete mCards[index];
				mCards.erase(mCards.begin() + index);
				return 1;
			}
		}
		return 0;
	}
	else {
		return 0;
	}
}

int CardManager::getCardsCountByAccountNumber(std::string accountNumber) const
{
	int counter = 0;
	for (Card* card : mCards) {
		if (card->getAccountAssociatedWith() == accountNumber) {
			counter++;
		}
	}
	return counter;
}

void CardManager::removeAllCardsFromAccount(std::string account)
{
	int index = 0;
	for (Card* card : mCards) {
		index++;
		if (card->getAccountAssociatedWith() == account) {
			delete mCards[index];
			mCards.erase(mCards.begin() + index);
		}
	}
}
