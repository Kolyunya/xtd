#include <gtest/gtest.h>
#include <xtd/event.hpp>

TEST ( event , does_not_throw_while_construction_001 )
{
    ASSERT_NO_THROW(delete(new xtd::event::event<>()));
}

TEST ( event , does_not_throw_while_construction_002 )
{
    ASSERT_NO_THROW(delete(new xtd::event::event<int>()));
}

TEST ( event , does_not_throw_while_construction_003 )
{
    ASSERT_NO_THROW(delete(new xtd::event::event<int,bool,float>()));
}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}