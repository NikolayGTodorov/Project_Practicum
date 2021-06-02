#include "EmployeeUser.h"

EmployeeUser::EmployeeUser(std::string username, std::string password, std::string egn, std::string firstName, std::string secondName, std::string lastName, BirthDate birthDate, std::string address, PhoneNumber phone) :
	User(egn,firstName, secondName, lastName, birthDate, address),
	mUsername{username}, mPassword{password}, mPhoneNumber{phone}
{
}

EmployeeUser::EmployeeUser()
{
}

void EmployeeUser::serialize(std::ostream& os)
{
	os << mUsername << mPassword << mEgn << mFirstName
		<< mSecondName << mLastName << mBirthDate << mPhoneNumber << '\n';
}

void EmployeeUser::deserialize(std::istream& is)
{
	////maybe add legth of strings?
	//is >> mUsername >> mPassword >> mEgn >> mFirstName
	//	>> mSecondName >> mLastName >> mBirthDate >> mPhoneNumber >> '\n';
}

std::istream& operator>>(std::istream& is, EmployeeUser& empUser)
{
	std::cout << "Enter username: \n";
	is >> empUser.mUsername;
	std::cout << "Enter password: \n";
	is >> empUser.mPassword;
	is >> static_cast<User&>(empUser);
	std::cout << "Enter phone number: \n";
 	is >> empUser.mPhoneNumber;

	return is;
}
