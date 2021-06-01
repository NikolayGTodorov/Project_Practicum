#pragma once
#include <vector>
#include <string>
class EmployeeUser;

class EmployeeManager
{
	std::vector<EmployeeUser*> mEmployees;
	//size_t initialEmployeesCount;

	static EmployeeManager* employeeManager;
	EmployeeManager();
public:
	static EmployeeManager* getEmployeeManagerInstance();
	std::vector<EmployeeUser*>& getEmployees();
	bool checkEgnAlreadyRegistered(std::string egnToCheck) const;
};

