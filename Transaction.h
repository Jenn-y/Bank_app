#ifndef TRANSACTION.H
#define TRANSACTION.H
#include "Account.h"
#include <string>

class Transaction{
    Account *sourceAccount, *targetAccount;
    double amount;
    std::string date, description;
    void performTransaction();
    void validateBalance() const;
    std::string setDate();
public:
    Transaction(Account*, Account*, double, const std::string&);
    Account getSourceAccount() const;
    Account getTargetAccount() const;
    double getAmount() const;
    void DisplayTransactionInfo() const;
};
#endif
