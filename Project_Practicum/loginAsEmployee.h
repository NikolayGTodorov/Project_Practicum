#include "Utility.h"
#include <iostream>
#include "EmployeeManager.h"
#include "EmployeeUser.h"

void loginAsEmployee(std::string& command) {
	std::string username;
	std::string password;
	std::cout << "Enter username: ";
	std::cin >> username;
	std::cout << "Enter password: ";
	std::cin >> password;
	EmployeeManager* employeeManager = EmployeeManager::getEmployeeManagerInstance();
	if (employeeManager->employeeWithUserNameExist(username)) {
		if (employeeManager->employeeWithPasswordExist(password)) {
			std::cout << "Login successfull.\n";
			do {
				std::cout << '>';
				std::cin >> command;
				EmployeeUser* currentlyLogged = employeeManager->getUserByCredentials(username, password);
				if (toLower(command) == "help") {
					std::cout << "The available commands are:\n- addClient (You are prompted to enter valid info for the new Client)\n" <<
						"- removeClient (You are prompted to enter EGN of the client you want to remove, if it exists he is deleted)\n"
						<< "- addAccountToClient (You are prompted to enter valid EGN of the client and positive intial amount of the deposit)\n"
						<< "- addCardToClientAccount (You are prompted to enter valid EGN and client's account number where the card should be stored)\n"
						<< "- removeClientAccount (You are prompted to enter valid EGN and client's account number to be removed)\n"
						<< "- removeCardFromAccount (You are prompted to enter valid EGN, client's account number and card number that is assigned to this account)\n"
						<< "- printAllClients (The system automatically prints statistics for currenly registered clients)\n"
						<< "- printIndividualSummary (You are prompted to enter EGN of the client whose summary to be shown)\n";
				}
				else if (toLower(command) == "addclient") {
					currentlyLogged->addClient();
				}
				else if (toLower(command) == "removeclient") {
					currentlyLogged->deleteClient();
				}
				else if (toLower(command) == "addaccounttoclient") {
					currentlyLogged->openAccount();
				}
				else if (toLower(command) == "removeclientaccount") {
					currentlyLogged->closeAccount();
				}
				else if (toLower(command) == "addcardtoclientaccount") {
					currentlyLogged->addCardToAccount();
				}
				else if (toLower(command) == "removecardfromaccount") {
					currentlyLogged->deleteCardFromAccount();
				}
				else if (toLower(command) == "printallclients") {
					currentlyLogged->printClientsReport();
				}
				else if (toLower(command) == "printindividualsummary") {
					currentlyLogged->printIndividualReport();
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
			std::cout << "Incorrect password...\n";
		}
	}
	else {
		std::cout << "User does not exist...\n";
	}
}