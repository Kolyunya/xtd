#include <gtest/gtest.h>
#include <xtd/log.hpp>

TEST ( file_logger , logs )
{

    std::string log_file = "../tests/data/log";
    std::string log_data = "Hello world!";
    xtd::file::truncate_contents(log_file);

    const xtd::log::abstract_logger& logger = xtd::log::file_logger(log_file,false,false);
    logger.log(log_data);

    ASSERT_EQ ( xtd::file::get_contents(log_file) , log_data );

}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}