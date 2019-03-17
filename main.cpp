#include <iostream>
#include "Account.h"
#include <string>

void printMenu(){
    std::cout << "\n" << R"(
                                   Please select one of the following options:

                                     1. Create an account
                                     2. Check balance
                                     3. Withdraw
                                     4. Deposit
                                     5. Account summary
                                     6. Make a transaction
                                     7. Exit
                    )" << "\n\t\t\t\t--> ";
}
// find account in account database and return index of that account
int findAccount (){
    std::cout << "\n\t\t\t\t--> Enter account ID: ";
    int id;
    std::cin >> id;
    for (int i = 0; i < Account().accountDatabase.size(); i++)
        if (id == Account().accountDatabase[i].getId()) return i;

    return -1;
}
void MenuSelection(){

    int option = 1, account;
    while (option != 7){
        switch (option){
            // create account
            case 1:{
                    Account newAccount;
                    std::cout << "\n\t\t\t\t--> Please enter your name: ";
                    std::string name;
                    std::cin >> name;
                    newAccount.setName(name);
                    std::cout << "\n\t\t\t\t--> Please enter your ID: ";
                    int id;
                    std::cin >> id;
                    newAccount.setID(id);
                    std::cout << "\n\t\t\t\t--> Please enter your balance: ";
                    double balance;
                    std::cin >> balance;
                    newAccount.setBalance(balance);
                    // add account to the database
                    newAccount.addAccount(newAccount);
                    std::cout << "\n\t\t\t\t~ Your account has been successfully created ~\n";
                    } break;
            // check balance
            case 2:{
                    account = findAccount();
                    if (account == -1) std::cout << "\n\t\t\t\t~ ID does not match any in the database ~\n";
                    else std::cout << "\n\t\t\t\t--> Your balance: " << Account().accountDatabase[account].getBalance();
                    } break;
            // withdraw money
            case 3:{
                    std::cout << "\n\t\t\t\t--> Enter amount to withdraw: ";
                    double withdrawalAmount;
                    std::cin >> withdrawalAmount;
                    account = findAccount();
                         if (account == -1) std::cout << "\n\t\t\t\t~ ID does not match any in the database ~\n";
                         else {
                            if (withdrawalAmount > 0 && Account().accountDatabase[account].getBalance() >= withdrawalAmount){
                                Account().accountDatabase[account].withdraw(withdrawalAmount);
                                std::cout << "\n\t\t\t\t~ Amount successfully withdrawn ~\n";
                            }
                            else std::cout << "\n\t\t\t\t~ Withdrawal not successful ~\n";
                         }
                    } break;
            // deposit money
            case 4:{
                    std::cout << "\n\t\t\t\t--> Enter amount to deposit: ";
                    double depositAmount;
                    std::cin >> depositAmount;
                    account = findAccount();
                    if (account == -1) std::cout << "\n\t\t\t\t~ ID does not match any in the database ~\n";
                    else {
                        if (depositAmount > 0){
                            Account().accountDatabase[account].deposit(depositAmount);
                            std::cout << "\n\t\t\t\t-->~ Amount successfully deposited ~\n";
                        }
                        else std::cout << "\n\t\t\t\t-->~ Deposit not successful ~\n";
                    }
                    } break;
            // print account summary
            case 5:{
                    account = findAccount();
                    if (account == -1) std::cout << "\n\t\t\t\t~ ID does not match any in the database ~\n";
                    else std::cout << "\n\n\t\t\t\t~ ACCOUNT SUMMARY ~\n"
                                   << "\n\t\t\t\t--> Name: " << Account().accountDatabase[account].getName()
                                   << "\n\t\t\t\t--> ID: " << Account().accountDatabase[account].getId()
                                   << "\n\t\t\t\t--> Balance: " << Account().accountDatabase[account].getBalance() << "\n";

                    } break;
            // make a transaction
            case 6:{
                    std::cout << "\n\t\t\t\t--> Do you wish to withdraw or deposit? (w/d): ";
                    char choice;
                    std::cin >> choice;
                    std::cout << "\n\t\t\t\t--> Enter transaction amount: ";
                    double amount;
                    std::cin >> amount;
                    std::cout << "\n\t\t~ You will be asked to enter your account's ID first, then the transaction account's ID ~\n";
                    account = findAccount();
                    if (account == -1) std::cout << "\n\t\t\t\t~ ID does not match any in the database ~\n";
                    else {
                         int secondAccount = findAccount();
                         if (secondAccount == -1) std::cout << "\n\t\t\t\t~ ID does not match any in the database ~\n";
                         else {
                              bool transactionPerformed = false;
                              if (tolower(choice) == 'w' && Account().accountDatabase[secondAccount].getBalance() >= amount){
                                  Account().accountDatabase[secondAccount].withdraw(amount);
                                  Account().accountDatabase[account].deposit(amount);
                                  transactionPerformed = true;
                              }
                              else if (tolower(choice) == 'd' && Account().accountDatabase[account].getBalance() >= amount){
                                  Account().accountDatabase[secondAccount].deposit(amount);
                                  Account().accountDatabase[account].withdraw(amount);
                                  transactionPerformed = true;
                              }
                              if (!transactionPerformed) std::cout << "\n\t\t\t\t~ Transaction not successful ~\n";
                              else std::cout << "\n\t\t\t\t~ Transaction successfully completed ~\n";
                            }
                     }
                    }
        }
        printMenu();
        std::cin >> option;
        while (option < 1 || option > 7){
        std::cout << "\n\t\t\t\t--> Please enter a valid option (1-7): ";
        std::cin >> option;
        }
    }

    if (option == 7) std::cout << R"(
########################################################################################################################
                                  ~ THANK   YOU   FOR   USING   OUR   SERVICES ~

########################################################################################################################
                    )";
}

int main(){
    std::cout << R"(
########################################################################################################################
                                   ~ W E L C O M E   T O   O U R   B A N K ~

########################################################################################################################


                    )";
    MenuSelection();
    return 0;
}
