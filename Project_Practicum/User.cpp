#include "User.h"
#include "EmployeeManager.h"
#include "ClientManager.h"

User::User(std::string egn, std::string firstName, std::string secondName, std::string lastName, BirthDate birthDate, std::string address) :
	mEgn{ egn }, mFirstName{ firstName }, mSecondName{ secondName }, mLastName{ lastName }, mBirthDate{ birthDate },
	mAddress{address}
{
}

User::User()
{
}

std::string User::getUserEgn() const
{
	return mEgn;
}

void User::serialize(std::ostream& os)
{
	int egnLength = mEgn.length();
	int firstNameLength = mFirstName.length();
	int secondNameLength = mSecondName.length();
	int lastNameLength = mLastName.length();
	int addressLength = mAddress.length();

	os.write((const char*)&egnLength, sizeof(int));
	os.write(mEgn.c_str(), egnLength);

	os.write((const char*)&firstNameLength, sizeof(int));
	os.write(mFirstName.c_str(), firstNameLength);

	os.write((const char*)&secondNameLength, sizeof(int));
	os.write(mSecondName.c_str(), secondNameLength);

	os.write((const char*)&lastNameLength, sizeof(int));
	os.write(mLastName.c_str(), lastNameLength);

	mBirthDate.serialize(os);

	os.write((const char*)&addressLength, sizeof(int));
	os.write(mAddress.c_str(), addressLength);
}

void User::deserialize(std::istream& is)
{
	int egnLength, firstNameLength, secondNameLength, lastNameLength, addressLength;

	is.read((char*)&egnLength, sizeof(int));
	char* tempEgn = new char[egnLength + 1];
	is.read(tempEgn, egnLength);
	tempEgn[egnLength] = '\0';
	mEgn = tempEgn;

	is.read((char*)&firstNameLength, sizeof(int));
	char* tempFirstName = new char[firstNameLength + 1];
	is.read(tempFirstName, firstNameLength);
	tempFirstName[firstNameLength] = '\0';
	mFirstName = tempFirstName;

	is.read((char*)&secondNameLength, sizeof(int));
	char* tempSecondName = new char[secondNameLength + 1];
	is.read(tempSecondName, secondNameLength);
	tempSecondName[secondNameLength] = '\0';
	mSecondName = tempSecondName;

	is.read((char*)&lastNameLength, sizeof(int));
	char* tempLastName = new char[lastNameLength + 1];
	is.read(tempLastName, lastNameLength);
	tempLastName[lastNameLength] = '\0';
	mLastName = tempLastName;

	mBirthDate.deserialize(is);

	is.read((char*)&addressLength, sizeof(int));
	char* tempAddress = new char[addressLength + 1];
	is.read(tempAddress, addressLength);
	tempAddress[addressLength] = '\0';
	mAddress = tempAddress;


	delete[] tempAddress;
	delete[] tempEgn;
	delete[] tempFirstName;
	delete[] tempLastName;
	delete[] tempSecondName;
}

bool containsDigitsOnly(const std::string& str) {
	for (char c : str) {
		if (!std::isdigit(c)) {
			return 0;
		}
	}
	return 1;
}

std::istream& operator>>(std::istream& is, User& user)
{
	EmployeeManager* empManager = EmployeeManager::getEmployeeManagerInstance();
	ClientManager* clientManager = ClientManager::getClientManagerInstance();
	std::cout << "Enter egn: \n";
	is >> user.mEgn;
	if (user.mEgn.length() == 10 && containsDigitsOnly(user.mEgn)) {
		if (empManager->checkEgnAlreadyRegistered(user.mEgn) || clientManager->clientWithEgnExists(user.mEgn)) {
			std::cout << "Egn already exists\n";
			throw std::exception("Egn already exists\n");
		}
	}
	std::cout << "Input first name: \n";
	is >> user.mFirstName;
	std::cout << "Input middle name: \n";
	is >> user.mSecondName;
	std::cout << "Input last name: \n";
	is >> user.mLastName;
	std::cout << "Input date of birth: \n";
	is >> user.mBirthDate;
	std::cin.ignore(256, '\n');
	std::cout << "Input an address: \n";
	std::getline(is,user.mAddress, '\n');

	return is;
}

std::ostream& operator<<(std::ostream& os, User& user)
{
	os << "EGN: " << user.mEgn << "\nName: " << user.mFirstName << " " << user.mSecondName
		<< " " << user.mLastName << "\nBirthday: " << user.mBirthDate << "\nAddress: " 
		<< user.mAddress << '\n';
	return os;
}
