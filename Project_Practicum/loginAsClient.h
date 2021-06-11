#include "Utility.h"
#include <iostream>
#include "CardManager.h"
#include "ClientManager.h"

void loginAsClient(std::string& command) {
	std::string cardNumber;
	short int pin;
	std::cout << "Enter card number: ";
	std::cin >> cardNumber;
	std::cout << "Enter pin for the card: ";
	std::cin >> pin;
	CardManager* cardManager = CardManager::getCardManagerInstance();
	if (cardManager->cardWithNumberExists(cardNumber)) {
		Card* currentCard = cardManager->getCardByNumber(cardNumber);
		if (currentCard->getPin() == pin) {
			ClientManager* clientManager = ClientManager::getClientManagerInstance();
			ClientUser* currentlyLogged = clientManager->getClientByAccountNumber(currentCard->getAccountAssociatedWith());
			std::cout << "Login successfull.\n";
			do {
				std::cout << '>';
				std::cin >> command;
				if (toLower(command) == "help") {
					std::cout << "The available commands are:\n- deposit (You should enter positive amount to be deposited)\n" <<
						"- withdraw (You should enter positive amount to be withdrawed)\n"
						<< "- checkBalance (The balance is automatically showed based on to which account the card is assigned)\n";
				}
				else if (toLower(command) == "deposit") {
					currentlyLogged->deposit(currentCard->getAccountAssociatedWith());
				}
				else if (toLower(command) == "withdraw") {
					currentlyLogged->withdraw(currentCard->getAccountAssociatedWith());
				}
				else if (toLower(command) == "checkbalance") {
					std::cout << "Current balance: " << currentlyLogged->checkBalance(currentCard->getAccountAssociatedWith());
				}
				else if (toLower(command) == "exit") {
					std::cout << "Exitting the program.\n";
				}
				else {
					std::cout << "Invalid command...\n";
				}
			} while (toLower(command) != "exit");
		}
		else {
			std::cout << "Entered pin is incorrect...\n";
		}
	}
	else {
		std::cout << "Such card does not exist...\n";
	}
}