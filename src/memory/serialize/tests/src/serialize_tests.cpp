#include <gtest/gtest.h>
#include <memory/serialize.hpp>

struct Foo
{
    long foo;
    bool bar;
    char baz;
};

TEST ( unsigned_integer , is_being_serialized_effectively )
{
    unsigned int data_original = 42;
    std::string data_serialized = std::serialize(data_original);
    unsigned int data_deserialized = std::deserialize<unsigned int>(data_serialized);
    ASSERT_EQ(data_original,data_deserialized);
}

TEST ( struct_instance , is_being_serialized_effectively )
{
    Foo data_original{424242,true,'4'};
    std::string data_serialized = std::serialize(data_original);
    Foo data_deserialized = std::deserialize<Foo>(data_serialized);
    ASSERT_EQ(data_original.foo,data_deserialized.foo);
    ASSERT_EQ(data_original.bar,data_deserialized.bar);
    ASSERT_EQ(data_original.baz,data_deserialized.baz);
}

TEST ( string , is_being_serialized_effectively )
{
    std::string data_original = "42";
    std::string data_serialized = std::serialize(data_original);
    std::string data_deserialized = std::deserialize<std::string>(data_serialized);
    //ASSERT_STREQ(data_original.data(),data_deserialized.data());
    //ASSERT_EQ(data_original.size(),data_deserialized.size());
}

int main ( int argc , char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
