#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Example.hpp"
using ::testing::_;
using ::testing::AtLeast;
using ::testing::Invoke;
using ::testing::InvokeWithoutArgs; // to call global functions
using ::testing::Return;

class MockDatabase : public DatabaseConnect
{
public:
    MOCK_METHOD0(fetchRecord, size_t());                                   // mockmethod0 => 0 means doesnt take any argument
    MOCK_METHOD1(logout, bool(std::string username));                      // 1=> means takes one parameter
    MOCK_METHOD2(login, bool(std::string username, std::string password)); // 2=> means 2 parameters
};

struct ExampleTests : public ::testing::Test
{
    int x;
    virtual void SetUp() override
    {
        x = 42; // Initialize
    }
    virtual void TearDown() override
    {
        //release some memory delete p;
    }
};
//use mock with two functions Expect_call and on_call
TEST_F(ExampleTests, checklogin)
{
    MockDatabase mockdb;
    Mydatabase db(mockdb);
    EXPECT_CALL(mockdb, login("test", "test"))
        .Times(1)
        .WillOnce(Return(true));
    bool res = db.testlogin("test", "test");
    EXPECT_EQ(res, true);
}

TEST_F(ExampleTests, checkloginthird)
{
    MockDatabase mockdb;
    Mydatabase db(mockdb);
    EXPECT_CALL(mockdb, login(_, _)) // _ means any argument so it doesnt matter what you pass
        .Times(1)
        .WillOnce(Return(true));
    bool res = db.testlogin("test", "test");
    EXPECT_EQ(res, true);
}
/*The differnece between ON_CALL and EXPECT_CALL is that in Expect_call, 
it expect to be call executed if it doesnt then it returns false
while on_call says that this call need not to be executed but if it happens
it executes true. So in expect call you have to call that function  */
TEST_F(ExampleTests, checkloginsec)
{
    MockDatabase mockdb;
    Mydatabase db(mockdb);
    ON_CALL(mockdb, login("test", "test"))
        .WillByDefault(Return(true));
    bool res = db.testlogin("test", "test");
    EXPECT_EQ(res, true);
}
// use of invoke for calling actual method instead of mock
TEST_F(ExampleTests, checkloginfourth)
{
    MockDatabase mockdb;
    Mydatabase db(mockdb);
    DatabaseConnect odb;
    EXPECT_CALL(mockdb, login(_, _)) // _ means any argument so it doesnt matter what you pass
        .Times(1)
        .WillOnce(Invoke(&odb, &DatabaseConnect::login));
    bool res = db.testlogin("test", "test");
    EXPECT_EQ(res, true);
}
TEST_F(ExampleTests, AddTWONUMS)
{
    EXPECT_EQ(5, 2 + 3);
    EXPECT_TRUE(true);
}

TEST_F(ExampleTests, SUM)
{
    EXPECT_EQ(17, sum(8, 9));
}