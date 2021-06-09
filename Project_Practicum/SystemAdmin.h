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
	static void releaseSystemAdminInstance();



	void addEmployeeAccount();
	void deleteEmployeeAccount();
};

bool stringContainsDigitsOnly(const std::string& str);