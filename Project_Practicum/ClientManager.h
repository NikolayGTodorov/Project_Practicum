#pragma once
#include <vector>
#include "ClientUser.h"

class ClientManager : public ISerializable
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

	const std::vector<ClientUser*> getClientsVector() const;
	ClientUser* getClientUserByAccountNumber(std::string accountNumber) const;
	ClientUser* getClientByEgn(std::string egn) const;
	bool clientWithEgnExists(std::string egn) const;

	// Inherited via ISerializable
	virtual void serialize(std::ostream& os) override;
	virtual void deserialize(std::istream& is) override;

};

