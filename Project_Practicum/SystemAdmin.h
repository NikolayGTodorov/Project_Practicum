#pragma once
#include <string>
#include "EmployeeUser.h"
#include "EmployeeManager.h"

class SystemAdmin
{
	std::string mUsername;
	std::string mPassword;

	static SystemAdmin* admin;
	SystemAdmin();

public:
	static SystemAdmin* getSystemAdminInstance();
	void addEmployeeAccount();
	//void deleteEmployeeAccount();
};

