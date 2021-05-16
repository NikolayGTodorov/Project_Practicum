#pragma once
#include "ClientUser.h"
class EmployeeUser :
    public ClientUser
{
    std::string mUsername;
    std::string mPassword;
    PhoneNumber mPhoneNumber;
public:
    ClientUser(std::string username, std::string password, PhoneNumber phone);

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

