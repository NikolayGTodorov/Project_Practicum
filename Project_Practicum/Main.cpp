#include <iostream>
#include "SystemAdmin.h"
#include <string>
#include "CardManager.h"
#include "ClientManager.h"
#include "AccountManager.h"

void initializeFiles() {
	std::ifstream accountsFile("accounts.bin", std::ios::binary);
	std::ifstream cardsFile("cards.bin", std::ios::binary);
	std::ifstream employeesFile("employees.bin", std::ios::binary);
	std::ifstream clientsFile("accounts.bin", std::ios::binary);

	AccountManager* accountManager = AccountManager::getAccountManagerInstance();
	accountManager->deserialize(accountsFile);

	CardManager* cardManager = CardManager::getCardManagerInstance();
	cardManager->deserialize(cardsFile);

	EmployeeManager* employeeManager = EmployeeManager::getEmployeeManagerInstance();
	employeeManager->deserialize(employeesFile);

	ClientManager* clientManager = ClientManager::getClientManagerInstance();
	clientManager->deserialize(clientsFile);
}

void serializeManagers() {
	std::ofstream accountsFile("accounts.bin", std::ios::binary | std::ios::trunc);
	std::ofstream cardsFile("cards.bin", std::ios::binary | std::ios::trunc);
	std::ofstream employeesFile("employees.bin", std::ios::binary | std::ios::trunc);
	std::ofstream clientsFile("accounts.bin", std::ios::binary | std::ios::trunc);

	AccountManager* accountManager = AccountManager::getAccountManagerInstance();
	accountManager->serialize(accountsFile);

	CardManager* cardManager = CardManager::getCardManagerInstance();
	cardManager->serialize(cardsFile);

	EmployeeManager* employeeManager = EmployeeManager::getEmployeeManagerInstance();
	employeeManager->serialize(employeesFile);

	ClientManager* clientManager = ClientManager::getClientManagerInstance();
	clientManager->serialize(clientsFile);
}


void run() {
	std::string command;
	do {
		std::cin >> command;
		if (command == "loginAsAdmin") {
			std::string username;
			std::string password;
			std::cout << "Enter username: ";
			std::cin >> username;
			std::cout << "Enter password: ";
			std::cin >> password;
			if (username == "admin" && password == "admin") {
				std::cout << "Login successfull.\n";
				SystemAdmin* admin = SystemAdmin::getSystemAdminInstance();
				do {
					std::cin >> command;
					if (command == "help") {
						std::cout << "The available commands are:\n- addEmployee\n" <<
							"- removeEmployee\n";
					}
					else if (command == "addEmployee") {
						admin->addEmployeeAccount();
					}
					else if (command == "removeEmployee") {
						admin->deleteEmployeeAccount();
					}
					else {
						std::cout << "Invalid command...\n";
					}
				} while (command != "exit");
			}
			else {
				std::cout << "Invalid username or password...\n";
			}
		}
		else if (command == "loginAsEmployee") {
			std::string username;
			std::string password;
			std::cout << "Enter username: ";
			std::cin >> username;
			std::cout << "Enter password: ";
			std::cin >> password;
			EmployeeManager* employeeManager = EmployeeManager::getEmployeeManagerInstance();
			if (employeeManager->employeeWithUserNameExist(username)) {
				if (employeeManager->employeeWithPasswordExist(password)) {
					do {
						std::cin >> command;
						EmployeeUser* currentlyLogged = employeeManager->getUserByCredentials(username, password);
						if (command == "help") {
							std::cout << "The available commands are:\n- addClient\n" <<
								"- removeClient\n- addAccountToClient\n- addCardToClientAccount\n"
								<< "-removeClientAccount\n- removeCardFromAccount\n- printAllClients\n"
								<< "- printIndividualSummary\n";
						}
						else if (command == "addClient") {
							currentlyLogged->addClient();
						}
						else if (command == "removeClient") {
							currentlyLogged->deleteClient();
						}
						else if (command == "addAccountToClient") {
							currentlyLogged->openAccount();
						}
						else if (command == "removeClientAccount") {
							currentlyLogged->closeAccount();
						}
						else if (command == "addCardToClientAccount") {
							currentlyLogged->addCardToAccount();
						}
						else if (command == "removeCardFromAccount") {
							currentlyLogged->deleteCardFromAccount();
						}
						else if (command == "printAllClients") {
							currentlyLogged->printClientsReport();
						}
						else if (command == "printIndividualSummary") {
							currentlyLogged->printIndividualReport();
						}
						else {
							std::cout << "Invalid command...\n";
						}
					} while (command != "exit");
				}
				else {
					std::cout << "Incorrect password...\n";
				}
			}
			else {
				std::cout << "User does not exist...\n";
			}
		}
		else if (command == "loginAsClient") {
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
					ClientUser* currentlyLogged = clientManager->getClientUserByAccountNumber(currentCard->getAccountAssociatedWith());
					do {
						std::cin >> command;
						if (command == "help") {
							std::cout << "The available commands are:\n- deposit\n" <<
								"- withdraw\n- checkBalance\n";
						}
						else if (command == "deposit") {
							currentlyLogged->deposit(currentCard->getAccountAssociatedWith());
						}
						else if (command == "withdraw") {
							currentlyLogged->withdraw(currentCard->getAccountAssociatedWith());
						}
						else if (command == "checkBalance") {
							currentlyLogged->checkBalance(currentCard->getAccountAssociatedWith());
						}
						else {
							std::cout << "Invalid command...\n";
						}
					} while (command != "exit");
				}
				else {
					std::cout << "Entered pin is incorrect...\n";
				}
			}
			else {
				std::cout << "Such card does not exist...\n";
			}
		}
		else if (command == "help") {
			std::cout << "The available commands are:\n- loginAsAdmin\n" <<
				"- loginAsEmployee\n- loginAsClient\n";
		}
		else {
			std::cout << "Invalid command...\n";
		}

	} while (command != "exit");

}

int main() {
	initializeFiles();
	run();
	serializeManagers();
}