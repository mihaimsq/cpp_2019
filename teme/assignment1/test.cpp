#include "assignment.h"
#include "gtest/gtest.h"


double balance = 5000;

TEST(TestWithdraw, TestNegativeBalance) {
	double negative_balance = -5;
	withdraw(&negative_balance, 2000);
	EXPECT_TRUE(negative_balance == -5.5);
}

TEST(TestWithdraw, TestNegativeAmount) {
	double balance = 10;
	withdraw(&balance, -10);
	EXPECT_EQ(balance, 20);
}

TEST(TestWithdraw, TestBalanceTooLow) {
	double balance = 1000;
	withdraw(&balance, 1100);
	EXPECT_EQ(balance, 1000);
}

TEST(TestWithdraw, TestZeroAmount) {
	double balance = 5000;
	withdraw(&balance, 0);
	EXPECT_EQ(balance, 4750);
}

TEST(TestWithdraw, RightTest) {
	double balance = 2000;
	withdraw(&balance, 1000);
	EXPECT_EQ(balance, 1000);
}