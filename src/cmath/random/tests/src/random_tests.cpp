#include <gtest/gtest.h>
#include <std/cmath>
#include <stdlib.h>			//	abs

TEST ( get_int_1_2 , returns_1_or_2 )
{

	int random_integer = std::random::get_int(1,2);

	ASSERT_TRUE
	(
		random_integer == 1
			||
		random_integer == 2
	);

}

TEST ( get_int_minus_5_minus_3 , returns_minus_5_or_minus_4_or_minus_3 )
{

	int random_integer = std::random::get_int(-5,-3);

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

	ASSERT_THROW(std::random::get_int(2,1),std::range_error);

}

TEST ( coin_flip , returns_true_or_false )
{

	bool coin_flip = std::random::coin_flip();

	ASSERT_TRUE
	(
		coin_flip == true
			||
		coin_flip == false
	);

}

TEST ( coin_flip_10 , returns_true_or_false )
{

	bool coin_flip = std::random::coin_flip(10);

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
	int threshold = 10;
	
	for ( int key = 0 ; key < 10000 ; key++ )
	{
	
		if ( std::random::coin_flip(10) )
		{
		
			wins++;
		
		}
	
	}
	
	ASSERT_TRUE ( abs(wins-wins_expected) < threshold );

}

int main ( int argc , char** argv )
{

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}