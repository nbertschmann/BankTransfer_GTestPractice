#pragma once

class BankAccount {
public:
    virtual ~BankAccount() {}
    virtual double getBalance() const = 0;
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};
