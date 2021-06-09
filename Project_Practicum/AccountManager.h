#pragma once
#include <vector>
#include "Account.h"
#include "ISerializable.h"
class AccountManager : public ISerializable
{
	std::vector<Account*> mAccounts;
	AccountManager();
	~AccountManager();
	static AccountManager* accountManager;
public:
	static AccountManager* getAccountManagerInstance();
	static void releaseAccountManagerInstance();

	bool accountWithNumberExists(std::string accountNumber);
	std::string generateAccountNumber(std::string egn);

	void addAccount(std::string egn, double balance);
	bool removeAccount(std::string egn, std::string accountNumber);

	void addCashToAccount(std::string accountNumber, double toAdd);
	void substractCashToAccount(std::string accountNumber, double toWithdraw);
	double getAccountBalanceByNumber(std::string accountNumber) const;

	const std::vector<Account*> getAllAccountsByEgn(std::string egn) const;
	
	void removeAllAccountsAndCardsWithEgn(std::string ownerEgn);

	virtual void serialize(std::ostream& os);
	virtual void deserialize(std::istream& is);
};

