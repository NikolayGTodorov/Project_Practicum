#include "ISerializable.h"

std::ostream& operator<<(std::ostream& os, ISerializable& obj)
{
	obj.serialize(os);
	return os;
}

std::istream& operator>>(std::istream& is, ISerializable& obj)
{
	obj.deserialize(is);
	return is;
}
