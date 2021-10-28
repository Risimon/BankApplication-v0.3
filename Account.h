#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
using std::cout;
using std::endl;

const int NAME_LEN = 40;
const int MAX_ACC_NUM = 100;

class Account {
private:
    int m_accId;
    int m_balance;
    char* m_cusName;
public:
    Account(int id, int balance, char* name);
    Account(const Account& cp);
    Account();
    ~Account();
    int getAccId() const;
    void deposit(int money);
    int withdraw(int money);
    void showAccInfo() const;
    int getBalance()const;
};
#endif