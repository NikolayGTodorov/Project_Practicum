#include "SystemAdmin.h"


SystemAdmin* SystemAdmin::admin = 0;

SystemAdmin::SystemAdmin() : mUsername{"admin"}, mPassword{"admin"}
{
}

SystemAdmin* SystemAdmin::getSystemAdminInstance()
{
	if (!admin) {
		admin = new SystemAdmin();
	}
	return admin;
}

void SystemAdmin::addEmployeeAccount()
{
	EmployeeUser* emp = new EmployeeUser();
	std::cin >> *emp;
	EmployeeManager* empManager = EmployeeManager::getEmployeeManagerInstance();
	empManager->getEmployees().push_back(new EmployeeUser(*emp));
	delete emp;
}
