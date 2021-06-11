#include "Utility.h"
#include <iostream>
#include "SystemAdmin.h"

void loginAsAdmin(std::string& command) {
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
			std::cout << '>';
			std::cin >> command;
			if (toLower(command) == "help") {
				std::cout << "The available commands are:\n- addEmployee (You are prompted to enter information needed to add an Employee, some field are validated)\n" <<
					"- removeEmployee (You are prompted to enter EGN of the user you want to remove, if it exists, he is deleted)\n";
			}
			else if (toLower(command) == "addemployee") {
				admin->addEmployeeAccount();
			}
			else if (toLower(command) == "removeemployee") {
				admin->deleteEmployeeAccount();
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
		std::cout << "Invalid username or password...\n";
	}
}