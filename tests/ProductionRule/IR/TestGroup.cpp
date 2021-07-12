#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Listener/User/FillGroup.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Bison/Parser.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Return;
using namespace DLDL_GRAMMAR_PRODUCTION_RULE::ast::listener::user;

class TestGroup : public testing::Test
{
public:
protected:
	TestGroup() = default;

	virtual ~TestGroup() = default;

public:
};

TEST_F(TestGroup, Bnf_CorrectlyGeneratesProductionRules)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "function_type VARNAME LEFT_PARAN arguments RIGHT_PARAN";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	const auto generatedEnvironment = group->GetEnvironment();

	EXPECT_EQ(1, generatedEnvironment.currentProductionRules.size());

	EXPECT_EQ(5, generatedEnvironment.currentProductionRules[0].values.size());

	EXPECT_EQ("function_type", generatedEnvironment.currentProductionRules[0].values[0]->name);
	EXPECT_EQ("VARNAME", generatedEnvironment.currentProductionRules[0].values[1]->name);
	EXPECT_EQ("LEFT_PARAN", generatedEnvironment.currentProductionRules[0].values[2]->name);
	EXPECT_EQ("arguments", generatedEnvironment.currentProductionRules[0].values[3]->name);
	EXPECT_EQ("RIGHT_PARAN", generatedEnvironment.currentProductionRules[0].values[4]->name);

	delete group;
	delete result;
}

TEST_F(TestGroup, BnfEmpty_CorrectlyGeneratesEmptyProductionRule)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "EMPTY EMPTY EPSILON";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	const auto generatedEnvironment = group->GetEnvironment();

	EXPECT_EQ(1, generatedEnvironment.currentProductionRules.size());

	EXPECT_EQ(0, generatedEnvironment.currentProductionRules[0].values.size());

	delete group;
	delete result;
}

TEST_F(TestGroup, EbnfSingleOptional_CorrectlyGeneratesProductionRules)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "[VARNAME]";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	const auto generatedEnvironment = group->GetEnvironment();

	EXPECT_EQ(2, generatedEnvironment.currentProductionRules.size());

	EXPECT_EQ(1, generatedEnvironment.currentProductionRules[0].values.size());
	EXPECT_EQ(0, generatedEnvironment.currentProductionRules[1].values.size());

	EXPECT_EQ("VARNAME", generatedEnvironment.currentProductionRules[0].values[0]->name);

	delete group;
	delete result;
}

TEST_F(TestGroup, EbnfSingleOptional_RedundantOptionalNotation_CorrectlyGeneratesProductionRules)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "[VARNAME]?";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	const auto generatedEnvironment = group->GetEnvironment();

	EXPECT_EQ(2, generatedEnvironment.currentProductionRules.size());

	EXPECT_EQ(1, generatedEnvironment.currentProductionRules[0].values.size());
	EXPECT_EQ(0, generatedEnvironment.currentProductionRules[1].values.size());

	EXPECT_EQ("VARNAME", generatedEnvironment.currentProductionRules[0].values[0]->name);

	delete group;
	delete result;
}

TEST_F(TestGroup, EbnfDoubleOptional_CorrectlyGeneratesProductionRules)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "[VARNAME] [LEFT_PARAN]";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	const auto generatedEnvironment = group->GetEnvironment();

	EXPECT_EQ(4, generatedEnvironment.currentProductionRules.size());

	EXPECT_EQ(2, generatedEnvironment.currentProductionRules[0].values.size());
	EXPECT_EQ(1, generatedEnvironment.currentProductionRules[1].values.size());
	EXPECT_EQ(1, generatedEnvironment.currentProductionRules[2].values.size());
	EXPECT_EQ(0, generatedEnvironment.currentProductionRules[3].values.size());

	EXPECT_EQ("VARNAME", generatedEnvironment.currentProductionRules[0].values[0]->name);
	EXPECT_EQ("LEFT_PARAN", generatedEnvironment.currentProductionRules[0].values[1]->name);

	EXPECT_EQ("VARNAME", generatedEnvironment.currentProductionRules[1].values[0]->name);

	EXPECT_EQ("LEFT_PARAN", generatedEnvironment.currentProductionRules[2].values[0]->name);

	delete group;
	delete result;
}

