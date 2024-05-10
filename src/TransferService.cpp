#include "TransferService.h"

void TransferService::transfer(double amount) {
    sender_.withdraw(amount);
    recipient_.deposit(amount);
}