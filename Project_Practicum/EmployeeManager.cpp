#include "EmployeeManager.h"
#include "EmployeeUser.h"

EmployeeManager* EmployeeManager::employeeManager = 0;

EmployeeManager::EmployeeManager()
{
	//read all employees from File
	//set initialEmployeesCount to number of account read from file
}

EmployeeManager* EmployeeManager::getEmployeeManagerInstance()
{
	if (!employeeManager) {
		employeeManager = new EmployeeManager();
	}
	return employeeManager;
}

std::vector<EmployeeUser*>& EmployeeManager::getEmployees()
{
	return mEmployees;
}

bool EmployeeManager::checkEgnAlreadyRegistered(std::string egnToCheck) const
{
	for (EmployeeUser* emp : mEmployees) {
		if (emp->getUserEgn() == egnToCheck) {
			return 1;
		}
	}
	return 0;
}
