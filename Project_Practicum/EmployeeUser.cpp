#include "EmployeeUser.h"
#include "ClientManager.h"
#include "AccountManager.h"
#include "CardManager.h"

EmployeeUser::EmployeeUser(std::string username, std::string password, std::string egn, std::string firstName, std::string secondName, std::string lastName, BirthDate birthDate, std::string address, PhoneNumber phone) :
	User(egn, firstName, secondName, lastName, birthDate, address),
	mUsername{ username }, mPassword{ password }, mPhoneNumber{ phone }
{
}

EmployeeUser::EmployeeUser() : User(), mUsername{ "" }, mPassword{ "" }, mPhoneNumber{ "" }
{
}

std::string EmployeeUser::getUsername() const
{
	return mUsername;
}

std::string EmployeeUser::getPassword() const
{
	return mPassword;
}

void EmployeeUser::serialize(std::ostream& os)
{
	int usernameLength = mUsername.length();
	int passwordLength = mPassword.length();

	os.write((const char*)&usernameLength, sizeof(int));
	os.write(mUsername.c_str(), usernameLength);
	os.write((const char*)&passwordLength, sizeof(int));
	os.write(mPassword.c_str(), passwordLength);
	static_cast<User&>(*this).serialize(os);
	mPhoneNumber.serialize(os);
}

void EmployeeUser::deserialize(std::istream& is)
{
	int usernameLength;
	int passwordLength;

	is.read((char*)&usernameLength, sizeof(int));
	char* tempUsername = new char[usernameLength + 1];
	is.read(tempUsername, usernameLength);
	tempUsername[usernameLength] = '\0';
	mUsername = tempUsername;

	is.read((char*)&passwordLength, sizeof(int));
	char* tempPassword = new char[passwordLength + 1];
	is.read(tempPassword, passwordLength);
	tempPassword[passwordLength] = '\0';
	mPassword = tempPassword;

	static_cast<User&>(*this).deserialize(is);
	mPhoneNumber.deserialize(is);

	delete[] tempUsername;
	delete[] tempPassword;
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
		AccountManager* accountManager = AccountManager::getAccountManagerInstance();
		accountManager->removeAllAccountsAndCardsWithEgn(egn);
		std::cout << "Successfully deleted client with EGN: " << egn << "and all cards and accounts associated with it...\n";
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
		if (accountManager->removeAccount(egn, accountNumber) == 1) {
			CardManager* cardManager = CardManager::getCardManagerInstance();
			cardManager->removeAllCardsFromAccount(accountNumber);
		}
		else {
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

void EmployeeUser::printClientsReport()
{
	int index = 0;
	ClientManager* clientManager = ClientManager::getClientManagerInstance();
	for (ClientUser* client : clientManager->getClientsVector()) {
		std::cout << index << ". EGN: " << client->getUserEgn()
			<< "\n Accounts count: " << client->getAccountsCount()
			<< "\n  Cards count: " << client->getCardsCount() << "\n\n";
		index++;
	}
}

void EmployeeUser::printIndividualReport()
{
	std::string egn;
	std::cin >> egn;
	ClientManager* clientManager = ClientManager::getClientManagerInstance();
	if (clientManager->clientWithEgnExists(egn)) {
		std::cout << *(clientManager->getClientByEgn(egn));
	}
	else {
		std::cout << "Client with such EGN does not exist...\n";
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
