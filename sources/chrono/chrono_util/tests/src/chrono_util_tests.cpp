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
#include <cstring>                      // memcmp
#include <chrono/chrono_util.hpp>

TEST ( one_second_time_point , converts_to_time_t_equal_to_1 )
{

    std::chrono::time_point<std::chrono::steady_clock> time_point(std::chrono::seconds(1));
    time_t time_point_in_time_t_format = xstd::chrono::time_point_to_time_t(time_point);

    ASSERT_EQ(time_point_in_time_t_format,1);

}

TEST ( one_second_time_point , converts_to_string_1970_01_01_00_00_01 )
{

    std::chrono::time_point<std::chrono::steady_clock> time_point(std::chrono::seconds(1));
    std::string time_point_string = xstd::chrono::time_point_to_formatted_string(time_point);

    ASSERT_EQ(time_point_string,"[1970/01/01-00:00:01]");

}

TEST ( one_minute_time_point , converts_to_time_t_equal_to_60 )
{

    std::chrono::time_point<std::chrono::steady_clock> time_point(std::chrono::minutes(1));
    time_t time_point_in_time_t_format = xstd::chrono::time_point_to_time_t(time_point);

    ASSERT_EQ(time_point_in_time_t_format,60);

}

TEST ( one_minute_time_point , converts_to_equal_tm )
{

    std::chrono::time_point<std::chrono::steady_clock> time_point(std::chrono::minutes(1));
    tm time_point_in_tm_format_actual = xstd::chrono::time_point_to_tm(time_point);

    time_t time_point_in_time_t_format = 60;
    tm time_point_in_tm_format_correct = *gmtime(&time_point_in_time_t_format);

    ASSERT_EQ(memcmp(&time_point_in_tm_format_actual,&time_point_in_tm_format_correct,sizeof(tm)),0);

}

TEST ( one_hour_time_point , converts_to_time_t_equal_to_3600 )
{

    std::chrono::time_point<std::chrono::steady_clock> time_point(std::chrono::hours(1));
    time_t time_point_in_time_t_format = xstd::chrono::time_point_to_time_t(time_point);

    ASSERT_EQ(time_point_in_time_t_format,3600);

}

TEST ( one_hour_time_point , converts_to_sting_with_custom_format )
{

    std::chrono::time_point<std::chrono::steady_clock> time_point(std::chrono::seconds(42));
    std::string time_point_string = xstd::chrono::time_point_to_formatted_string(time_point,"%Y-%m-%d %H-%M-%S");

    ASSERT_EQ(time_point_string,"1970-01-01 00-00-42");

}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}