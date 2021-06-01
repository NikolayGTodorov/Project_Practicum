#pragma once
#include <iostream>
#include "ISerializable.h"
class PhoneNumber :
	public ISerializable
{
	friend std::istream& operator>>(std::istream& is, PhoneNumber& phoneNumber);

	char* mPhone;
public:
	virtual void serialize(std::ostream& os) override;
	virtual void deserialize(std::istream& is) override;

	PhoneNumber(const char* phone = "\0");
	
	PhoneNumber(const PhoneNumber& source);
	PhoneNumber& operator=(const PhoneNumber& rhs);

	PhoneNumber(PhoneNumber&& source);
	PhoneNumber& operator=(PhoneNumber&& rhs);

	~PhoneNumber();
};

std::istream& operator>>(std::istream& is, PhoneNumber& phoneNumber);