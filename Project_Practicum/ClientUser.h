#pragma once
#include "ISerializable.h"
#include <vector>
#include "Account.h"
#include "User.h"
class ClientUser :
    public User
{
    friend std::istream& operator>>(std::istream& is, ClientUser& client);
    friend std::ostream& operator<<(std::ostream& os, ClientUser& client);

public:
    ClientUser(std::string egn, std::string firstName, std::string secondName,
        std::string lastName, BirthDate birthDate,
        std::string address);// check for =address
    ClientUser();

    virtual void serialize(std::ostream& os) override;
    virtual void deserialize(std::istream& is) override;

    int getAccountsCount() const;
    const std::vector<Account*> getAccounts() const;
    int getCardsCount() const;

    void deposit(std::string accountNumber);
    void withdraw(std::string accountNumber);
    double checkBalance(std::string accountNumber);
};

std::istream& operator>>(std::istream& is, ClientUser& client);
std::ostream& operator<<(std::ostream& os, ClientUser& client);