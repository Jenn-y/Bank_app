#include "Transaction.h"
#include "Account.h"
#include <stdexcept>
#include <iostream>
#include <ctime>

Transaction::Transaction(Account *src, Account *target, double money, const std::string& desc){
    if (money <= 0) throw std::domain_error("~ Transaction amount must be positive ~");
    sourceAccount = src;
    targetAccount = target;
    amount = money;
    date = setDate();
    description = desc;
    performTransaction();
}
std::string Transaction::setDate(){
    time_t t;
    time(&t);
    return ctime(&t);
}
void Transaction::performTransaction() {
    validateBalance();
    (*sourceAccount).withdraw(amount);
    (*targetAccount).deposit(amount);
}
void Transaction::validateBalance() const {
    if ((*sourceAccount).getBalance() < amount)
        throw std::domain_error("~ Balance insufficient ~");
}
Account Transaction::getSourceAccount() const{
    return *sourceAccount;
}
Account Transaction::getTargetAccount() const{
    return *targetAccount;
}
double Transaction::getAmount() const{
    return amount;
}
void Transaction::DisplayTransactionInfo() const{
    std::cout << "\n\t\t\t\t\t~ Source account name: " << (*sourceAccount).getName()
              << "\n\t\t\t\t\t~ Target account name: " << (*targetAccount).getName()
              << "\n\t\t\t\t\t~ Transaction amount: " << amount
              << "\n\t\t\t\t\t~ Date: " << date
              << "\n\t\t\t\t\t~ Transaction description (if provided)"
              << "\n\t\t\t\t\t- " << description << "-\n\n";
}
