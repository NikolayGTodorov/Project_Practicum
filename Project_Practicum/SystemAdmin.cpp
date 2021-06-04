#include "SystemAdmin.h"


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

void SystemAdmin::addEmployeeAccount()
{
	EmployeeUser* emp = new EmployeeUser();
	std::cin >> *emp;
	EmployeeManager* empManager = EmployeeManager::getEmployeeManagerInstance();
	if (!empManager->checkEgnAlreadyRegistered(emp->getUserEgn())) {
		empManager->addEmployee(emp);
	}
	else {
		std::cout << "Employee with such Egn already exists...\n";
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
