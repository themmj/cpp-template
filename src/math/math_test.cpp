#include "gtest/gtest.h"
#include "math.h"

TEST(AddTest, Numbers) {
    EXPECT_EQ(69, Math::add(34, 35));
}

TEST(AddTest, StringSpecialization){
    EXPECT_EQ(std::string("Hello World"),Math::add<std::string>("Hello", " World")); 
}

TEST(TestMethodTest, WithTrue){
    EXPECT_EQ(1, Math::testMethod(true));
}

TEST(TestMethodTest, WithFalse){
    EXPECT_EQ(0, Math::testMethod(false));
}