TEST_F(TestGroup, EbnfDoubleOptionalWithStandardTerminal_CorrectlyGeneratesProductionRules)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "[VARNAME] ALWAYS [LEFT_PARAN]";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	const auto generatedEnvironment = group->GetEnvironment();

	EXPECT_EQ(4, generatedEnvironment.currentProductionRules.size());

	EXPECT_EQ(3, generatedEnvironment.currentProductionRules[0].values.size());
	EXPECT_EQ(2, generatedEnvironment.currentProductionRules[1].values.size());
	EXPECT_EQ(2, generatedEnvironment.currentProductionRules[2].values.size());
	EXPECT_EQ(1, generatedEnvironment.currentProductionRules[3].values.size());

	EXPECT_EQ("VARNAME", generatedEnvironment.currentProductionRules[0].values[0]->name);
	EXPECT_EQ("ALWAYS", generatedEnvironment.currentProductionRules[0].values[1]->name);
	EXPECT_EQ("LEFT_PARAN", generatedEnvironment.currentProductionRules[0].values[2]->name);

	EXPECT_EQ("VARNAME", generatedEnvironment.currentProductionRules[1].values[0]->name);
	EXPECT_EQ("ALWAYS", generatedEnvironment.currentProductionRules[1].values[1]->name);

	EXPECT_EQ("ALWAYS", generatedEnvironment.currentProductionRules[2].values[0]->name);
	EXPECT_EQ("LEFT_PARAN", generatedEnvironment.currentProductionRules[2].values[1]->name);

	EXPECT_EQ("ALWAYS", generatedEnvironment.currentProductionRules[3].values[0]->name);

	delete group;
	delete result;
}

TEST_F(TestGroup, EbnfSingleOr_CorrectlyGeneratesProductionRules)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "(VARNAME|TYPENAME)";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	const auto generatedEnvironment = group->GetEnvironment();

	EXPECT_EQ(2, generatedEnvironment.currentProductionRules.size());

	EXPECT_EQ(1, generatedEnvironment.currentProductionRules[0].values.size());
	EXPECT_EQ(1, generatedEnvironment.currentProductionRules[1].values.size());

	EXPECT_EQ("VARNAME", generatedEnvironment.currentProductionRules[0].values[0]->name);
	EXPECT_EQ("TYPENAME", generatedEnvironment.currentProductionRules[1].values[0]->name);

	delete group;
	delete result;
}

TEST_F(TestGroup, EbnfDoubleOr_CorrectlyGeneratesProductionRules)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "(VARNAME|TYPENAME|CLASSNAME)";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	const auto generatedEnvironment = group->GetEnvironment();

	EXPECT_EQ(3, generatedEnvironment.currentProductionRules.size());

	EXPECT_EQ(1, generatedEnvironment.currentProductionRules[0].values.size());
	EXPECT_EQ(1, generatedEnvironment.currentProductionRules[1].values.size());
	EXPECT_EQ(1, generatedEnvironment.currentProductionRules[2].values.size());

	EXPECT_EQ("VARNAME", generatedEnvironment.currentProductionRules[0].values[0]->name);
	EXPECT_EQ("TYPENAME", generatedEnvironment.currentProductionRules[1].values[0]->name);
	EXPECT_EQ("CLASSNAME", generatedEnvironment.currentProductionRules[2].values[0]->name);

	delete group;
	delete result;
}

