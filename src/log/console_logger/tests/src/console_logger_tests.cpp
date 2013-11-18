#include <gtest/gtest.h>
#include <log/console_logger.hpp>



TEST ( console_logger , does_not_throw_while_construction )
{

    std::console_logger(false,false);
    ASSERT_TRUE(true);

}

TEST ( console_logger , does_not_throw_while_logging )
{

    const std::abstract_logger& logger = std::console_logger(false,false);
    logger.log("");
    ASSERT_TRUE(true);

}

int main ( int argc , char** argv )
{

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}