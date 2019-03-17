#include "Account.h"
#include <string>
#include <iostream>
#include <vector>

Account::Account(){}

std::vector<Account> Account::accountDatabase;

void Account::addAccount(Account account){
    accountDatabase.push_back(account);
}

std::string Account::getName() const{
    return name;
}

int Account::getId() const{
    return id;
}

double Account::getBalance() const{
    return balance;
}

void Account::setName(std::string userName){
    name = userName;
}

void Account::setID(int newId){
    for (int i = 0; i < accountDatabase.size(); i++){
        if (newId == accountDatabase[i].getId()){
            std::cout << "\n\t\t\t\t~ Entered ID is already in use ~"
                      << "\n\t\t\t\t--> Enter ID: ";
            std::cin >> newId;
            i = 0;
        }
    }
    id = newId;
}

void Account::setBalance(double newBalance){
    balance = newBalance;
}

void Account::withdraw(double amount){
    balance -= amount;
}

void Account::deposit(double amount){
    balance += amount;
}
