#pragma once
class PhoneNumber
{
	char* mPhone;
public:
	PhoneNumber(const char* phone = "\0");
	
	PhoneNumber(const PhoneNumber& source);
	PhoneNumber& operator=(const PhoneNumber& rhs);

	PhoneNumber(PhoneNumber&& source);
	PhoneNumber& operator=(PhoneNumber&& rhs);

	~PhoneNumber();
};

