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

bool ClientManager::removeClient(std::string egn)
{
	int index = 0;
	for (ClientUser* client : mClients) {
		index++;
		if (client->getUserEgn() == egn) {
			delete mClients[index];
			mClients.erase(mClients.begin() + index);
			return 1;
		}
	}
	return 0;
}