TEST_F(TestGroup, EbnfOptionalDoubleOr_CorrectlyGeneratesProductionRules)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "(VARNAME|TYPENAME|CLASSNAME)?";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	const auto generatedEnvironment = group->GetEnvironment();

	EXPECT_EQ(4, generatedEnvironment.currentProductionRules.size());

	EXPECT_EQ(1, generatedEnvironment.currentProductionRules[0].values.size());
	EXPECT_EQ(1, generatedEnvironment.currentProductionRules[1].values.size());
	EXPECT_EQ(1, generatedEnvironment.currentProductionRules[2].values.size());
	EXPECT_EQ(0, generatedEnvironment.currentProductionRules[3].values.size());

	EXPECT_EQ("VARNAME", generatedEnvironment.currentProductionRules[0].values[0]->name);
	EXPECT_EQ("TYPENAME", generatedEnvironment.currentProductionRules[1].values[0]->name);
	EXPECT_EQ("CLASSNAME", generatedEnvironment.currentProductionRules[2].values[0]->name);

	delete group;
	delete result;
}

TEST_F(TestGroup, EbnfOptionalDoubleOrWithNestedGroups_CorrectlyGeneratesProductionRules)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text =
		"(VARNAME|(TYPENAME LEFT_ANGLE_BRACKET RIGHT_ANGLE_BRACKET)|(CLASSNAME LEFT_PARAN "
		"RIGHT_PARAN))?";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	const auto generatedEnvironment = group->GetEnvironment();

	EXPECT_EQ(4, generatedEnvironment.currentProductionRules.size());

	EXPECT_EQ(1, generatedEnvironment.currentProductionRules[0].values.size());
	EXPECT_EQ(3, generatedEnvironment.currentProductionRules[1].values.size());
	EXPECT_EQ(3, generatedEnvironment.currentProductionRules[2].values.size());
	EXPECT_EQ(0, generatedEnvironment.currentProductionRules[3].values.size());

	EXPECT_EQ("VARNAME", generatedEnvironment.currentProductionRules[0].values[0]->name);

	EXPECT_EQ("TYPENAME", generatedEnvironment.currentProductionRules[1].values[0]->name);
	EXPECT_EQ("LEFT_ANGLE_BRACKET", generatedEnvironment.currentProductionRules[1].values[1]->name);
	EXPECT_EQ("RIGHT_ANGLE_BRACKET",
			  generatedEnvironment.currentProductionRules[1].values[2]->name);

	EXPECT_EQ("CLASSNAME", generatedEnvironment.currentProductionRules[2].values[0]->name);
	EXPECT_EQ("LEFT_PARAN", generatedEnvironment.currentProductionRules[2].values[1]->name);
	EXPECT_EQ("RIGHT_PARAN", generatedEnvironment.currentProductionRules[2].values[2]->name);

	delete group;
	delete result;
}

TEST_F(TestGroup,
	   EbnfOptionalDoubleOrWithNestedGroupsWithNestedOrs_CorrectlyGeneratesProductionRules)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text =
		"(VARNAME|(TYPENAME ((LEFT_ANGLE_BRACKET RIGHT_ANGLE_BRACKET)|(LEFT_PARAN "
		"RIGHT_PARAN)))|(CLASSNAME LEFT_PARAN "
		"RIGHT_PARAN))?";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	const auto generatedEnvironment = group->GetEnvironment();

	EXPECT_EQ(5, generatedEnvironment.currentProductionRules.size());

	EXPECT_EQ(1, generatedEnvironment.currentProductionRules[0].values.size());
	EXPECT_EQ(3, generatedEnvironment.currentProductionRules[1].values.size());
	EXPECT_EQ(3, generatedEnvironment.currentProductionRules[2].values.size());
	EXPECT_EQ(3, generatedEnvironment.currentProductionRules[3].values.size());
	EXPECT_EQ(0, generatedEnvironment.currentProductionRules[4].values.size());

	EXPECT_EQ("VARNAME", generatedEnvironment.currentProductionRules[0].values[0]->name);

	EXPECT_EQ("TYPENAME", generatedEnvironment.currentProductionRules[1].values[0]->name);
	EXPECT_EQ("LEFT_ANGLE_BRACKET", generatedEnvironment.currentProductionRules[1].values[1]->name);
	EXPECT_EQ("RIGHT_ANGLE_BRACKET",
			  generatedEnvironment.currentProductionRules[1].values[2]->name);

	EXPECT_EQ("TYPENAME", generatedEnvironment.currentProductionRules[2].values[0]->name);
	EXPECT_EQ("LEFT_PARAN", generatedEnvironment.currentProductionRules[2].values[1]->name);
	EXPECT_EQ("RIGHT_PARAN", generatedEnvironment.currentProductionRules[2].values[2]->name);

	EXPECT_EQ("CLASSNAME", generatedEnvironment.currentProductionRules[3].values[0]->name);
	EXPECT_EQ("LEFT_PARAN", generatedEnvironment.currentProductionRules[3].values[1]->name);
	EXPECT_EQ("RIGHT_PARAN", generatedEnvironment.currentProductionRules[3].values[2]->name);

	delete group;
	delete result;
}

