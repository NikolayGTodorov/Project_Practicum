#include "PhoneNumber.h"

void PhoneNumber::serialize(std::ostream& os)
{
	int phoneLength = mPhone.length();

	os.write((const char*)&phoneLength, sizeof(int));
	os.write(mPhone.c_str(), phoneLength);
}

void PhoneNumber::deserialize(std::istream& is)
{
	int phoneLength;
	is.read((char*)&phoneLength, sizeof(int));
	char* tempPhone = new char[phoneLength + 1];
	is.read(tempPhone, phoneLength);
	tempPhone[phoneLength] = '\0';
	mPhone = tempPhone;

	delete[] tempPhone;
}

PhoneNumber::PhoneNumber(std::string phone) : mPhone{ phone }
{
}

bool isDigitsOnly(const std::string& str) {
	for (char c : str) {
		if (!std::isdigit(c)) {
			return 0;
		}
	}
	return 1;
}

std::istream& operator>>(std::istream& is, PhoneNumber& phoneNumber)
{
	is >> phoneNumber.mPhone;
	if (phoneNumber.mPhone.length() > 15 || !isDigitsOnly(phoneNumber.mPhone)) {
		throw std::invalid_argument("Phone number is digits only and less than 15 digits");
	}
	return is;
}
