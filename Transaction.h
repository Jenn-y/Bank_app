#ifndef TRANSACTION.H
#define TRANSACTION.H
#include "Account.h"

class Transaction{
    Account *sourceAccount, *targetAccount;
    double amount;
    void performTransaction();
    void validateBalance() const;
public:
    Transaction(Account*, Account*, double);
    Account getSourceAccount() const;
    Account getTargetAccount() const;
    double getAmount() const;
    void DisplayTransactionInfo() const;
};
#endif
