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
#include <iostream>
#include <chrono/timer.hpp>

/*
TEST ( timer_default_constuctor , does_not_throw )
{
    ASSERT_NO_THROW(delete(new std::chrono::timer<std::chrono::high_resolution_clock>()));
}
*/

TEST ( timer , does_not_throw_while_starting )
{
    xstd::chrono::timer<std::chrono::high_resolution_clock> timer;
    timer.event_tick.add_listener
    (
        [
        ]
        (
            unsigned int tick_id
        )
        {
            std::cout << "Tick id: " << tick_id << std::endl;
        }
    );
    timer.tick_interval = std::chrono::seconds(1);
    timer.tick_limit = 3;

    timer.start();

    while (  timer.get_is_active() == true )
    {

    }

    ASSERT_TRUE(true);

}


int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}