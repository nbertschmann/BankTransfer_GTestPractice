#include "BankAccount.h"

class TransferService {
public:
    TransferService(BankAccount& sender, BankAccount& recipient);
    void transfer(double amount);

private:
    BankAccount& sender_;
    BankAccount& recipient_;
};
