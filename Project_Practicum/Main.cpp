#include <iostream>
#include "SystemAdmin.h"
#include <string>
#include "CardManager.h"
#include "ClientManager.h"
#include "AccountManager.h"
#include "Utility.h"
#include "loginAsAdmin.h"
#include "loginAsEmployee.h"
#include "loginAsClient.h"

void deserializeManagers() {
	std::ifstream accountsFile("accounts.bin", std::ios::binary);
	std::ifstream cardsFile("cards.bin", std::ios::binary);
	std::ifstream employeesFile("employees.bin", std::ios::binary);
	std::ifstream clientsFile("clients.bin", std::ios::binary);

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
	std::ofstream clientsFile("clients.bin", std::ios::binary | std::ios::trunc);

	AccountManager* accountManager = AccountManager::getAccountManagerInstance();
	accountManager->serialize(accountsFile);
	accountManager->releaseAccountManagerInstance();

	CardManager* cardManager = CardManager::getCardManagerInstance();
	cardManager->serialize(cardsFile);
	cardManager->releaseCardManagerInstance();

	EmployeeManager* employeeManager = EmployeeManager::getEmployeeManagerInstance();
	employeeManager->serialize(employeesFile);
	employeeManager->releaseEmployeeManagerInstance();

	ClientManager* clientManager = ClientManager::getClientManagerInstance();
	clientManager->serialize(clientsFile);
	clientManager->releaseClientManagerInstance();
}

void run() {
	std::string command;
	do {
		std::cout << '>';
		std::cin >> command;
		if (toLower(command) == "loginasadmin") {
			loginAsAdmin(command);
		}
		else if (toLower(command) == "loginasemployee") {
			loginAsEmployee(command);
		}
		else if (toLower(command) == "loginasclient") {
			loginAsClient(command);
		}
		else if (toLower(command) == "help") {
			std::cout << "The available commands are:\n- loginAsAdmin (The user enters username and password and if they exist he enters as Admin)\n" <<
				"- loginAsEmployee (The user enters username and password and if they exist they enter the system as Employee)\n" 
				<< "- loginAsClient (The user enters card number and pin of this card (he must own it) and if they exist and are his property he is logged as Client)\n";
		}
		else if (toLower(command) == "exit") {
			std::cout << "Exitting the program.\n";
		}
		else {
			std::cout << "Invalid command...\n";
		}
	} while (toLower(command) != "exit");

}

int main() {
	deserializeManagers();
	run();
	serializeManagers();
}