#pragma once
#include <vector>
#include <string>
#include "Card.h"
class CardManager : public ISerializable
{
	std::vector<Card*> mCards;
	static CardManager* cardManager;
	CardManager();
	~CardManager();
public:
	static CardManager* getCardManagerInstance();
	static void releaseCardManagerInstance();

	bool cardWithNumberExists(std::string cardNumber);
	Card* getCardByNumber(std::string cardNumber);
	int getCardsCountByAccountNumber(std::string accountNumber) const;
	const std::vector<Card*> getAllCardsByAccountNumber(std::string accountNumber) const;

	std::string generateCardNumber(std::string egn);
	short int generateRandomPIN();

	void addCard(std::string egn, std::string accountNumber);
	bool removeCard(std::string egn, std::string accountNumber, std::string cardNumber);
	void removeAllCardsFromAccount(std::string account);

	// Inherited via ISerializable
	virtual void serialize(std::ostream& os) override;
	virtual void deserialize(std::istream& is) override;
};

