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
	bool removeClientByEgn(std::string egn);

	bool clientWithEgnExists(std::string egn) const;
	ClientUser* getClientByEgn(std::string egn) const;
	bool clientHasAccountWithNumber(std::string ) const;

};

