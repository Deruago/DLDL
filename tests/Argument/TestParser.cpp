#include "DLDL/Argument/Parser.h"
#include <gtest/gtest.h>

class TestParser : public testing::Test
{
public:
	DLDL::argument::Parser parser;

protected:
	TestParser() = default;

	virtual ~TestParser() = default;

public:

};

#define ASSERT_VALUE_FROM_ARGUMENT(value, argument_) { DLDL::argument::Parser parser; ASSERT_EQ(value, parser.GetValueFromString(argument_)); }
#define ASSERT_ENUM_VALUE_FROM_ARG(type, argument_) { DLDL::argument::Parser parser = DLDL::argument::Parser(); ASSERT_EQ(type, parser.GetTypeFromString(argument_)); }

TEST_F(TestParser, GetValueFromArgumentWithValue_ShouldReturnEmptyString)
{
	ASSERT_VALUE_FROM_ARGUMENT("Test", "-language-name=Test");
	ASSERT_VALUE_FROM_ARGUMENT("TestLanguage", "-language-name=\"TestLanguage\"");
	ASSERT_VALUE_FROM_ARGUMENT("TestLanguage", "-unknown-argument=\"TestLanguage\"");
}

TEST_F(TestParser, GetValueFromArgumentWithoutValue_ShouldReturnEmptyString)
{
	ASSERT_VALUE_FROM_ARGUMENT("", "-init");
	ASSERT_VALUE_FROM_ARGUMENT("", "-language-name");
	ASSERT_VALUE_FROM_ARGUMENT("", "-unknown-argument");
	ASSERT_VALUE_FROM_ARGUMENT("", "-ln");
	ASSERT_VALUE_FROM_ARGUMENT("", "");
	ASSERT_VALUE_FROM_ARGUMENT("", "1123323");
	ASSERT_VALUE_FROM_ARGUMENT("", "assaddghfrstgds");
}

TEST_F(TestParser, InputArgument_ShouldReturnArgumentWhenAsked)
{
	const char* text[] = { "", "-language-name=\"TestLanguage\"" };
	DLDL::argument::Parser parser(2, text);

	const auto argument = parser.GetArgument(DLDL::argument::Type::language_name);

	ASSERT_EQ("TestLanguage", argument.value);
	ASSERT_EQ(DLDL::argument::Type::language_name, argument.type);
}

TEST_F(TestParser, InputNoArgument_AskArgumentNotEntered_ShouldReturnUnknownType)
{
	const char* text[] = { "" };
	DLDL::argument::Parser parser(1, text);

	const auto argument = parser.GetArgument(DLDL::argument::Type::auto_compile);

	ASSERT_EQ("", argument.value);
	ASSERT_EQ(DLDL::argument::Type::unknown, argument.type);
}

TEST_F(TestParser, InputArgument_AskArgumentNotEntered_ShouldReturnUnknownType)
{
	const char* text[] = { "", "-init" };
	DLDL::argument::Parser parser(2, text);

	const auto argument = parser.GetArgument(DLDL::argument::Type::auto_compile);

	ASSERT_EQ("", argument.value);
	ASSERT_EQ(DLDL::argument::Type::unknown, argument.type);
}

TEST_F(TestParser, InputArguments_ShouldReturnArgumentWhenAsked)
{
	const char* text[] = { "", "-language-name=\"TestLanguage\"", "-init", "-ln", "-help" };
	DLDL::argument::Parser parser(5, text);

	const auto argument = parser.GetArgument(DLDL::argument::Type::language_name);

	ASSERT_EQ("TestLanguage", argument.value);
	ASSERT_EQ(DLDL::argument::Type::language_name, argument.type);
}

TEST_F(TestParser, InputArguments_AskArgumentNotEntered_ShouldReturnUnknownType)
{
	const char* text[] = { "", "-init", "-ln", "-tl", "-about" };
	DLDL::argument::Parser parser(5, text);

	const auto argument = parser.GetArgument(DLDL::argument::Type::auto_compile);

	ASSERT_EQ("", argument.value);
	ASSERT_EQ(DLDL::argument::Type::unknown, argument.type);
}

TEST_F(TestParser, InputInvalidArgument_ShouldReturnUnknownType)
{
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::unknown, "");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::unknown, "-");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::unknown, "1123456789");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::unknown, "asedrfgyuhij");
}

TEST_F(TestParser, ConvertTextToEnumeration_ShouldCorrectlyReturnEnumeration)
{
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::initialize, "-init");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::initialize, "-initial");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::initialize, "-initialize");
	
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::language_name, "-ln");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::language_name, "-lang-name");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::language_name, "-language-name");

	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::generate, "-g");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::generate, "-gen");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::generate, "-generate");
	
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::version, "-v");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::version, "-version");
	
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::copyright, "-copyright");
	
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::help, "-h");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::help, "-help");
	
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::auto_compile, "-ac");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::auto_compile, "-auto-compile");
	
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::auto_run, "-ar");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::auto_run, "-auto-run");
	
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::profile, "-profile");
	
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::echo, "-echo");
	
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::debug_dldl, "-debug-dldl");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::debug_build, "-debug-build");
	
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::exit, "-q");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::exit, "-quit");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::exit, "-exit");
	
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::log, "-log");
	
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::target_language, "-tl");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::target_language, "-target-language");

	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::information, "-info");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::information, "-information");
	
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::definition_map, "-dm");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::definition_map, "-definition-map");
	
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::build_map, "-bm");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::build_map, "-build-map");
	
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::git_initialize, "-git-init");
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::git_initialize, "-git-initialize");
	
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::compatible, "-compatible");
	
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::target_os, "-target-os");
	
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::about, "-about");
	
	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::supported_grammars, "-supported-grammars");

	ASSERT_ENUM_VALUE_FROM_ARG(DLDL::argument::Type::print_parse_result, "-print-parser-output");
}