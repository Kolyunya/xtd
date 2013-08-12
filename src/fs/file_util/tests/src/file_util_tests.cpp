#include <gtest/gtest.h>
#include <std/fs/file_util.hpp>

TEST ( file_test_000_txt , exists )
{

	ASSERT_TRUE ( std::fs::get_file_exists("tests/data/test_000.txt") );

}

TEST ( file_test_42_dat , does_not_exist )
{

	ASSERT_FALSE ( std::fs::get_file_exists("tests/data/test_42.dat") );

}

TEST ( file_test_000_txt_contents , is_simple_test )
{

	std::string file_path = "tests/data/test_000.txt";
	std::string file_contents_expected = "simple test";
	std::string file_contents_actual = std::fs::get_file_contents(file_path);
	
	ASSERT_EQ ( file_contents_expected , file_contents_actual );
	
}

TEST ( file_test_000_txt_size , is_11_bytes )
{

	std::string file_path = "tests/data/test_000.txt";
	off_t file_size_expected = 11;
	off_t file_size_actual = std::fs::get_file_size(file_path);
	
	ASSERT_EQ ( file_size_expected , file_size_actual );
	
}

TEST ( file_test_001_data_contents , is_simple_Cl_multiline_CL_test )
{

	std::string file_path = "tests/data/test_001.data";
	std::string file_contents_expected = "simple\nmultiline\ntest";
	std::string file_contents_actual = std::fs::get_file_contents(file_path);
	
	ASSERT_EQ ( file_contents_expected , file_contents_actual );
	
}

TEST ( file_test_002_contents , is_read_correctly_by_std_fs_get_file_contents )
{

	std::string file_path = "tests/data/test_002";
	std::string file_contents_expected = "multiline test with\nmany   spaces\nsome\ttablution\n\nempty lines\nand some special ,./-= characters\n\n";
	std::string file_contents_actual = std::fs::get_file_contents(file_path);
	
	ASSERT_EQ ( file_contents_expected , file_contents_actual );
	
}

TEST ( file_test_003_contents , is_empty )
{

	std::string file_path = "tests/data/.test_003";
	std::string file_contents_expected = "";
	std::string file_contents_actual = std::fs::get_file_contents(file_path);
	
	ASSERT_EQ ( file_contents_expected , file_contents_actual );
	
}

TEST ( file_test_004_contents , is_does_CL_it_CL_really_CL_work_CL )
{

	std::string file_path = "tests/data/...test_004";
	std::string file_contents_expected = "does\nit\nreally\nwork\n?";
	std::string file_contents_actual = std::fs::get_file_contents(file_path);
	
	ASSERT_EQ ( file_contents_expected , file_contents_actual );
	
}

TEST ( get_file_contents , throws_runtime_error_while_trying_to_get_contents_of_a_file_which_does_not_exist )
{

	ASSERT_THROW ( std::fs::get_file_contents("unexisting_file") , std::runtime_error );

}

TEST ( std_fs_set_file_contents , sets_data_test_005_file_contents_to_hello_world_effectively )
{

	std::string file_path = "tests/data/test_005";
	std::string file_contents_expected = "hello world";
	std::fs::set_file_contents(file_path,file_contents_expected);
	std::string file_contents_actual = std::fs::get_file_contents(file_path);
	
	ASSERT_EQ ( file_contents_expected , file_contents_actual );
	
}

TEST ( std_fs_append_file_contents , appends_CL_appended_text_to_test_005_file )
{

	std::string file_path = "tests/data/test_005";
	std::string appended_text = "\nappended text";
	std::string file_contents_expected = "hello world" + appended_text;
	
	std::fs::append_file_contents(file_path,appended_text);
	std::string file_contents_actual = std::fs::get_file_contents(file_path);
	
	ASSERT_EQ ( file_contents_expected , file_contents_actual );
	
}

TEST ( std_fs_append_file_contents , prepends_CL_appended_text_to_test_005_file )
{

	std::string file_path = "tests/data/test_005";
	std::string prepended_text = "\nprepended text";
	std::string file_contents_expected = prepended_text + "hello world\nappended text";
	
	std::fs::prepend_file_contents(file_path,prepended_text);
	std::string file_contents_actual = std::fs::get_file_contents(file_path);
	
	ASSERT_EQ ( file_contents_expected , file_contents_actual );
	
}

TEST ( std_fs_truncate_file_contents , truncates_file_test_005_file_effectively )
{

	std::string file_path = "tests/data/test_005";
	
	std::fs::truncate_file_contents(file_path);
	
	std::string file_contents_expected = "";
	std::string file_contents_actual = std::fs::get_file_contents(file_path);
	
	ASSERT_EQ ( file_contents_expected , file_contents_actual );
	
}

int main ( int argc , char** argv )
{

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}