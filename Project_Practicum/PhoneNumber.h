#pragma once
class PhoneNumber :
	public ISerializable
{
	char* mPhone;
public:
	virtual void serialize(std::ostream& os) override;
	virtual void deserialize(std::istream& is) override;

	PhoneNumber(const char* phone = "\0");
	
	PhoneNumber(const PhoneNumber& source);
	PhoneNumber& operator=(const PhoneNumber& rhs);

	PhoneNumber(PhoneNumber&& source);
	PhoneNumber& operator=(PhoneNumber&& rhs);

	~PhoneNumber();
};

