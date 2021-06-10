#include "SystemAdmin.h"
#include "ClientManager.h"

SystemAdmin* SystemAdmin::admin = 0;

SystemAdmin::SystemAdmin() : mUsername{ "admin" }, mPassword{ "admin" }
{
}

SystemAdmin* SystemAdmin::getSystemAdminInstance()
{
	if (!admin) {
		admin = new SystemAdmin();
	}
	return admin;
}

void SystemAdmin::releaseSystemAdminInstance()
{
	delete admin;
}

bool stringContainsDigitsOnly(const std::string& str) {
	for (char c : str) {
		if (!std::isdigit(c)) {
			return 0;
		}
	}
	return 1;
}

void SystemAdmin::addEmployeeAccount()
{
	EmployeeUser* emp = new EmployeeUser();
	EmployeeManager* empManager = EmployeeManager::getEmployeeManagerInstance();
	ClientManager* clientManager = ClientManager::getClientManagerInstance();
	std::cin >> *emp;
	if (emp->getUserEgn().length() == 10 && stringContainsDigitsOnly(emp->getUserEgn())) {
		if (empManager->checkEgnAlreadyRegistered(emp->getUserEgn()) || clientManager->clientWithEgnExists(emp->getUserEgn())) {
			std::cout << "User with such Egn already exists...\n";
		}
		if (!stringContainsDigitsOnly(emp->getPhoneNumber()) && !emp->getPhoneNumber().length() <= 15) {
			std::cout << "Invalid phone number (max length: 15 and digits only)\n";
		}
		if (!emp->getBirthDate().validInput(emp->getBirthDate().getDate())) {
			std::cout << "Enter valid birthday info\n";
		}
		else {
			std::cout << "Employee created successfully.\n";
			empManager->addEmployee(emp);
		}
	}
	else {
		std::cout << "Enter valid egn (10 digits)\n";
	}
	delete emp;
}

void SystemAdmin::deleteEmployeeAccount()
{
	std::string egn;
	std::cout << "Enter employee Egn: \n";
	std::cin >> egn;
	EmployeeManager* empManager = EmployeeManager::getEmployeeManagerInstance();
	if (empManager->removeEmployeeByEgn(egn) == 1) {
		std::cout << "Successfully deleted empoyee with EGN: " << egn << '\n';
	}
	else {
		std::cout << "Couldn't find employee with this egn...\n";
	}
}
