#pragma once
#include <vector>
#include "ClientUser.h"
class ClientManager
{
	std::vector<ClientUser*> mClients;

	static ClientManager* clientManager;
	ClientManager();
	~ClientManager();
public:
	static ClientManager* getClientManagerInstance();
	static void releaseClientManagerInstance();

	void addClient(ClientUser* client);
	bool removeClient(std::string egn);
};

