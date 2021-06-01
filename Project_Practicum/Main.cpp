#include <iostream>
#include "SystemAdmin.h"
/*
void fixStream() {
	if (std::cin.bad() || std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else {
	}
}
void showCommands() {
	std::cout << "The available commands are:\n- loginAsAdmin\n" <<
		"- loginAsEmployee\n- loginAsClient";
}

void run() {
	showCommands();
	char* command = new char[9];
	do {	
		std::cin.getline(command, 9);
		if (strcmp(command, "loginAsAdmin") == 0) {
			
			User user;
			if (user.create() == 1) {
				user.saveInFile();
			}
			else {
				std::cout << "Username already exists!\n";
			}
		}
		else if (strcmp(command, "login") == 0) {
			User user;
			if (user.login() == 1) {
				user.getHashedPassword();
				user.setUserEmail();
				std::cout << "Succesful login.\n";
				showLoginCommands();
				loggedMenu(user);
			}
			else {
				std::cout << "Invalid credentials.\n";
			}
		}
		else {
			fixStream();
		}
	} while (strcmp(command, "exit") != 0);

	delete[] command;
}
*/
int main() {

	SystemAdmin* s = SystemAdmin::getSystemAdminInstance();
	s->addEmployeeAccount();

}