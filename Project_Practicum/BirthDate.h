#pragma once
#include "ISerializable.h"
class BirthDate :
	public ISerializable
{
	std::string mDate;
public:
	BirthDate(std::string birthDate);
	bool validInput(std::string dateToValidate);

	virtual void serialize(std::ostream& os) override;
	virtual void deserialize(std::istream& is) override;

};

