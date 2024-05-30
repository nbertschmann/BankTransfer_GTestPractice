#include "TransferService.h"
#include <iostream>
#include <stdexcept>

TransferService::TransferService(BankAccount& sender, BankAccount& recipient) : sender_(sender), recipient_(recipient) {}

void TransferService::transfer(double amount) {
    
    
    if(amount < 0){
        throw std::runtime_error("Transfer amount is below 0");
    }
    
    else if(sender_.getBalance() - amount < 0){
        throw std::runtime_error("Insufficient balance in sender account");
    }

    else{
        sender_.withdraw(amount);
        recipient_.deposit(amount);
    }
}