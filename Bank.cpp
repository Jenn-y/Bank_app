#include "Bank.h"
#include "Account.h"
#include "Transaction.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

Bank::Bank(){
    std::cout << R"(
########################################################################################################################
                                   ~ W E L C O M E   T O   O U R   B A N K ~

########################################################################################################################


                    )";
}

std::map<int, Account> Bank::accountDatabase;
std::map<int, std::vector<Transaction>> Bank::transactionDatabase;

std::string Bank::format(std::string sentence){
    return "\n\t\t\t\t\t" + sentence;
}

int Bank::userIDInput(){
    int id;
    std::cout << format("--> Please enter your ID: ");
    getInput(id);
    return id;
}

bool Bank::findAccount (int id){
    auto it = accountDatabase.find(id);
    if (it == accountDatabase.end()) return false;

    return true;
}

void Bank::createAccount(){
    std::cout << format("--> Please enter your name: ");
    std::string name;
    std::getline(std::cin >> std::ws, name);
    int id = userIDInput();
    while (findAccount(id)){
        std::cout << format("~ Entered ID is already in use ~");
        id = userIDInput();
    }
    std::cout << format("--> Please enter your balance: ");
    double balance;
    getInput(balance);
    Account newAccount(name, id, balance);
    // add account to the database
    accountDatabase.insert({id, newAccount});
    std::cout << format("~ Your account has been successfully created ~") << "\n";
}

void Bank::printAccountSummary(){
    int id = userIDInput();
    if (!findAccount(id)) std::cout << format("~ ID does not match any in the database ~") << "\n";
    else std::cout << "\n" << format("~ ACCOUNT SUMMARY ~") << "\n"
                   << format("--> Name: ") << accountDatabase.at(id).getName()
                   << format("--> Balance: ") << accountDatabase.at(id).getBalance() << "\n";

}

void Bank::checkBalance(){
    int id = userIDInput();
    if (!findAccount(id)) std::cout << format("~ ID does not match any in the database ~") << "\n";
    else std::cout << format("\n\t\t\t\t--> Your balance: ") << accountDatabase.at(id).getBalance();
}

void Bank::withdraw(){
    int id = userIDInput();
    if (!findAccount(id)) std::cout << format("~ ID does not match any in the database ~") << "\n";
    else {
        std::cout << format("--> Enter amount to withdraw: ");
        double withdrawalAmount;
        getInput(withdrawalAmount);
        accountDatabase.at(id).withdraw(withdrawalAmount);
        std::cout << format("~ Amount successfully withdrawn ~") << "\n";
    }
}

void Bank::deposit(){
    int id = userIDInput();
    if (!findAccount(id)) std::cout << format("~ ID does not match any in the database ~") << "\n";
    else {
        std::cout << format("--> Enter amount to deposit: ");
        double depositAmount;
        getInput(depositAmount);
        accountDatabase.at(id).deposit(depositAmount);
        std::cout << format("~ Amount successfully deposited ~") << "\n";
    }
}


void Bank::performTransaction(){
    int srcId = userIDInput();
    if (!findAccount(srcId)) std::cout << format("~ ID does not match any in the database ~") << "\n";
    else {
        int trgId;
        std::cout << format("--> Please enter ID of the transaction account: ");
        getInput(trgId);
        if (!findAccount(trgId)) std::cout << format("~ ID does not match any in the database ~") << "\n";
        else if (srcId == trgId) std::cout << format("~ Transaction cannot be completed between the same account ~");
        else {
            std::cout << format("--> Enter transaction amount: ");
            double amount;
            getInput(amount);
            std::string description;
            std::cout << format("Please enter a brief description of the transaction: ");
            std::getline(std::cin >> std::ws, description);
            Transaction t(&accountDatabase.at(srcId), &accountDatabase.at(trgId), amount, description);
            bool transactionAdded = false;
            // add transaction to transaction database
            // first checks if the account has already made transactions in the past
            // to just add new transaction to the vector
            for(auto it = transactionDatabase.begin(); it != transactionDatabase.end(); it++)
                if (it->first == srcId){
                    it->second.push_back(t);
                    transactionAdded = true; break;
                    }
            if(!transactionAdded) transactionDatabase[srcId].push_back(t);
            std::cout << format("~ Transaction successfully completed ~") << "\n";
        }
    }
}

void Bank::printTransactions(){
    int id = userIDInput();
    if (!findAccount(id)) std::cout << format("~ ID does not match any in the database ~") << "\n";
    else {
        if (transactionDatabase[id].empty()){
            std::cout << format("~ No transactions in the database ~");
            return;
        }
        for(int i = 0; i < transactionDatabase.at(id).size(); i++){
            std::cout << format("| Transaction - ") << i+1 << " -\n";
            transactionDatabase.at(id).at(i).DisplayTransactionInfo();
        }
    }
}

void Bank::exit() const{
    std::cout << R"(
########################################################################################################################
                                  ~ THANK   YOU   FOR   USING   OUR   SERVICES ~

########################################################################################################################
                    )";
}
