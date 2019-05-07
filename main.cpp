#include "Account.h"
#include "Transaction.h"
#include <iostream>
#include <string>
#include <stdexcept>

std::vector<Account> accountDatabase;
std::vector<Transaction> transactionDatabase;

std::string format(std::string sentence){
    return "\n\t\t\t\t\t" + sentence;
}

void printMenu(){
    std::cout << "\n" << R"(
                                   Please select one of the following options:

                                     1. Create an account
                                     2. Check balance
                                     3. Withdraw
                                     4. Deposit
                                     5. Account summary
                                     6. Make a transaction
                                     7. Print transactions
                                     8. Exit
                    )" << format("--> ");
}

// get a valid input
template<typename Type>
void getInput(Type &value){
    while (true){
        std::cin >> value;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << format("~ Invalid input ~") << format("--> Enter again: ");
        }
        else {
            std::cin.ignore();
            return;
        }
    }
}

// find account in account database and return index of that account
int findAccount (int id){
    for (int i = 0; i < accountDatabase.size(); i++)
        if (id == accountDatabase[i].getId()) return i;

    return -1;
}

int getAccountIndex(){
    int id;
    std::cout << format("--> Please enter your ID: ");
    getInput(id);
    return findAccount(id);
}

void createAccount (){
    Account newAccount;
    std::cout << format("--> Please enter your name: ");
    std::string name;
    std::cin.ignore();
    std::getline(std::cin, name);
    newAccount.setName(name);
    std::cout << format("--> Please enter your ID: ");
    int id;
    getInput(id);
    if (findAccount(id) != -1) throw std::domain_error("~ Entered ID is already in use ~");
    newAccount.setID(id);
    std::cout << format("--> Please enter your balance: ");
    double balance;
    getInput(balance);
    newAccount.setBalance(balance);
    // add account to the database
    accountDatabase.push_back(newAccount);
    std::cout <<  format("~ Your account has been successfully created ~") << "\n";
}

void performTransaction(){
    int id, account;
    std::cout << format("--> Enter transaction amount: ");
    double amount;
    getInput(amount);
    std::cout << format("--> Please enter your ID: ");
    getInput(id);
    account = findAccount(id);
    if (account == -1) std::cout << format("~ ID does not match any in the database ~") << "\n";
    else {
        std::cout << format("--> Please enter ID of the transaction account: ");
        getInput(id);
        int secondAccount = findAccount(id);
        if (secondAccount == -1) std::cout << format("~ ID does not match any in the database ~") << "\n";
        else {
            Transaction t(&accountDatabase[account], &accountDatabase[secondAccount], amount);
            transactionDatabase.push_back(t);
            std::cout << format("~ Transaction successfully completed ~") << "\n";
        }
}
}
void MenuSelection(){

    int option = 1, account, id;
    while (option != 8){

      try{
        switch (option){
            case 1: createAccount();break;

            // check balance
            case 2:{
                    account = getAccountIndex();
                    if (account == -1) std::cout << format("~ ID does not match any in the database ~") << "\n";
                    else std::cout << format("\n\t\t\t\t--> Your balance: ") << accountDatabase[account].getBalance();
                    } break;

            // withdraw money
            case 3:{
                    std::cout << format("--> Enter amount to withdraw: ");
                    double withdrawalAmount;
                    getInput(withdrawalAmount);
                    account = getAccountIndex();
                         if (account == -1) std::cout << format("~ ID does not match any in the database ~") << "\n";
                         else {
                            if (accountDatabase[account].getBalance() >= withdrawalAmount){
                                accountDatabase[account].withdraw(withdrawalAmount);
                                std::cout << format("~ Amount successfully withdrawn ~") << "\n";
                            }
                            else std::cout << format("~ Withdrawal not successful - check the state of balance ~") << "\n";
                         }
                    } break;

            // deposit money
            case 4:{
                    std::cout << format("--> Enter amount to deposit: ");
                    double depositAmount;
                    getInput(depositAmount);
                    account = getAccountIndex();
                    if (account == -1) std::cout << format("~ ID does not match any in the database ~") << "\n";
                    else {
                            accountDatabase[account].deposit(depositAmount);
                            std::cout << format("~ Amount successfully deposited ~") << "\n";
                    }
                    } break;

            // print account summary
            case 5:{
                    account = getAccountIndex();
                    if (account == -1) std::cout << format("~ ID does not match any in the database ~") << "\n";
                    else std::cout << "\n" << format("~ ACCOUNT SUMMARY ~") << "\n"
                                   << format("--> Name: ") << accountDatabase[account].getName()
                                   << format("--> ID: ") << accountDatabase[account].getId()
                                   << format("--> Balance: ") << accountDatabase[account].getBalance() << "\n";

                    } break;

            // make a transaction
            case 6: performTransaction(); break;

            // print transactions
            case 7: {
                    std::cout << format("--> Please enter your ID: ");
                    getInput(id);
                    account = findAccount(id);
                    if (account == -1) std::cout << format("~ ID does not match any in the database ~") << "\n";
                    else {
                        for (int i = 0; i < transactionDatabase.size(); i++)
                            if (transactionDatabase[i].getSourceAccount().getId() == accountDatabase[account].getId())
                                transactionDatabase[i].DisplayTransactionInfo();
                        }
                    }break;
            }
         }
         catch (std::domain_error e){
                std::cerr << format(e.what());
         }
         printMenu();
         getInput(option);
         while (option < 1 || option > 8){
            std::cout << format("--> Please enter a valid option (1-8): ");
            getInput(option);
         }
    }

    std::cout << R"(
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
