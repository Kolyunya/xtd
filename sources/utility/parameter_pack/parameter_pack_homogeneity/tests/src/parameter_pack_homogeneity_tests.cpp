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
#include <utility/parameter_pack.hpp>

TEST ( pack , is_homogeneous_000 )
{
    bool pack_is_homogeneous = xstd::pp::is_homogeneous<>::value;
    ASSERT_TRUE(pack_is_homogeneous);
}

TEST ( pack , is_homogeneous_001 )
{
    bool pack_is_homogeneous = xstd::pp::is_homogeneous<int>::value;
    ASSERT_TRUE(pack_is_homogeneous);
}

TEST ( pack , is_heterogeneous_000 )
{
    bool pack_is_heterogeneous = xstd::pp::is_heterogeneous<int,float>::value;
    ASSERT_TRUE(pack_is_heterogeneous);
}

TEST ( pack_type , is_retrieved_correctly_000 )
{
    using pack_type_expected = xstd::pp::null_type;
    using pack_type_actual = xstd::pp::is_homogeneous<>::type;
    bool pack_type_retrieved_correctly = std::is_same<pack_type_expected,pack_type_actual>::value;
    ASSERT_TRUE(pack_type_retrieved_correctly);
}

TEST ( pack_type , is_retrieved_correctly_001 )
{
    using pack_type_expected = xstd::pp::null_type;
    using pack_type_actual = xstd::pp::is_homogeneous<int,bool>::type;
    bool pack_type_retrieved_correctly = std::is_same<pack_type_expected,pack_type_actual>::value;
    ASSERT_TRUE(pack_type_retrieved_correctly);
}

TEST ( pack_type , is_retrieved_correctly_002 )
{
    using pack_type_expected = int;
    using pack_type_actual = xstd::pp::is_homogeneous<int>::type;
    bool pack_type_retrieved_correctly = std::is_same<pack_type_expected,pack_type_actual>::value;
    ASSERT_TRUE(pack_type_retrieved_correctly);
}

TEST ( pack_type , is_retrieved_correctly_003 )
{
    using pack_type_expected = int;
    using pack_type_actual = xstd::pp::is_homogeneous<int,int,int>::type;
    bool pack_type_retrieved_correctly = std::is_same<pack_type_expected,pack_type_actual>::value;
    ASSERT_TRUE(pack_type_retrieved_correctly);
}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
