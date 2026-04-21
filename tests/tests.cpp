#include <gtest/gtest.h>
#include "CashRegister.hpp"

TEST(CashRegisterTest, CanWithdrawChange) {
    CashRegister cash;

    auto result = cash.withdrawChange(1.5);

    EXPECT_FALSE(result.empty());
}

TEST(CashRegisterTest, FailWhenImpossible) {
    CashRegister cash;

    // symulacja braku monet
    cash.remove(2.0, 10);
    cash.remove(1.0, 5);
    cash.remove(0.5, 2);

    auto result = cash.withdrawChange(1.5);

    EXPECT_TRUE(result.empty());
}