#pragma once
#include "ISerializable.h"
#include "BirthDate.h"
class User :
	public ISerializable
{
	std::string mEgn;   // maybe change this to my class EGN which has char[10] and manages its memory
	std::string mFirstName;
	std::string mSecondName;
	std::string mLastName;
	BirthDate mBirthDate;
	std::string mAddress;
	User(std::string egn, std::string firstName, std::string secondName,
		std::string lastName, BirthDate birthDate,
		std::string address);
public:
	/* pure-virtual functions are automatically inherited as pure-virtual in the derived classes
	till the first implementation !*/
};

