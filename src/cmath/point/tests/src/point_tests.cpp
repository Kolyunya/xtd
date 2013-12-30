#include <gtest/gtest.h>
#include <cmath/point.hpp>

TEST ( default_constructor , 000 )
{
    ASSERT_THROW((std::point<int,0>()),int);
}

TEST ( default_constructor , 001 )
{
	std::point<float,1> point;
    ASSERT_EQ(point[0],0);
}

TEST ( default_constructor , 002 )
{
	std::point<int,5> point;
    ASSERT_EQ(point[0],0);
    ASSERT_EQ(point[1],0);
    ASSERT_EQ(point[2],0);
    ASSERT_EQ(point[3],0);
    ASSERT_EQ(point[4],0);
}

TEST ( constructor_from_initializer_list , 000 )
{
	std::point_f3 point {1.5,2,5};
    ASSERT_EQ(point[0],(float)1.5);
    ASSERT_EQ(point[1],(float)2);
    ASSERT_EQ(point[2],(float)5);
}

TEST ( constructor_from_initializer_list , 001 )
{
    ASSERT_THROW(std::point_f3({1.5,2,5,6}),int);
}

TEST ( constructor_from_initializer_list , 002 )
{
	std::point_i3 point {1,2,5};
    ASSERT_EQ(point[0],1);
    ASSERT_EQ(point[1],2);
    ASSERT_EQ(point[2],5);
}

TEST ( constructor_from_initializer_list , 003 )
{
	std::point_f3 point {1,2,5};
    ASSERT_EQ(point[0],1);
    ASSERT_EQ(point[1],2);
    ASSERT_EQ(point[2],5);
}

TEST ( constructor_from_coordinates , 000 )
{
	std::point<int,3> point {4,5,6};
    ASSERT_EQ(point[0],4);
    ASSERT_EQ(point[1],5);
    ASSERT_EQ(point[2],6);
}

TEST ( constructor_from_coordinates , 001 )
{
	std::point<float,3> point {4.1,5.43,6.56};
    ASSERT_EQ(point[0],4.1f);
    ASSERT_EQ(point[1],5.43f);
    ASSERT_EQ(point[2],6.56f);
}

TEST ( constructor_from_coordinates , 002 )
{
    ASSERT_THROW((std::point<float,5>({4.1,5.43,6.56})),int);
}

TEST ( constructor_from_coordinates , 003 )
{
    ASSERT_THROW((std::point<float,5>({4.1,5.43,6.56,65,6,6,6,6,66})),int);
}

TEST ( constructor_from_point , 000 )
{
	std::point<int,3> pointA {4,5,6};
	std::point<int,3> pointB = pointA;
    ASSERT_EQ(pointB[0],4);
    ASSERT_EQ(pointB[1],5);
    ASSERT_EQ(pointB[2],6);
}


