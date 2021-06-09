#pragma once
#include "ISerializable.h"
#include "BirthDate.h"
#include <iostream>
class User : public ISerializable
{
	friend std::istream& operator >>(std::istream& is, User& user);
	friend std::ostream& operator<<(std::ostream& os, const User& user);
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
	BirthDate getBirthDate() const;

	// Inherited via ISerializable
	virtual void serialize(std::ostream& os) override;
	virtual void deserialize(std::istream& is) override;
};

std::istream& operator >>(std::istream& is, User& user);
std::ostream& operator<<(std::ostream& os, const User& user);
