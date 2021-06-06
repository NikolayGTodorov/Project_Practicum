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
	~EmployeeManager();
public:
	static EmployeeManager* getEmployeeManagerInstance();
	static void releaseEmployeeManagerInstance();
	//std::vector<EmployeeUser*>& getEmployees();
	bool checkEgnAlreadyRegistered(std::string egnToCheck) const;

	void addEmployee(EmployeeUser* user);
	bool removeEmployeeByEgn(std::string egn);
};

