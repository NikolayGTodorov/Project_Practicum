#include "BirthDate.h"
#include <string>
#include <iostream>
#include <time.h>


BirthDate::BirthDate() : mDate{""}
{
}

BirthDate::BirthDate(std::string birthDate)
{

	if (validInput(birthDate)) {
		mDate = birthDate;
	}

}

int getDaysInMonth(int year, int month) {
	if (month == 2) {
		if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
			return 29;
		}
		else {
			return 28;
		}
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		return 31;
	}
	else {
		return 30;
	}
}

bool BirthDate::validInput(std::string dateToValidate)
{
	std::string temp;
	if (dateToValidate.length() != 10) {
		std::cout << "Birthday is in format dd/mm/yyyy\n";
		return 0;
	}

	bool validDay = 0;
	bool validMonth = 0;
	bool validYear = 0;

	time_t t = time(0);
	struct tm now;
	localtime_s(&now, &t);

	temp = dateToValidate.substr(6, 10);
	int year = std::stoi(temp);
	validYear = (year > now.tm_year + 1780 && year <= now.tm_year + 1900);
	if (!validYear) {
		return 0;
	}
	temp = dateToValidate.substr(3, 5);
	int month = std::stoi(temp);
	validMonth = (month > 0 && month <= 12);
	if (!validMonth) {
		return 0;
	}

	temp = dateToValidate.substr(0, 2);
	validDay = (std::stoi(temp) > 0 && std::stoi(temp) <= getDaysInMonth(year, month));

	return (validDay && validMonth && validYear);

}

std::string BirthDate::getDate() const
{
	return mDate;
}

void BirthDate::serialize(std::ostream& os)
{
	int birthdateLength = mDate.length();

	os.write((const char*)&birthdateLength, sizeof(int));
	os.write(mDate.c_str(), birthdateLength);
}

void BirthDate::deserialize(std::istream& is)
{
	int birthdateLength;
	is.read((char*)&birthdateLength, sizeof(int));
	char* tempDate = new char[birthdateLength + 1];
	is.read(tempDate, birthdateLength);
	tempDate[birthdateLength] = '\0';
	mDate = tempDate;

	delete[] tempDate;
}

std::istream& operator>>(std::istream& is, BirthDate& birthDate)
{
	std::cout << "Enter date in format mm/dd/yyyy: \n";
	is >> birthDate.mDate;
	return is;
}

std::ostream& operator<<(std::ostream& os, const BirthDate& birthDate)
{
	os << birthDate.mDate;
	return os;
}
