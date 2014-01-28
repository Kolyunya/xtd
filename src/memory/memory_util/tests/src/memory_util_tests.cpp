#include <gtest/gtest.h>
#include <memory/memory_util.hpp>

TEST ( std_validate_pointer , throws_when_being_passed_a_null_pointer )
{
    ASSERT_THROW(std::validate_pointer<int>(nullptr),std::runtime_error);
}

TEST ( std_validate_pointer , does_not_throw_when_being_passed_a_non_null_pointer )
{
    int foo;
    ASSERT_NO_THROW(std::validate_pointer(&foo));
}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
