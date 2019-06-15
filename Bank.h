#ifndef BANK.H
#define BANK.H
#include "Account.h"
#include "Transaction.h"
#include <iostream>
#include <vector>
#include <map>

class Bank{
    static std::map<int, Account> accountDatabase;
    static std::map<int, std::vector<Transaction>> transactionDatabase;
    std::string format(std::string);
    int userIDInput();
    bool findAccount(int);
    public:
    Bank();
    void createAccount();
    void printAccountSummary();
    void checkBalance();
    void withdraw();
    void deposit();
    void performTransaction();
    void printTransactions();
    void exit() const;
    template<typename Type>
    void getInput(Type &value){
        while (true){
            std::cin >> value;
            if (std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << format("~ Invalid input ~ --> Enter again: ");
            }
            else {
                std::cin.ignore();
                return;
            }
        }
    }
};
#endif // BANK
