// ConcreteBankAccount.h
#pragma once
#include "BankAccount.h"

class ConcreteBankAccount : public BankAccount {
private:
    double balance_;

public:
    ConcreteBankAccount(double initialBalance) : balance_(initialBalance) {}

    double getBalance() const override {
        return balance_;
    }

    void deposit(double amount) override {
        balance_ += amount;
    }

    void withdraw(double amount) override {
        balance_ -= amount;
    }
};
