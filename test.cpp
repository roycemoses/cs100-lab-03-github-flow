#include "header/c-echo.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
	char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
	EXPECT_EQ("hello world", echo(3, test_val));
}

TEST(EchoTest, EmptyString) {
	char* test_val[1]; test_val[0] = "./c-echo";
	EXPECT_EQ("", echo(1,test_val));
}

TEST(EchoTest, AllUpperCase) {
	char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "HELLO"; test_val[2] = "WORLD";
	EXPECT_EQ("HELLO WORLD", echo(3, test_val));
}

TEST(EchoTest, SpecialCharacters) {
	char* test_val[2]; test_val[0] = "./c-echo"; test_val[1] = "!@#$%^&*()";
	EXPECT_EQ("!@#$%^&*()", echo(2, test_val));
}

TEST(EchoTest, TabCharacter) {
	char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "Hello	"; test_val[2] = "	World	";
	EXPECT_EQ("Hello	 	World	", echo(3, test_val));
}

TEST(EchoTest, NewLineCharacter) {
	char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "Hello\n";
test_val[2] = "\nWorld";
	EXPECT_EQ("Hello\n \nWorld", echo(3, test_val));
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

