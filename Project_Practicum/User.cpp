#include "User.h"
#include "EmployeeManager.h"

User::User(std::string egn, std::string firstName, std::string secondName, std::string lastName, BirthDate birthDate, std::string address) :
	mEgn{ egn }, mFirstName{ firstName }, mSecondName{ secondName }, mLastName{ lastName }, mBirthDate{ birthDate },
	mAddress{address}
{
}

User::User()
{
}

std::string User::getUserEgn() const
{
	return mEgn;
}


std::istream& operator>>(std::istream& is, User& user)
{
	EmployeeManager* empManager = EmployeeManager::getEmployeeManagerInstance();
	std::cout << "Enter egn: \n";
	is >> user.mEgn;
	if (empManager->checkEgnAlreadyRegistered(user.mEgn)) {
		std::cout << "Egn already exists\n";
		throw std::exception("Egn already exists\n");
	}
	std::cout << "Input first name: \n";
	is >> user.mFirstName;
	std::cout << "Input middle name: \n";
	is >> user.mSecondName;
	std::cout << "Input last name: \n";
	is >> user.mLastName;
	std::cout << "Input date of birth: \n";
	is >> user.mBirthDate;
	std::cout << "Input an address: \n";
	is >> user.mAddress;

	return is;
}
