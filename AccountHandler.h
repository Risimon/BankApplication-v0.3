#ifndef ACCOUNTHANDLER_H
#define ACCOUNTHANDLER_H
#include "Account.h"

class AccountHandler
{
	Account* accArr[MAX_ACC_NUM];
	int accNum = 0;

	int getAccIdx(int id);
public:
	void showMenu() const;
	void makeAccount();
	void depositMoney();
	void withdrawMoney();
	void showAllAccInfo() const;
	~AccountHandler();
};

#endif