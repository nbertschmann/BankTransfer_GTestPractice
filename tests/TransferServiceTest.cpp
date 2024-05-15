#include "BankAccount.h" 
#include "TransferService.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class MockBankAccount : public BankAccount {
    public:
        MOCK_METHOD(double, getBalance, (), (const, override));
        MOCK_METHOD(void, deposit, double, (override));
        MOCK_METHOD(void, withdraw, double, (override));
}

using ::testing::AtLeast;

TEST(TransferServiceTest, MoneyTransferTest)
{
    MockBankAccount sender;
    MockBankAccount recipient;
   
    double recipientInitialBalance = 1000;
    double senderInitialBalance = 1650;
    double transferAmount = 450;

    EXPECT_CALL(sender, getBalance()).WillOnce(Return(senderInitialBalance))

    EXPECT_CALL(sender, withdraw(transferAmount));
    EXPECT_CALL(recipient, deposit(transferAmount));

    TransferService transferService(sender, recipient);
    transferService.transfer(transferAmount);

    double senderFinalBalance = senderInitialBalance - transferAmount;
    double recipientFinalBalance = recipientFinalBalance + transferAmount;

    EXPECT_EQUAL(senderFinalBalance, sender.getBalance());
    EXPECT_EQUAL(recipientFinalBalance, recipient.getBalance());

}