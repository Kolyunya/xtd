#include <gtest/gtest.h>
#include <xtd/io.hpp>

TEST ( scout_operator_out , does_not_throw )
{
    ASSERT_NO_THROW(xtd::io::scout << "Hello world!\n");
}

TEST ( scout_operator_out , does_not_throw_when_passing_std_endl )
{
    ASSERT_NO_THROW(xtd::io::scout << std::endl);
}

TEST ( scout_operator_out , does_not_throw_when_passing_std_endl_std_endl )
{
    ASSERT_NO_THROW(xtd::io::scout << std::endl << std::endl);
}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}