#include "AccountHandler.h"
using std::cin;

void AccountHandler::showAllAccInfo() const{
    for (int i = 0; i < accNum; i++) {
        accArr[i]->showAccInfo();
    }
}
AccountHandler::~AccountHandler()
{
    for (int i = 0; i < accNum; i++) {
        delete accArr[i];
    }
}
void AccountHandler::showMenu() const{
    cout << "------Menu------" << endl;
    cout << "1. Make Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdrawal" << endl;
    cout << "4. Display all" << endl;
    cout << "5. Exit program" << endl;
}
int AccountHandler::getAccIdx(int id) {
    for (int i = 0; i < accNum; i++) {
        if (accArr[i]->getAccId() == id) {
            return i;
        }
    }
    return -1;
}
void AccountHandler::makeAccount() {
    int id;
    char name[NAME_LEN];
    int balance;
    //char pin[4];

    if (accNum >= MAX_ACC_NUM) {
        cout << "Sorry! Cannot make an account anymore." << endl;
        return;
    }
    cout << "[Make Account]" << endl;
    cout << "Account ID: ";
    cin >> id;

    if (getAccIdx(id) != -1) {
        cout << "Error: Existing account ID" << endl;
        return;
    }
    cout << "Customer Name: ";
    cin >> name;
    cout << "Deposit amount: ";
    cin >> balance;
    cout << endl;

    accArr[accNum] = new Account(id, balance, name);
    accNum++;
}

void AccountHandler::depositMoney() {
    int money;
    int id;
    cout << "[Deposit]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Deposit amount: ";
    cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i]->getAccId() == id) {
            accArr[i]->deposit(money);
            cout << "Deposit completed" << endl << endl;
            return;
        }
    }
    cout << "This ID is not valid." << endl << endl;
}
void AccountHandler::withdrawMoney() {
    int money;
    int id;
    //char pin[4];
    cout << "[Withdrawal]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Withdrawal amount: ";
    cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i]->getAccId() == id) {
            if (accArr[i]->getBalance() < money) {
                cout << "Not enough balance" << endl << endl;
                return;
            }
            accArr[i]->withdraw(money);
            cout << "Withdrawal completed" << endl << endl;
            return;
        }
    }
    cout << "ID or PIN is invalid." << endl << endl;
}
