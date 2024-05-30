#include "BankAccount.h" 
#include "TransferService.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace ::testing;

class MockBankAccount : public BankAccount {
    public:
        
        MOCK_METHOD(double, getBalance, (), (const, override));
        MOCK_METHOD(void, deposit, (double), (override));
        MOCK_METHOD(void, withdraw, (double), (override));
};

TEST(TransferServiceTest, MoneyTransferTest) {
    // Create mock bank accounts
    MockBankAccount sender;
    MockBankAccount recipient;

    // Set expectations on mock objects
    double senderInitialBalance = 1000.0;
    double recipientInitialBalance = 500.0;
    double transferAmount = 100.0;

    EXPECT_CALL(sender, getBalance()).WillOnce(Return(senderInitialBalance));

    EXPECT_CALL(sender, withdraw(transferAmount)).Times(1);
    EXPECT_CALL(recipient, deposit(transferAmount)).Times(1);

    // Create TransferService instance with mock accounts
    TransferService transferService(sender, recipient);

    // Perform money transfer
    transferService.transfer(transferAmount);

    // Verify balances after transfer
    double expectedSenderBalance = senderInitialBalance - transferAmount;
    double expectedRecipientBalance = recipientInitialBalance + transferAmount;

    EXPECT_CALL(sender, getBalance()).WillOnce(Return(expectedSenderBalance));
    EXPECT_CALL(recipient, getBalance()).WillOnce(Return(expectedRecipientBalance));

    EXPECT_EQ(expectedSenderBalance, sender.getBalance());
    EXPECT_EQ(expectedRecipientBalance, recipient.getBalance());
}

TEST(TransferServiceTest, InsufficientFundsTest){
    
    MockBankAccount sender;
    MockBankAccount recipient;

    // Set expectations on mock objects
    double senderInitialBalance = 50.0;
    double recipientInitialBalance = 500.0;
    double transferAmount = 100.0;

    EXPECT_CALL(sender, getBalance()).WillOnce(Return(senderInitialBalance));
    
    // Do not expect withraw or deposit to be called
    EXPECT_CALL(sender, withdraw(_)).Times(0);
    EXPECT_CALL(recipient, deposit(_)).Times(0);

    TransferService transferService(sender, recipient);
    
    // Expect std::runtime error to be thrown due to insufficient funds
    EXPECT_THROW(transferService.transfer(transferAmount), std::runtime_error);

}

TEST(TransferServiceTest, NegativeTransferAmountTest)
{
    double senderInitialBalance = 1000;
    double recipientInitialBalance = 1000;
    double negativeTransferAmount = -200.5;
    
    MockBankAccount sender;
    MockBankAccount recipient;

    TransferService transferService(sender, recipient);

    // Ensure that no interactions occur with the BankAccount objects
    EXPECT_CALL(sender, getBalance()).Times(0);
    EXPECT_CALL(sender, withdraw(_)).Times(0);
    EXPECT_CALL(recipient, deposit(_)).Times(0);

    // Expect std::runtime_error to be thrown for a negative transfer amount
    EXPECT_THROW(transferService.transfer(negativeTransferAmount), std::runtime_error);

}
