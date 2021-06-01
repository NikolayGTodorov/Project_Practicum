#pragma once
#include "ISerializable.h"
class BirthDate :
	public ISerializable
{
	friend std::istream& operator>>(std::istream& is, BirthDate& birthDate);

	std::string mDate;
public:
	BirthDate();
	BirthDate(std::string birthDate);
	bool validInput(std::string dateToValidate);

	virtual void serialize(std::ostream& os) override;
	virtual void deserialize(std::istream& is) override;

};
std::istream& operator>>(std::istream& is, BirthDate& birthDate);
