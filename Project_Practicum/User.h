#pragma once
#include "ISerializable.h"
#include "BirthDate.h"
#include <iostream>
class User
{
	friend std::istream& operator >>(std::istream& is, User& user);
protected:
	std::string mEgn;   // maybe change this to my class EGN which has char[10] and manages its memory
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

