#include "Transaction.h"
#include "Account.h"
#include <stdexcept>
#include <iostream>

Transaction::Transaction(Account *src, Account *target, double amount){
    sourceAccount = src;
    targetAccount = target;
    this->amount = amount;
    performTransaction();
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
    std::cout << "\n\t\t\t\t\t~ Source account ID: " << (*sourceAccount).getId()
              << "\n\t\t\t\t\t~ Target account ID: " << (*targetAccount).getId()
              << "\n\t\t\t\t\t~ Transaction amount: " << amount << "\n";
}
