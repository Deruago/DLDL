#include "DLDL_LPDDEF/Ast/Listener/User/LpdDef.h"
#include "DLDL_LPDDEF/Bison/Parser.h"
#include <gtest/gtest.h>

class TestLPDDEF : public testing::Test
{
public:
protected:
	TestLPDDEF() = default;

	virtual ~TestLPDDEF() = default;

public:
	DLDL_LPDDEF::parser::Parser parser = DLDL_LPDDEF::parser::Parser();
};

TEST_F(TestLPDDEF, EmptyDefinition_ShouldCorrectlyParseEmptyDefinition)
{
	std::string text = "";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF, ParseDefinition_VariousArgumentsWithValueDirectlyAfterColon)
{
	std::string text =
		"name:ABC\n"
		"description:BCD\n"
		"\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF, ParseDefinition_VariousArgumentsWithValueAfterColonAndSpace)
{
	std::string text =
		"name: ABC\n"
		"description: BCD\n"
		"\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF, ParseDefinition_VariousArgumentsWithValueAfterColonAndTab)
{
	std::string text =
		"name:	ABC\n"
		"description:	BCD\n"
		"\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLPDDEF, Listener_ParseStandardDefinition)
{
	std::string text =
		"name:	ABC\n"
		"type: main\n"
		"description:	BCD\n"
		"\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	ASSERT_FALSE(ast == nullptr);

	auto listener = DLDL_LPDDEF::ast::listener::user::LpdDef();
	listener.Dispatch(ast->GetStartNode());
	std::unique_ptr<DLDL::ir::LpdDef> lpd(listener.GetLpdDef());

	EXPECT_EQ("ABC", lpd->GetName());
	EXPECT_EQ(DLDL::ir::LPDType::main, lpd->GetLPDType());
	EXPECT_EQ("BCD", lpd->GetDescription());
}

TEST_F(TestLPDDEF, Listener_ParseStandardDefinitionWithAngleBlocks)
{
	std::string text =
		"name:	ABC\n"
		"type: main\n"
		"description: <\n"
		"	BCD\n"
		">\n"
		"\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	ASSERT_FALSE(ast == nullptr);

	auto listener = DLDL_LPDDEF::ast::listener::user::LpdDef();
	listener.Dispatch(ast->GetStartNode());
	std::unique_ptr<DLDL::ir::LpdDef> lpd(listener.GetLpdDef());

	EXPECT_EQ("ABC", lpd->GetName());
	EXPECT_EQ(DLDL::ir::LPDType::main, lpd->GetLPDType());
	EXPECT_EQ("BCD\n", lpd->GetDescription());
}

TEST_F(TestLPDDEF, Listener_ParseStandardDefinitionWithAngleBlocksMultipleLines_OneLineHas2Spaces)
{
	std::string text =
		"name:	ABC\n"
		"type: main\n"
		"description: <\n"
		"	BCD\n"
		"	EFGRR\n"
		"	BBA ACC\n"
		">\n"
		"\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	ASSERT_FALSE(ast == nullptr);

	auto listener = DLDL_LPDDEF::ast::listener::user::LpdDef();
	listener.Dispatch(ast->GetStartNode());
	std::unique_ptr<DLDL::ir::LpdDef> lpd(listener.GetLpdDef());

	EXPECT_EQ("ABC", lpd->GetName());
	EXPECT_EQ(DLDL::ir::LPDType::main, lpd->GetLPDType());
	EXPECT_EQ("BCD\nEFGRR\nBBA ACC\n", lpd->GetDescription());
}

TEST_F(TestLPDDEF, Listener_ParseStandardDefinitionWithAngleBlocksMultipleLines_OneLineHas3Spaces)
{
	std::string text =
		"name:	ABC\n"
		"type: main\n"
		"description: <\n"
		"	BCD\n"
		"	EFGRR\n"
		"	BBA ACC RRR\n"
		">\n"
		"\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	ASSERT_FALSE(ast == nullptr);

	auto listener = DLDL_LPDDEF::ast::listener::user::LpdDef();
	listener.Dispatch(ast->GetStartNode());
	std::unique_ptr<DLDL::ir::LpdDef> lpd(listener.GetLpdDef());

	EXPECT_EQ("ABC", lpd->GetName());
	EXPECT_EQ(DLDL::ir::LPDType::main, lpd->GetLPDType());
	EXPECT_EQ("BCD\nEFGRR\nBBA ACC RRR\n", lpd->GetDescription());
}
