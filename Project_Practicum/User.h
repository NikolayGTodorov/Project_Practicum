#pragma once
#include "ISerializable.h"
#include "BirthDate.h"
#include <iostream>
class User
{
	friend std::istream& operator >>(std::istream& is, User& user);
	friend std::ostream& operator<<(std::ostream& os, User& user);
protected:
	std::string mEgn;
	std::string mFirstName;
	std::string mSecondName;
	std::string mLastName;
	BirthDate mBirthDate;
	std::string mAddress;
	User(std::string egn, std::string firstName, std::string secondName,
		std::string lastName, BirthDate birthDate,
		std::string address);
	User();
public:
	std::string getUserEgn() const;
};

std::istream& operator >>(std::istream& is, User& user);
std::ostream& operator<<(std::ostream& os, User& user);
