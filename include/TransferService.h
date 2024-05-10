#pragma once
#include "BankAccount.h"

class TransferService {
public:
    TransferService(BankAccount& sender, BankAccount& recipient) : sender_(sender), recipient_(recipient) {}
    void transfer(double amount);

private:
    BankAccount& sender_;
    BankAccount& recipient_;
};
