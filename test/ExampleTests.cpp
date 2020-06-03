#include <gtest/gtest.h>
#include "../Example.hpp"

struct ExampleTests:public ::testing::Test
{
    int x ;
    virtual void SetUp() override{
        x = 42; // Initialize

    }
    virtual void TearDown() override
    {
        //release some memory delete p;
    }

};
TEST_F(ExampleTests, AddTWONUMS)
{
    EXPECT_EQ(5,2+3);
    EXPECT_TRUE(true);
}

TEST_F(ExampleTests, SUM)
{
    EXPECT_EQ(17, sum(8,9));
   
}