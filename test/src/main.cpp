#include "gtest/gtest.h"

#include "log.hpp"

TEST(HelloTest, BasicFunctionality) {
    ASSERT_FALSE(false);
    EXPECT_STRNE("hello", "world");
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    LOG_DEBUG("Running Tests");
    return RUN_ALL_TESTS();
}
