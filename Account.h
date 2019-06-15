#ifndef ACCOUNT.H
#define ACCOUNT.H
#include <string>

class Account{
    std::string name;
    int id;
    double balance;

public:
    Account(std::string, int, double);
    std::string getName() const;
    int getId() const;
    double getBalance() const;
    void setName(std::string);
    void setID(int);
    void setBalance(double);
    void withdraw(double);
    void deposit(double);
};
#endif // ACCOUNT
