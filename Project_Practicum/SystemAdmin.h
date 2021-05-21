#pragma once
#include <string>
class SystemAdmin
{
	std::string mUsername;
	std::string mPassword;

	static SystemAdmin* admin;
	SystemAdmin();

public:
	static SystemAdmin* getSystemAdminInstace();
	void addEmployeeAccount();
	void deleteEmployeeAccount();
};

