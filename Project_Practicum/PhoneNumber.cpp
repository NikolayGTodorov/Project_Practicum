#include "PhoneNumber.h"

void PhoneNumber::serialize(std::ostream& os)
{
}

void PhoneNumber::deserialize(std::istream& is)
{
}

PhoneNumber::PhoneNumber(std::string phone) : mPhone{ phone }
{
}

std::istream& operator>>(std::istream& is, PhoneNumber& phoneNumber)
{
	is >> phoneNumber.mPhone;
	return is;
}
