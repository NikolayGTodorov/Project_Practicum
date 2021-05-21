#include "EmployeeUser.h"

EmployeeUser::EmployeeUser(std::string username, std::string password, std::string egn, std::string firstName, std::string secondName, std::string lastName, BirthDate birthDate, std::string address, PhoneNumber phone) :
	User(egn,firstName, secondName, lastName, birthDate, address),
	mUsername{username}, mPassword{password}, mPhoneNumber{phone}
{
}

void EmployeeUser::serialize(std::ostream& os)
{
	os << mUsername << mPassword << mEgn << mFirstName
		<< mSecondName << mLastName << mBirthDate.serialize(os) << mPhoneNumber.serialize(os) << '\n';
}

void EmployeeUser::deserialize(std::istream& is)
{
	//maybe add legth of strings?
	is >> mUsername >> mPassword >> mEgn >> mFirstName
		>> mSecondName >> mLastName >> mBirthDate.deserialize(is) >> mPhoneNumber.deserialize(is) >> '\n';
}
