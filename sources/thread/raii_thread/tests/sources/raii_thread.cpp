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
#include <thread/raii_thread.hpp>

TEST ( raii_thread_constructor , does_not_throw_0 )
{
    std::function<void()> foo = [](){};
    xstd::raii_thread bar(foo);
}
/*
TEST ( raii_thread_constructor , does_not_throw_1 )
{
    std::raii_thread<void(*)(int),int> foo([](int){},1);
}
*/
int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}