#pragma once
#include "ISerializable.h"
#include <vector>
#include "Account.h"
#include "User.h"
class ClientUser :
    public User
{
    std::vector<Account*> userAccounts;
public:
    //Create constructor

    virtual void serialize(std::ostream& os) override;
    virtual void deserialize(std::istream& is) override;

    void deposit(double amountToDeposit);
    void withdraw(double amountToWithdraw);
    double checkBalance();
};

