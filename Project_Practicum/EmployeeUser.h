#pragma once
#include "ClientUser.h"
#include "User.h"
#include "ISerializable.h"
#include "PhoneNumber.h"
#include "EmployeeManager.h"

class EmployeeUser :
    public User
{
    friend std::istream& operator>>(std::istream& is, EmployeeUser& empUser);
    std::string mUsername;
    std::string mPassword;
    PhoneNumber mPhoneNumber;
public:
    EmployeeUser(std::string username, std::string password,
        std::string egn, std::string firstName, std::string secondName,
        std::string lastName, BirthDate birthDate,
        std::string address,PhoneNumber phone);
    EmployeeUser();

    std::string getUsername() const;
    std::string getPassword() const;
    std::string getPhoneNumber() const;

    void addClient();
    void deleteClient();
    void openAccount();
    void closeAccount();
    void addCardToAccount();
    void deleteCardFromAccount();
    void printClientsReport();
    void printIndividualReport();

    virtual void serialize(std::ostream& os) override;
    virtual void deserialize(std::istream& is) override;

};

std::istream& operator>>(std::istream& is, EmployeeUser& empUser);
bool containsDigitsOnly(const std::string& str);