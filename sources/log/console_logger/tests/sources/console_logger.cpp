#include <gtest/gtest.h>
#include <xtd/log/console_logger.hpp>

TEST ( console_logger , does_not_throw_while_construction )
{
    xtd::log::console_logger(false,false);
    ASSERT_TRUE(true);
}

TEST ( console_logger , does_not_throw_while_logging_000 )
{
    const xtd::log::abstract_logger& logger = xtd::log::console_logger();
    logger.log("Hello world");
    ASSERT_TRUE(true);
}

TEST ( console_logger , does_not_throw_while_logging_001 )
{
    const xtd::log::abstract_logger& logger = xtd::log::console_logger(true,false);
    logger.log("Hello world");
    ASSERT_TRUE(true);
}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}