#include "EmployeeUser.h"
#include "ClientManager.h"
#include "AccountManager.h"
#include "CardManager.h"

EmployeeUser::EmployeeUser(std::string username, std::string password, std::string egn, std::string firstName, std::string secondName, std::string lastName, BirthDate birthDate, std::string address, PhoneNumber phone) :
	User(egn, firstName, secondName, lastName, birthDate, address),
	mUsername{ username }, mPassword{ password }, mPhoneNumber{ phone }
{
}

EmployeeUser::EmployeeUser() : User()
{
}

void EmployeeUser::serialize(std::ostream& os)
{
	os << mUsername << mPassword << mEgn << mFirstName
		<< mSecondName << mLastName << mBirthDate << mPhoneNumber << '\n';
}

void EmployeeUser::deserialize(std::istream& is)
{
	////maybe add legth of strings?
	//is >> mUsername >> mPassword >> mEgn >> mFirstName
	//	>> mSecondName >> mLastName >> mBirthDate >> mPhoneNumber >> '\n';
}

void EmployeeUser::addClient()
{
	ClientUser* client = new ClientUser();
	std::cin >> *client;
	ClientManager* clientManager = ClientManager::getClientManagerInstance();
	if (!clientManager->clientWithEgnExists(client->getUserEgn())) {
		clientManager->addClient(client);
	}
	else {
		std::cout << "Client with such Egn already exists...\n";
	}
	delete client;
}

void EmployeeUser::deleteClient()
{
	std::string egn;
	std::cout << "Enter client Egn: \n";
	std::cin >> egn;
	ClientManager* clientManager = ClientManager::getClientManagerInstance();
	if (clientManager->removeClientByEgn(egn) == 1) {
		std::cout << "Successfully deleted client with EGN: " << egn << '\n';
	}
	else {
		std::cout << "Couldn't find client with this egn...\n";
	}
}

void EmployeeUser::openAccount()
{
	std::string egn;
	double amount;
	std::cout << "Enter egn of client: ";
	std::cin >> egn;
	ClientManager* clientManager = ClientManager::getClientManagerInstance();
	if (clientManager->clientWithEgnExists(egn)) {
		std::cout << "Enter initial amount to be added: ";
		std::cin >> amount;
		AccountManager* accountManager = AccountManager::getAccountManagerInstance();
		accountManager->addAccount(egn, amount);
	}
	else {
		std::cout << "There is not client with such egn in the system...\n";
	}
}

void EmployeeUser::closeAccount()
{
	std::string egn;
	std::string accountNumber;
	std::cout << "Enter egn of client: ";
	std::cin >> egn;
	std::cout << "Enter account number to be closed: ";
	std::cin >> accountNumber;
	ClientManager* clientManager = ClientManager::getClientManagerInstance();
	if (clientManager->clientWithEgnExists(egn)) {
		AccountManager* accountManager = AccountManager::getAccountManagerInstance();
		if (accountManager->removeAccount(egn, accountNumber) == 0) {
			std::cout << "This client does not have account with this number...\n";
		}
	}
	else {
		std::cout << "There is not client with such egn in the system...\n";
	}
}

void EmployeeUser::addCardToAccount()
{
	std::string egn;
	std::cout << "Enter egn of client: ";
	std::cin >> egn;
	ClientManager* clientManager = ClientManager::getClientManagerInstance();
	if (clientManager->clientWithEgnExists(egn)) {
		std::string accountNumber;
		std::cout << "Enter account number in which the card should be created: ";
		std::cin >> accountNumber;
		AccountManager* accountManager = AccountManager::getAccountManagerInstance();
		if (accountManager->accountWithNumberExists(accountNumber)) {
			CardManager* cardManager = CardManager::getCardManagerInstance();
			cardManager->addCard(egn, accountNumber);
		}
		else {
			std::cout << "Account with number: " << accountNumber << " does not exist...\n";
		}
	}
	else {
		std::cout << "Client with egn: " << egn << " does not exist...\n";
	}
}

void EmployeeUser::deleteCardFromAccount()
{
	std::string egn;
	std::cout << "Enter egn of client: ";
	std::cin >> egn;
	ClientManager* clientManager = ClientManager::getClientManagerInstance();
	if (clientManager->clientWithEgnExists(egn)) {
		std::string accountNumber;
		std::string cardNumber;
		std::cout << "Enter account number card is assigned to: ";
		std::cin >> accountNumber;
		std::cout << "Enter PIN of card to be removed: ";
		std::cin >> cardNumber;
		CardManager* cardManager = CardManager::getCardManagerInstance();
		if (cardManager->removeCard(egn, accountNumber, cardNumber) == 0) {
			std::cout << "Entered invalid account or card number...\n";
		}
	}
	else {
		std::cout << "There is not client with such egn in the system...\n";
	}
}

std::istream& operator>>(std::istream& is, EmployeeUser& empUser)
{
	std::cout << "Enter username: \n";
	is >> empUser.mUsername;
	std::cout << "Enter password: \n";
	is >> empUser.mPassword;
	is >> static_cast<User&>(empUser);
	std::cout << "Enter phone number: \n";
	is >> empUser.mPhoneNumber;

	return is;
}
