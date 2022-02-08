#include "DLDL_LPDDEF_DF/Ast/Listener/User/DF.h"
#include "DLDL_LPDDEF_DF/Bison/Parser.h"
#include <gtest/gtest.h>

class TestLPDDEF_DF : public testing::Test
{
public:
protected:
	TestLPDDEF_DF() = default;

	virtual ~TestLPDDEF_DF() = default;

public:
	DLDL_LPDDEF_DF::parser::Parser parser = DLDL_LPDDEF_DF::parser::Parser();
};

TEST_F(TestLPDDEF_DF, EmptyDefinition_ShouldCorrectlyParseEmptyDefinition)
{
	std::string text = "";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF_DF, ParseDefinition_1Vector_ShouldCorrectlyParse)
{
	std::string text = "Vector<Terminal> Terminals\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF_DF, ParseDefinition_2Vector_ShouldCorrectlyParse)
{
	std::string text =
		"Vector<Terminal> Terminals\n"
		"Vector<NonTerminal> nonterminals\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF_DF, ParseDefinition_1Optional_ShouldCorrectlyParse)
{
	std::string text = "Optional<Terminal> terminal\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF_DF, ParseDefinition_2Optional_ShouldCorrectlyParse)
{
	std::string text =
		"Optional<Terminal> terminal\n"
		"Optional<NonTerminal> nonterminal\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF_DF, ParseDefinition_1Standard_ShouldCorrectlyParse)
{
	std::string text = "Terminal terminal\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF_DF, ParseDefinition_2Standard_ShouldCorrectlyParse)
{
	std::string text =
		"Terminal terminal\n"
		"NonTerminal nonterminal\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF_DF, ParseDefinition_1VectorWithDefaultValue_ShouldCorrectlyParse)
{
	std::string text = "Vector<Terminal> Terminals = {}\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF_DF, ParseDefinition_2VectorWithDefaultValue_ShouldCorrectlyParse)
{
	std::string text =
		"Vector<Terminal> Terminals = {}\n"
		"Vector<NonTerminal> nonterminals = {}\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF_DF, ParseDefinition_1OptionalWithDefaultValue_ShouldCorrectlyParse)
{
	std::string text = "Optional<Terminal> terminal = {}\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF_DF, ParseDefinition_2OptionalWithDefaultValue_ShouldCorrectlyParse)
{
	std::string text =
		"Optional<Terminal> terminal = {}\n"
		"Optional<NonTerminal> nonterminal = {}\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF_DF, ParseDefinition_1StandardWithDefaultValue_ShouldCorrectlyParse)
{
	std::string text = "Terminal terminal = {}\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF_DF, ParseDefinition_2StandardWithDefaultValue_ShouldCorrectlyParse)
{
	std::string text =
		"Terminal terminal = {}\n"
		"NonTerminal nonterminal = {}\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF_DF, ParseDefinition_1StandardWithNumberValue_ShouldCorrectlyParse)
{
	std::string text = "unsigned ColorId = 0\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF_DF, ParseDefinition_2StandardWithNumberValue_ShouldCorrectlyParse)
{
	std::string text =
		"unsigned ColorId = 0\n"
		"unsigneda ColorIda = 12342420\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF_DF, ParseDefinition_1StandardWithEnumerationValue_ShouldCorrectlyParse)
{
	std::string text = "NonTerminalAbstraction abstraction = NonTerminalAbstraction::Standard\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF_DF, ParseDefinition_2StandardWithEnumerationValue_ShouldCorrectlyParse)
{
	std::string text =
		"NonTerminalAbstraction abstraction = NonTerminalAbstraction::Standard\n"
		"NonTerminalAbstraction abstraction = NonTerminalAbstraction::Unknown\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF_DF, ParseDefinition_1BoolWithDefaultValue_ShouldCorrectlyParse)
{
	std::string text = "bool terminal = true\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF_DF, ParseDefinition_2BoolWithDefaultValue_ShouldCorrectlyParse)
{
	std::string text =
		"bool terminal = true\n"
		"bool nonterminal = false\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}
