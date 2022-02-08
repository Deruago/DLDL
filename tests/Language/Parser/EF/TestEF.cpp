#include "DLDL_LPDDEF_EF/Ast/Listener/User/EF.h"
#include "DLDL_LPDDEF_EF/Bison/Parser.h"
#include <gtest/gtest.h>

class TestLPDDEF_EF : public testing::Test
{
public:
protected:
	TestLPDDEF_EF() = default;

	virtual ~TestLPDDEF_EF() = default;

public:
	DLDL_LPDDEF_EF::parser::Parser parser = DLDL_LPDDEF_EF::parser::Parser();
};

TEST_F(TestLPDDEF_EF, EmptyDefinition_ShouldCorrectlyParseEmptyDefinition)
{
	std::string text = "";
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(text));
	EXPECT_FALSE(ast == nullptr);
}
