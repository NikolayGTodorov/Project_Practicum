#pragma once
#include <fstream>
class ISerializable
{
	friend std::ostream& operator<<(std::ostream& os, ISerializable& obj);  //write in file
	friend std::istream& operator>>(std::istream& is, ISerializable& obj);  //read from file
public:
	virtual void serialize(std::ostream& os) = 0;
	virtual void deserialize(std::istream& is) = 0;
};

std::ostream& operator<<(std::ostream& os, ISerializable& obj);
std::istream& operator>>(std::istream& is, ISerializable& obj);

