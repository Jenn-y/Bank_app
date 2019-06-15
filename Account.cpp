#include "Account.h"
#include <iostream>
#include <string>
#include <stdexcept>

Account::Account(std::string newName, int newId, double newBalance){
   name = newName;
   setID(newId);
   setBalance(newBalance);
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
        throw std::domain_error("~ Balance cannot be negative ~");

    balance = newBalance;
}

void Account::withdraw(double amount){
    if (amount <= 0)
        throw std::domain_error("~ Withdrawal amount cannot be zero or negative - Withdrawal not successful ~");
    if (amount > balance)
        throw std::domain_error("~ Withdrawal amount too high - Withdrawal not successful ~");

    balance -= amount;
}

void Account::deposit(double amount){
    if (amount <= 0)
        throw std::domain_error("~ Deposit amount cannot be zero or negative - Deposit not successful ~");

    balance += amount;
}