TEST_F(TestGroup, EbnfSingleStar_CorrectlyGeneratesProductionRules)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "VARNAME*";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	const auto generatedEnvironment = group->GetEnvironment();

	EXPECT_EQ(1, generatedEnvironment.currentProductionRules.size());
	EXPECT_EQ(1, generatedEnvironment.nonterminals.size());

	EXPECT_EQ(1, generatedEnvironment.currentProductionRules[0].values.size());

	EXPECT_EQ("deamerreserved_star__VARNAME__",
			  generatedEnvironment.currentProductionRules[0].values[0]->name);
	EXPECT_EQ("deamerreserved_star__VARNAME__", generatedEnvironment.nonterminals[0].name);
	EXPECT_EQ(2, generatedEnvironment.nonterminals[0].productionRules.size());
	EXPECT_EQ(2, generatedEnvironment.nonterminals[0].productionRules[0].values.size());
	EXPECT_EQ(0, generatedEnvironment.nonterminals[0].productionRules[1].values.size());

	EXPECT_EQ("VARNAME", generatedEnvironment.nonterminals[0].productionRules[0].values[0]->name);
	EXPECT_EQ("deamerreserved_star__VARNAME__", generatedEnvironment.nonterminals[0].productionRules[0].values[1]->name);

	delete group;
	delete result;
}

TEST_F(TestGroup, EbnfSinglePlus_CorrectlyGeneratesProductionRules)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "VARNAME+";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	const auto generatedEnvironment = group->GetEnvironment();

	generatedEnvironment.Print();
	EXPECT_EQ(1, generatedEnvironment.currentProductionRules.size());
	EXPECT_EQ(1, generatedEnvironment.nonterminals.size());

	EXPECT_EQ(1, generatedEnvironment.currentProductionRules[0].values.size());

	EXPECT_EQ("deamerreserved_plus__VARNAME__",
			  generatedEnvironment.currentProductionRules[0].values[0]->name);
	EXPECT_EQ("deamerreserved_plus__VARNAME__", generatedEnvironment.nonterminals[0].name);
	EXPECT_EQ(2, generatedEnvironment.nonterminals[0].productionRules.size());
	EXPECT_EQ(2, generatedEnvironment.nonterminals[0].productionRules[0].values.size());
	EXPECT_EQ(1, generatedEnvironment.nonterminals[0].productionRules[1].values.size());

	EXPECT_EQ("VARNAME", generatedEnvironment.nonterminals[0].productionRules[0].values[0]->name);
	EXPECT_EQ("deamerreserved_plus__VARNAME__",
			  generatedEnvironment.nonterminals[0].productionRules[0].values[1]->name);
	EXPECT_EQ("deamerreserved_plus__VARNAME__",
			  generatedEnvironment.nonterminals[0].productionRules[1].values[0]->name);

	
	delete group;
	delete result;
}