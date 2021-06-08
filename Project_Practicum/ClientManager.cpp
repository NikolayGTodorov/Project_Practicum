#include "ClientManager.h"

ClientManager* ClientManager::clientManager = 0;

ClientManager::ClientManager() : mClients{ std::vector<ClientUser*>() }
{
}

ClientManager::~ClientManager()
{
	for (ClientUser* client : mClients) {
		delete client;
	}
	mClients.clear();
}

ClientManager* ClientManager::getClientManagerInstance()
{
	if (!clientManager) {
		clientManager = new ClientManager();
	}
	return clientManager;
}

void ClientManager::releaseClientManagerInstance()
{
	delete clientManager;
}

void ClientManager::addClient(ClientUser* client)
{
	mClients.push_back(new ClientUser(*client));
}

bool ClientManager::removeClientByEgn(std::string egn)
{
	int index = 0;
	for (ClientUser* client : mClients) {
		if (client->getUserEgn() == egn) {
			delete mClients[index];
			mClients.erase(mClients.begin() + index);
			return 1;
		}
		index++;
	}
	return 0;
}

const std::vector<ClientUser*> ClientManager::getClientsVector() const
{
	return mClients;
}

ClientUser* ClientManager::getClientUserByAccountNumber(std::string accountNumber) const
{
	for (ClientUser* client : mClients) {
		for (Account* account : client->getAccounts()) {
			if (account->getAccountNumber() == accountNumber) {
				return client;
			}
		}
	}
}


bool ClientManager::clientWithEgnExists(std::string egn) const
{
	for (ClientUser* client : mClients) {
		if (client->getUserEgn() == egn) {
			return 1;
		}
	}
	return 0;
}

ClientUser* ClientManager::getClientByEgn(std::string egn) const
{
	if (clientWithEgnExists(egn)) {
		for (ClientUser* client : mClients) {
			if (client->getUserEgn() == egn) {
				return client;
			}
		}
	}
	else {
		std::cout << "Couldn't find client with this egn\n";
	}
}

void ClientManager::serialize(std::ostream& os)
{
	int vectorSize = mClients.size();
	os.write((const char*)&vectorSize, sizeof(int));
	for (int i = 0; i < vectorSize; i++) {
		mClients[i]->serialize(os);
	}
}

void ClientManager::deserialize(std::istream& is)
{
	int size;
	mClients.clear();
	is.read((char*)&size, sizeof(int));
	mClients.resize(size + 1);
	for (int i = 0; i < size; i++) {
		mClients[i] = new ClientUser();
		mClients[i]->deserialize(is);
	}
}


