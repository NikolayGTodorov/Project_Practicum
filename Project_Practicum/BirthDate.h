#pragma once
#include "ISerializable.h"
class BirthDate :
	public ISerializable
{
	short int mDay;
	short int mMonth;
	short int mYear;
public:
	BirthDate(short int day, short int month, short int year);
	bool validate(short int day, short int month, short int year);

	virtual void serialize(std::ostream& os) override;
	virtual void deserialize(std::istream& is) override;

};

