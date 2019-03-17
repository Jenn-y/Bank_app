#ifndef ACCOUNT.H
#define ACCOUNT.H
#include <string>
#include <vector>

class Account{
public:
    Account();
    std::string getName() const;
    int getId() const;
    double getBalance() const;
    void setName(std::string);
    void setID(int);
    void setBalance(double);
    void addAccount (Account);
    void withdraw(double);
    void deposit(double);

    static std::vector<Account> accountDatabase;

private:
    std::string name;
    int id;
    double balance;
};
#endif // ACCOUNT
