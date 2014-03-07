//  xstd - extension of the C++ standard library
//  Copyright (C) 2013 Oleynikov Nikolay
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//  Author email: OleynikovNY@mail.ru

#include <gtest/gtest.h>
#include <log/console_logger.hpp>
#include <log/logger_client.hpp>

TEST ( logger_client , does_not_throw_while_construction )
{

    xstd::logger_client();
    ASSERT_TRUE(true);

}

TEST ( logger_client , does_not_throw_while_logging_0 )
{

    xstd::logger_client logger_client_obj;
    logger_client_obj.log("Hello world!");
    ASSERT_TRUE(true);

}

TEST ( logger_client , does_not_throw_while_logging_1 )
{

    xstd::console_logger logger;
    xstd::logger_client logger_client(&logger);
    logger_client.get_logger_ref().add_new_line = false;
    logger_client.get_logger_ref().add_time_stamp = false;
    logger_client.log("");
    ASSERT_TRUE(true);

}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}