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

TEST ( console_logger , does_not_throw_while_construction )
{
    xstd::console_logger(false,false);
    ASSERT_TRUE(true);
}

TEST ( console_logger , does_not_throw_while_logging_000 )
{
    const xstd::abstract_logger& logger = xstd::console_logger();
    logger.log("Hello world");
    ASSERT_TRUE(true);
}

TEST ( console_logger , does_not_throw_while_logging_001 )
{
    const xstd::abstract_logger& logger = xstd::console_logger(true,false);
    logger.log("Hello world");
    ASSERT_TRUE(true);
}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}