#pragma once
#include "ISerializable.h"
#include <vector>
#include "Account.h"
#include "User.h"
class ClientUser :
    public User, public ISerializable
{
    friend std::istream& operator>>(std::istream& is, ClientUser& client);

    std::vector<Account*> mUserAccounts;
public:
    ClientUser(std::vector<Account*> userAccounts, 
        std::string egn, std::string firstName, std::string secondName,
        std::string lastName, BirthDate birthDate,
        std::string address);// check for =address
    ClientUser();

    virtual void serialize(std::ostream& os) override;
    virtual void deserialize(std::istream& is) override;

    int getAccountsCount() const;
    std::vector<Account*> getAccounts() const;
    int getCardsCount() const;

    void deposit(double amountToDeposit);
    void withdraw(double amountToWithdraw);
    double checkBalance();
};

std::istream& operator>>(std::istream& is, ClientUser& client);