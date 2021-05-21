#include "SystemAdmin.h"

SystemAdmin* admin = 0;

SystemAdmin::SystemAdmin() : mUsername{"admin"}, mPassword{"admin"}
{
}

SystemAdmin* SystemAdmin::getSystemAdminInstace()
{
	if (!admin) {
		admin = new SystemAdmin();
		return admin;	
	}
}
