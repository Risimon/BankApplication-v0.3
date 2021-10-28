#include "AccountHandler.h"
using namespace std;

enum class bank { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

int main() {
    AccountHandler manager;
    int choice;
    bool run = true;

    while (true) {
        manager.showMenu();
        cout << "Select menu: ";
        cin >> choice;
        cout << endl;

        switch (bank(choice)) {
        case bank::MAKE:
            manager.makeAccount();
            break;
        case bank::DEPOSIT:
            manager.depositMoney();
            break;
        case bank::WITHDRAW:
            manager.withdrawMoney();
            break;
        case bank::INQUIRE:
            manager.showAllAccInfo();
            break;
        case bank::EXIT:
            return 0;
        default:
            cout << "Illegal selection.." << endl;
        }
    }
}
