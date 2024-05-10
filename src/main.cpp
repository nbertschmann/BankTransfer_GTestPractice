#include "BankAccount.h"
#include "TransferService.h"
#include "ConcreteBankAccount.h"
#include<iostream>

int main()
{
    int initial_sender_balance = 1000;
    ConcreteBankAccount sender = ConcreteBankAccount(1000);

    int initial_recipient_balance = 1000;
    ConcreteBankAccount recipient = ConcreteBankAccount(1000);

    TransferService transferService = TransferService(sender, recipient);

    transferService.transfer(200);

    std::cout << sender.getBalance() << std::endl;
    std::cout << recipient.getBalance() << std ::endl;
}