#include "User.h"

User::User(std::string egn, std::string firstName, std::string secondName, std::string lastName, BirthDate birthDate, std::string address) :
	mEgn{ egn }, mFirstName{ firstName }, mSecondName{ secondName }, mLastName{ lastName }, mBirthDate{ birthDate },
	mAddress{address}
{
}