/*

bool test_constructorFromPoint_001 ( void )
{

	std::point<float,3> pointA {4.1,5.43,6.56};
	std::point<float,3> pointB(pointA);

	return
	(
		pointB[0] == 4.1f
			&&
		pointB[1] == 5.43f
			&&
		pointB[2] == 6.56f
	);

}

bool test_constructorFromDifferentPoint_000 ( void )
{

	std::point<float,3> pointA {4.1,5.43,6.56};
	std::point<int,3> pointB(pointA);

	return
	(
		pointB[0] == 4
			&&
		pointB[1] == 5
			&&
		pointB[2] == 6
	);

}

bool test_operatorAssignment_000 ( void )
{

	std::point<int,3> pointA {4,5,6};
	std::point<int,3> pointB;

	pointB = pointA;

	return
	(
		pointB[0] == 4
			&&
		pointB[1] == 5
			&&
		pointB[2] == 6
	);

}

bool test_operatorAssignment_001 ( void )
{

	std::point<float,3> pointA {4.1,5.43,6.56};
	std::point<float,3> pointB;

	pointB = pointA;

	return
	(
		pointB[0] == 4.1f
			&&
		pointB[1] == 5.43f
			&&
		pointB[2] == 6.56f
	);

}

bool test_operatorEqual_001 ( void )
{

	std::point<int,5> pointA {4,5,3,6,7};
	std::point<int,5> pointB {4,5,3,6,7};

	return
	(
		pointA == pointB
	);

}

bool test_operatorNotEqual_000 ( void )
{

	std::point<int,5> pointA {4,5,3,6,7};
	std::point<int,5> pointB {4,5,3,6,8};

	return
	(
		pointA != pointB
	);

}

bool test_getDimension_001 ( void )
{

	std::point<int,5> point {4,5,3,6,7};

	return
	(
		point.get_dimension() == 5
	);

}

bool test_getDimension_002 ( void )
{

	std::point<float,7> point {4,5,3,6,7,5,5};

	return
	(
		point.get_dimension() == 7
	);

}

bool test_operatorPlus_000 ( void )
{

	std::point<int,5> pointA {4,5,-3,6,7};
	std::point<int,5> pointB {4,-1,3,2,-3};
	std::point<int,5> pointC = pointA + pointB;

	return
	(
		pointC[0] == 8
			&&
		pointC[1] == 4
			&&
		pointC[2] == 0
			&&
		pointC[3] == 8
			&&
		pointC[4] == 4
	);

}

bool test_operatorMinus_000 ( void )
{

	std::point<int,5> pointA {4,5,-3,6,7};
	std::point<int,5> pointB {4,-1,3,2,-3};
	std::point<int,5> pointC = pointA - pointB;

	return
	(
		pointC[0] == 0
			&&
		pointC[1] == 6
			&&
		pointC[2] == -6
			&&
		pointC[3] == 4
			&&
		pointC[4] == 10
	);

}

bool test_getDistanceTo_000 ( void )
{

	std::point<int,2> pointA {1,1};
	std::point<int,2> pointB {1,5};

	return
	(
		pointA.get_distance_to(pointB) == 4
	);

}

bool test_getDistanceTo_001 ( void )
{

	std::point<int,2> pointA {0,0};
	std::point<int,2> pointB {1,1};

	return
	(
		pointA.get_distance_to(pointB) == float(sqrt(2))
	);

}

bool test_getDistanceTo_002 ( void )
{

	std::point<int,2> pointA {-1,1};
	std::point<int,2> pointB {1,-1};

	return
	(
		pointA.get_distance_to(pointB) == float(sqrt(2)*2)
	);

}

bool test_getDistanceTo_003 ( void )
{

	std::point<int,2> pointA {2,2};
	std::point<int,2> pointB {-2,-2};

	return
	(
		pointA.get_distance_to(pointB) == float(sqrt(2)*4)
	);

}

bool test_operatorMultiply_000 ( void )
{

	std::point<int,2> pointA {-1,5};
	std::point<int,2> pointB = pointA * -1;

	return
	(
		pointB[0] == 1
			&&
		pointB[1] == -5
	);

}

bool test_operatorMultiply_001 ( void )
{

	std::point<float,3> pointA {-1.4,4.6,-5.2};
	std::point<float,3> pointB = pointA * -0.5;

	return
	(
		pointB[0] == float(0.7)
			&&
		pointB[1] == float(-2.3)
			&&
		pointB[2] == float(2.6)
	);

}

bool test_validateDimensionMatch_000 ( void )
{

	std::point_i2 pointA {5,6};
	std::point_f2 pointB {5.3,6.3};

	try
	{
		pointA.validate_dimension_match(pointB);
	}
	catch ( std::ExcDimensionMismatch )
	{
		return false;
	}

	return true;

}

bool test_validateDimensionMatch_001 ( void )
{

	std::point_i2 pointA {5,6};
	std::point_f3 pointB {5.3,6.3,5};

	try
	{
		pointA.validate_dimension_match(pointB);
	}
	catch ( std::ExcDimensionMismatch )
	{
		return true;
	}

	return false;

}
*/

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}