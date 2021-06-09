#pragma once
#include "ISerializable.h"
class BirthDate :
	public ISerializable
{
	friend std::istream& operator>>(std::istream& is, BirthDate& birthDate);
	friend std::ostream& operator<<(std::ostream& os, const BirthDate& birthDate);

	std::string mDate;
public:
	BirthDate();
	BirthDate(std::string birthDate);
	bool validInput(std::string dateToValidate);

	std::string getDate() const;

	virtual void serialize(std::ostream& os) override;
	virtual void deserialize(std::istream& is) override;

};
std::istream& operator>>(std::istream& is, BirthDate& birthDate);
std::ostream& operator<<(std::ostream& os,const BirthDate& birthDate);
