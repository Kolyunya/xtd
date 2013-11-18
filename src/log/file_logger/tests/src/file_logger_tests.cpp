#include <gtest/gtest.h>
#include <log/file_logger.hpp>



TEST ( file_logger , logs )
{

    std::string log_file = "../tests/data/log";
    std::string log_data = "Hello world!";
    std::fs::truncate_file_contents(log_file);

    const std::abstract_logger& logger = std::file_logger(log_file,false,false);
    logger.log(log_data);

    ASSERT_EQ ( std::fs::get_file_contents(log_file) , log_data );

}

int main ( int argc , char** argv )
{

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}