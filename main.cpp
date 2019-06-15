#include "Bank.h"
#include <iostream>
#include <string>
#include <stdexcept>

void printMenu(){
    std::cout << "\n" << R"(
                                   Please select one of the following options:

                                     1. Create Account
                                     2. Account Summary
                                     3. Check Balance
                                     4. Withdraw
                                     5. Deposit
                                     6. Make Transaction
                                     7. Print Transactions
                                     8. Exit
                           --> )";
}

void MenuSelection(Bank &b){

    int option = 1;
    while (option != 8){

      try{
        switch (option){
            case 1: b.createAccount(); break;
            case 2: b.printAccountSummary(); break;
            case 3: b.checkBalance(); break;
            case 4: b.withdraw(); break;
            case 5: b.deposit(); break;
            case 6: b.performTransaction(); break;
            case 7: b.printTransactions(); break;
            }
         }
         catch (std::domain_error e){
                std::cerr << "n\t\t\t\t\t " << e.what();
         }
         printMenu();
         b.getInput(option);
         while (option < 1 || option > 8){
            std::cout << "\n\t\t\t\t\t~--> Please enter an option (1-8): ";
            b.getInput(option);
         }
    }

    b.exit();
}

int main(){
    Bank b;
    MenuSelection(b);
    return 0;
}
