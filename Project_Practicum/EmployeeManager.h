#pragma once
#include <vector>
#include <string>
#include "ISerializable.h"
class EmployeeUser;

class EmployeeManager : public ISerializable
{
	std::vector<EmployeeUser*> mEmployees;

	static EmployeeManager* employeeManager;
	EmployeeManager();
	~EmployeeManager();
public:
	static EmployeeManager* getEmployeeManagerInstance();
	static void releaseEmployeeManagerInstance();

	bool checkEgnAlreadyRegistered(std::string egnToCheck) const;
	bool employeeWithUserNameExist(std::string username);
	bool employeeWithPasswordExist(std::string password);

	EmployeeUser* getUserByCredentials(std::string username, std::string password);

	void addEmployee(EmployeeUser* user);
	bool removeEmployeeByEgn(std::string egn);

	// Inherited via ISerializable
	virtual void serialize(std::ostream& os) override;
	virtual void deserialize(std::istream& is) override;
};

