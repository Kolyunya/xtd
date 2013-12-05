#include <gtest/gtest.h>
#include <iostream.hpp>

TEST ( coutmt_singleton_get_instance , does_not_throw )
{
    ASSERT_NO_THROW(std::coutmt_singleton::get_instance());
}

TEST ( coutmt_operator_out , does_not_throw )
{
    ASSERT_NO_THROW(std::coutmt << "Hello world!\n";);
}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}