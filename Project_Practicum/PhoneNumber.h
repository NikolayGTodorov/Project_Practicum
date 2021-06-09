#pragma once
#include <iostream>
#include "ISerializable.h"
#include <string>
class PhoneNumber :
	public ISerializable
{
	friend std::istream& operator>>(std::istream& is, PhoneNumber& phoneNumber);

	std::string mPhone;
public:
	virtual void serialize(std::ostream& os) override;
	virtual void deserialize(std::istream& is) override;

	std::string getPhone() const;

	PhoneNumber();
	PhoneNumber(std::string phone);
};

std::istream& operator>>(std::istream& is, PhoneNumber& phoneNumber);