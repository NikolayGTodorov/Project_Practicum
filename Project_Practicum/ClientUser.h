#pragma once
#include "ISerializable.h"
#include <vector>
#include "Account.h"
#include "User.h"
class ClientUser :
    public User, public ISerializable
{
    std::vector<Account*> mUserAccounts;
public:
    ClientUser(std::vector<Account*> userAccounts, 
        std::string egn, std::string firstName, std::string secondName,
        std::string lastName, BirthDate birthDate,
        std::string address);// check for =address

    virtual void serialize(std::ostream& os) override;
    virtual void deserialize(std::istream& is) override;

    void deposit(double amountToDeposit);
    void withdraw(double amountToWithdraw);
    double checkBalance();
};

