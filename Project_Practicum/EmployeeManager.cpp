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

bool EmployeeManager::employeeWithUserNameExist(std::string username)
{
	for (EmployeeUser* employee : mEmployees) {
		if (employee->getUsername() == username) {
			return 1;
		}
	}
	return 0;
}

bool EmployeeManager::employeeWithPasswordExist(std::string password)
{
	for (EmployeeUser* employee : mEmployees) {
		if (employee->getPassword() == password) {
			return 1;
		}
	}
	return 0;
}

EmployeeUser* EmployeeManager::getUserByCredentials(std::string username, std::string password)
{
	for (EmployeeUser* empUser : mEmployees) {
		if (empUser->getUsername() == username && empUser->getPassword() == password) {
			return empUser;
		}
	}
}

void EmployeeManager::addEmployee(EmployeeUser* user)
{
	mEmployees.push_back(new EmployeeUser(*user));
}

bool EmployeeManager::removeEmployeeByEgn(std::string egn)
{
	int index = 0;
	for (EmployeeUser* empUser : mEmployees) {
		if (empUser->getUserEgn() == egn) {
			delete mEmployees[index];
			mEmployees.erase(mEmployees.begin() + index);
			return 1;
		}
		index++;
	}
	return 0;
}

void EmployeeManager::serialize(std::ostream& os)
{
	int vectorSize = mEmployees.size();
	os.write((const char*)&vectorSize, sizeof(int));
	for (int i = 0; i < vectorSize; i++) {
		mEmployees[i]->serialize(os);
	}
}

void EmployeeManager::deserialize(std::istream& is)
{
	int size;
	mEmployees.clear();
	is.read((char*)&size, sizeof(int));
	if (size > 0) {
		mEmployees.resize(size + 1);
		for (int i = 0; i < size; i++) {
			mEmployees[i] = new EmployeeUser();
			mEmployees[i]->deserialize(is);
		}
	}
}
