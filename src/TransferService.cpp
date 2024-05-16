#include "TransferService.h"
#include <iostream>

TransferService::TransferService(BankAccount& sender, BankAccount& recipient) : sender_(sender), recipient_(recipient) {}

void TransferService::transfer(double amount) {
    
    if(sender_.getBalance()-amount >= 0){
        sender_.withdraw(amount);
        recipient_.deposit(amount);
    }

    else{
        std::cout << "Insufficient balance in sender account";
    }
}