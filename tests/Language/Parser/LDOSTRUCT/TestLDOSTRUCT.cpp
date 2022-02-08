#include "DLDL_LDOSTRUCT/Ast/Listener/User/LdoStruct.h"
#include "DLDL_LDOSTRUCT/Bison/Parser.h"
#include <gtest/gtest.h>

class TestLDOSTRUCT : public testing::Test
{
public:
protected:
	TestLDOSTRUCT() = default;

	virtual ~TestLDOSTRUCT() = default;

public:
	DLDL_LDOSTRUCT::parser::Parser parser = DLDL_LDOSTRUCT::parser::Parser();
};

TEST_F(TestLDOSTRUCT, EmptyDefinition_ShouldCorrectlyParseEmptyDefinition)
{
	std::string text = "";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLDOSTRUCT, ParseDefinition_VariousArgumentsWithValueDirectlyAfterColon)
{
	std::string text =
		"name:ABC\n"
		"description:BCD\n"
		"\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLDOSTRUCT, ParseDefinition_VariousArgumentsWithValueAfterColonAndSpace)
{
	std::string text =
		"name: ABC\n"
		"description: BCD\n"
		"\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLDOSTRUCT, ParseDefinition_VariousArgumentsWithValueAfterColonAndTab)
{
	std::string text =
		"name:	ABC\n"
		"description:	BCD\n"
		"\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}

TEST_F(TestLDOSTRUCT, Listener_ParseStandardDefinition)
{
	std::string text =
		"name:	ABC\n"
		"type: LDO\n"
		"description:	BCD\n"
		"\n";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	ASSERT_FALSE(ast == nullptr);

	auto listener = DLDL_LDOSTRUCT::ast::listener::user::LdoStruct();
	listener.Dispatch(ast->GetStartNode());
	std::unique_ptr<DLDL::ir::LDO> lpd(listener.GetLdoStruct());

	EXPECT_EQ("ABC", lpd->GetName());
	EXPECT_EQ(DLDL::ir::LDOType::Ldo, lpd->GetLDOType());
	EXPECT_EQ("BCD", lpd->GetDescription());
}
