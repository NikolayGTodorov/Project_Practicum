#include "BirthDate.h"
#include <string>
#include <iostream>
#include <time.h>
const short int LOWEST_YEAR = 1900;


BirthDate::BirthDate(std::string birthDate)
{
	if (validInput(birthDate)) {
		mDate = birthDate;
	}
}

bool BirthDate::validInput(std::string dateToValidate)
{
	std::string temp;

	bool validDay = 0;
	bool validMonth = 0;
	bool validYear = 0;

	time_t t = time(0);
	std::tm* now = std::localtime(&t);
	temp = dateToValidate.substr(6, 10);
	int year = std::stoi(temp);
	validYear = (year > LOWEST_YEAR && year <= now->tm_year + 1780); //get the current year - 120
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
	validDay = (std::stoi(temp) > 0 && std::stoi(temp) <= getDaysInMonth(year,month));

	return (validDay && validMonth && validYear);

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
	else if (month == 1 || month == 3 || month == 5 || month==7 || month == 8 || month == 10 || month == 12) {
		return 31;
	}
	else {
		return 30;
	}
}