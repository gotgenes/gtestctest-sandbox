#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Service.h"
#include "MockService.h"
#include "Dependent.h"


TEST(sample_test_case, sample_test)
{
    EXPECT_EQ(1, 1);
}

TEST(sample_test_case, fnx_test)
{
    Service s = Service();
    EXPECT_EQ(s.returnOne(), 1);
    EXPECT_EQ(s.returnGiven(2), 2);
}

using ::testing::Return;
TEST(sample_test_case_1, mock_test)
{
    MockService mock;

    EXPECT_CALL(mock, returnOne())
        .Times(1)
        .WillOnce(Return(2));
    
    Dependent d;
    EXPECT_EQ(d.useService(mock), 32);
}
