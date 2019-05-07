#include "Account.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

Account::Account(){
    name = "";
    id = 0;
    balance = 0;
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
    if (newId < 1)
        throw std::domain_error("~ ID cannot be zero or negative ~");

    id = newId;
}

void Account::setBalance(double newBalance){
    if (newBalance < 0)
<<<<<<< HEAD
        throw std::domain_error("~ Balance cannot be negative ~");

=======
        throw "\n\t\t\t\t  ~ Balance cannot be negative ~";
    
>>>>>>> 083713312e2ca20bbf9914fae8e2625564e3587c
    balance = newBalance;
}

void Account::withdraw(double amount){
    if (amount < 0)
        throw std::domain_error("~ Withdrawal amount cannot be negative ~");

    balance -= amount;
}

void Account::deposit(double amount){
    if (amount < 0)
        throw std::domain_error("~ Deposit amount cannot be negative ~");

    balance += amount;
}
