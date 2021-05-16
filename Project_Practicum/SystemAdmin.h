#pragma once
#include <string>
class SystemAdmin
{
	std::string mUsername;
	std::string mPassword;
public:
	// add constructor or make the class use singleton, only 1 admin??
	void addEmployeeAccount();
	void deleteEmployeeAccount();
};

