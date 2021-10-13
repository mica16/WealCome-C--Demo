#include "gmock/gmock.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(PalindromeCheckerSuite, DummyTestForExample) {
    EXPECT_THAT(1, testing::Eq(1));
}