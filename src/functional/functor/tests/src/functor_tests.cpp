#include <gtest/gtest.h>
#include <std/functional/functor.hpp>



struct success
{
	success ( void* data ) : data(data) { }
	void* data;
};

struct object_type
{
	void method ( void* data )
	{
		throw success(data);
	}
};



TEST ( functor , does_not_throw_exceptions_while_construction )
{

	object_type object;

	ASSERT_NO_THROW(std::functor<object_type>(&object,&object_type::method));

}

TEST ( functor , invokes_successfully )
{

	object_type object;
	std::functor<object_type> functor(&object,&object_type::method);

	ASSERT_THROW(functor(nullptr),success);

}

TEST ( functor , recieves_data_successfully )
{

	object_type object;
	int data = 42;
	std::functor<object_type> functor(&object,&object_type::method);
	
	try
	{
		functor(&data);
	}
	
	catch ( success success_exception )
	{
	
		int* data_ptr = static_cast<int*>(success_exception.data);
		
		ASSERT_EQ(*data_ptr,42);
		return;
		
	}
	
	ASSERT_EQ(0,1);
	
}

TEST ( functor , invokes_successfully_by_invoke_method )
{

	object_type object;
	int data = 42;
	std::functor<object_type> functor(&object,&object_type::method);
	
	try
	{
		functor.invoke(&data);
	}
	
	catch ( success success_exception )
	{
	
		int* data_ptr = static_cast<int*>(success_exception.data);
		
		ASSERT_EQ(*data_ptr,42);
		return;
		
	}
	
	ASSERT_EQ(0,1);

}



int main ( int argc , char** argv )
{

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}