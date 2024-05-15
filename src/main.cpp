#include "BankAccount.h"
#include "TransferService.h"
#include "ConcreteBankAccount.h"
#include<iostream>

int main()
{
    int initial_sender_balance = 1000;
    ConcreteBankAccount sender = ConcreteBankAccount(4600);
    std::cout << "Original sender: $" << sender.getBalance() << std::endl; 

    int initial_recipient_balance = 1000;
    ConcreteBankAccount recipient = ConcreteBankAccount(1000);
    std::cout << "Original recipient: $" << recipient.getBalance() << std::endl; 

    TransferService transferService = TransferService(sender, recipient);

    int transfer_amount = 200;
    std::cout << "Transfer amount: $" << transfer_amount << std::endl;
    transferService.transfer(transfer_amount);

    std::cout << "Sender Balance: $" << sender.getBalance() << std::endl;
    std::cout << "Recipient Balance: $" << recipient.getBalance() << std ::endl;
}