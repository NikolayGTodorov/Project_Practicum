#pragma once
#include "ISerializable.h"
#include "BirthDate.h"
class ClientUser :
    public ISerializable
{
    //Add Account*
    std::string mEgn;   // maybe change this to my class EGN which has char[10] and manages its memory
    std::string mFirstName;
    std::string mSecondName;
    std::string mLastName;
    BirthDate mBirthDate;
    std::string mAddress;
public:
    

    virtual void serialize(std::ostream& os) override;
    virtual void deserialize(std::istream& is) override;

    void deposit(double amountToDeposit);
    void withdraw(double amountToWithdraw);
    double checkBalance();
};

