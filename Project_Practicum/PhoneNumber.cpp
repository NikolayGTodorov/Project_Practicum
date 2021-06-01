#include "PhoneNumber.h"

void PhoneNumber::serialize(std::ostream& os)
{
}

void PhoneNumber::deserialize(std::istream& is)
{
}

PhoneNumber::PhoneNumber(const char* phone)
{
	if (strlen(phone) <= 15) {
		int size = strlen(phone) + 1;
		mPhone = new char[size];
		strcpy_s(mPhone, size, phone);
	}
	else {
	throw std::invalid_argument("Enter valid number please");

	}
}

PhoneNumber::PhoneNumber(const PhoneNumber& source)
{
	delete[] mPhone;
	int size = strlen(source.mPhone) + 1;
	mPhone = new char[size];
	strcpy_s(mPhone, size, source.mPhone);
}

PhoneNumber& PhoneNumber::operator=(const PhoneNumber& rhs)
{
	if (this != &rhs) {
		delete[] mPhone;
		int size = strlen(rhs.mPhone) + 1;
		mPhone = new char[size];
		strcpy_s(mPhone, size, rhs.mPhone);
	}
	return *this;
}

PhoneNumber::PhoneNumber(PhoneNumber&& source) : mPhone{source.mPhone}
{
	source.mPhone = nullptr;
}

PhoneNumber& PhoneNumber::operator=(PhoneNumber&& rhs)
{
	if (this != &rhs) {
		delete[] mPhone;
		mPhone = rhs.mPhone;
		rhs.mPhone = nullptr;
	}
	return *this;
}

PhoneNumber::~PhoneNumber()
{
	delete[] mPhone;
}

std::istream& operator>>(std::istream& is, PhoneNumber& phoneNumber)
{
	is >> phoneNumber.mPhone;
	return is;
}
