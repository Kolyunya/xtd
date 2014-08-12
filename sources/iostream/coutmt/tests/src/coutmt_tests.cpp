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
#include <iostream.hpp>

TEST ( coutmt_operator_out , does_not_throw )
{
    ASSERT_NO_THROW(xstd::coutmt << "Hello world!\n");
}

TEST ( coutmt_operator_out , does_not_throw_when_passing_std_endl )
{
    ASSERT_NO_THROW(xstd::coutmt << std::endl);
}

TEST ( coutmt_operator_out , does_not_throw_when_passing_std_endl_std_endl )
{
    ASSERT_NO_THROW(xstd::coutmt << std::endl << std::endl);
}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}