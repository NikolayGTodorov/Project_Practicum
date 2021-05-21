#pragma once
#include "ClientUser.h"
#include "User.h"
#include "PhoneNumber.h"
class EmployeeUser :
    public User
{
    std::string mUsername;
    std::string mPassword;
    PhoneNumber mPhoneNumber;
public:
    EmployeeUser(std::string username, std::string password,
        std::string egn, std::string firstName, std::string secondName,
        std::string lastName, BirthDate birthDate,
        std::string address,PhoneNumber phone);

    virtual void serialize(std::ostream& os) override;
    virtual void deserialize(std::istream& is) override;

    void addClient();
    void deleteClient();
    void openAccount();
    void addCardToAccount();
    void closeAccount();
    void deleteCardFromAccount();
    void printClientsReport();
    void printIndividualReport();

};

