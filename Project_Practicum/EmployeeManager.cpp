#include "EmployeeManager.h"
#include "EmployeeUser.h"

EmployeeManager* EmployeeManager::employeeManager = 0;

EmployeeManager::EmployeeManager() :
	mEmployees{ std::vector<EmployeeUser*>() }
{
	//read all employees from File
	//set initialEmployeesCount to number of account read from file
}

EmployeeManager::~EmployeeManager()
{
	for (EmployeeUser* emp : mEmployees) {
		delete emp;
	}
	mEmployees.clear();
}

EmployeeManager* EmployeeManager::getEmployeeManagerInstance()
{
	if (!employeeManager) {
		employeeManager = new EmployeeManager();
	}
	return employeeManager;
}

void EmployeeManager::releaseEmployeeManagerInstance()
{
	delete employeeManager;
}

//std::vector<EmployeeUser*>& EmployeeManager::getEmployees()
//{
//	return mEmployees;
//}

bool EmployeeManager::checkEgnAlreadyRegistered(std::string egnToCheck) const
{
	for (EmployeeUser* emp : mEmployees) {
		if (emp->getUserEgn() == egnToCheck) {
			return 1;
		}
	}
	return 0;
}

void EmployeeManager::addEmployee(EmployeeUser* user)
{
	mEmployees.push_back(new EmployeeUser(*user));
}

bool EmployeeManager::removeEmployeeByEgn(std::string egn)
{
	int index = 0;
	for (EmployeeUser* empUser : mEmployees) {
		index++;
		if (empUser->getUserEgn() == egn) {
			delete mEmployees[index];
			mEmployees.erase(mEmployees.begin() + index);
			return 1;
		}
	}
	return 0;
}
