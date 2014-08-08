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
#include <stdlib.h>         // abs
#include <cmath.hpp>

TEST ( get_int_1_2 , returns_1_or_2 )
{

    int random_integer = xstd::random::get_int(1,2);

    ASSERT_TRUE
    (
        random_integer == 1
            ||
        random_integer == 2
    );

}

TEST ( get_int_minus_5_minus_3 , returns_minus_5_or_minus_4_or_minus_3 )
{

    int random_integer = xstd::random::get_int(-5,-3);

    ASSERT_TRUE
    (
        random_integer == -5
            ||
        random_integer == -4
            ||
        random_integer == -3
    );

}

TEST ( get_int_2_1 , throws_std_range_error )
{

    ASSERT_THROW(xstd::random::get_int(2,1),std::range_error);

}

TEST ( coin_flip , returns_true_or_false )
{

    bool coin_flip = xstd::random::coin_flip();

    ASSERT_TRUE
    (
        coin_flip == true
            ||
        coin_flip == false
    );

}

TEST ( coin_flip_10 , returns_true_or_false )
{

    bool coin_flip = xstd::random::coin_flip(10);

    ASSERT_TRUE
    (
        coin_flip == true
            ||
        coin_flip == false
    );

}

TEST ( coin_flip_10 , returns_true_in_10_percents_of_cases )
{

    int wins = 0;
    int wins_expected = 1000;
    int threshold = 100;

    for ( int key = 0 ; key < 10000 ; key++ )
    {

        if ( xstd::random::coin_flip(10) == true )
        {

            wins++;

        }

    }

    ASSERT_TRUE ( abs(wins-wins_expected) < threshold );

}

int main ( int argc , char** argv )
{
    xstd::random::randomize();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}