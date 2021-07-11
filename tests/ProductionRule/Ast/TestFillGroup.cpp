#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Listener/User/FillGroup.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Bison/Parser.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Return;
using namespace DLDL_GRAMMAR_PRODUCTION_RULE::ast::listener::user;

class TestFillGroup : public testing::Test
{
public:
protected:
	TestFillGroup() = default;

	virtual ~TestFillGroup() = default;

public:
};

TEST_F(TestFillGroup, GetGroupOfNothingPr_ShouldReturnEmptyGroup)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	ASSERT_EQ(0, group->GetSubGroups().size());

	delete group;
}

TEST_F(TestFillGroup, GetGroupOfEMPTYPr_ShouldReturnEmptyGroup)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "EMPTY";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	ASSERT_EQ(0, group->GetSubGroups().size());

	delete group;
}

TEST_F(TestFillGroup, GetGroupOfEPSILONPr_ShouldReturnEmptyGroup)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "EPSILON";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	ASSERT_EQ(0, group->GetSubGroups().size());

	delete group;
}

TEST_F(TestFillGroup, GetGroupOfBnfPr_ShouldCorrectlyGiveA_SingleGroupWith5SubGroups)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "function_type VARNAME LEFT_PARAN arguments RIGHT_PARAN";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	ASSERT_EQ(5, group->GetSubGroups().size());

	delete group;
}

TEST_F(
	TestFillGroup,
	GetGroupOfEbnfPrWithOptionalPart_ShouldCorrectlyGiveA_SingleGroupWith4SubGroups_OptionalPartHas2SubGroups)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "[function_type VARNAME] LEFT_PARAN arguments RIGHT_PARAN";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	ASSERT_EQ(4, group->GetSubGroups().size());
	ASSERT_EQ(2, group->GetSubGroups()[0]->GetSubGroups().size());

	delete group;
}

TEST_F(
	TestFillGroup,
	GetGroupOfEbnfPrWithOptionalPart_ShouldCorrectlyGiveA_SingleGroupWith5SubGroups_OptionalPartHas1SubGroups)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "[function_type] [VARNAME] LEFT_PARAN arguments RIGHT_PARAN";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	ASSERT_EQ(5, group->GetSubGroups().size());
	ASSERT_EQ(1, group->GetSubGroups()[0]->GetSubGroups().size());
	ASSERT_EQ(1, group->GetSubGroups()[1]->GetSubGroups().size());

	delete group;
}

TEST_F(TestFillGroup, EbnfOrGroup_ShouldCorrectlyGiveSubGroups)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "(function_type|VARNAME) LEFT_PARAN arguments RIGHT_PARAN";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	ASSERT_EQ(4, group->GetSubGroups().size());
	ASSERT_EQ(1, group->GetSubGroups()[0]->GetSubGroups().size()); // nested group
	ASSERT_EQ(2, group->GetSubGroups()[0]->GetSubGroups()[0]->GetSubGroups().size()); // or group

	delete group;
}

TEST_F(TestFillGroup, EbnfOrGroupMultiple_ShouldCorrectlyGiveSubGroups)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "(function_type|VARNAME|LEFT_PARAN) arguments RIGHT_PARAN";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	ASSERT_EQ(3, group->GetSubGroups().size());
	ASSERT_EQ(1, group->GetSubGroups()[0]->GetSubGroups().size()); // nested group
	ASSERT_EQ(2, group->GetSubGroups()[0]->GetSubGroups()[0]->GetSubGroups().size()); // or group
	// or group rhs
	ASSERT_EQ(
		2, group->GetSubGroups()[0]->GetSubGroups()[0]->GetSubGroups()[1]->GetSubGroups().size());

	delete group;
}

TEST_F(TestFillGroup, EbnfOrGroupWithNestedGroups_ShouldCorrectlyGiveSubGroups)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "((function_type VARNAME)|(LEFT_PARAN arguments)) RIGHT_PARAN";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	ASSERT_EQ(2, group->GetSubGroups().size());
	ASSERT_EQ(1, group->GetSubGroups()[0]->GetSubGroups().size()); // nested group
	ASSERT_EQ(2, group->GetSubGroups()[0]->GetSubGroups()[0]->GetSubGroups().size()); // or group
	ASSERT_EQ(2,
			  group->GetSubGroups()[0]
				  ->GetSubGroups()[0]
				  ->GetSubGroups()[0]
				  ->GetSubGroups()
				  .size()); // nested 1 group
	ASSERT_EQ(2,
			  group->GetSubGroups()[0]
				  ->GetSubGroups()[0]
				  ->GetSubGroups()[1]
				  ->GetSubGroups()
				  .size()); // nested 2 group

	delete group;
}

TEST_F(TestFillGroup, EbnfNestedGroups_ShouldCorrectlyGiveSubGroups)
{
	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "(function_type VARNAME) (LEFT_PARAN arguments) RIGHT_PARAN";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	const auto* const startNode = result->GetStartNode();

	FillGroup fillGroup;
	fillGroup.Dispatch(startNode);

	auto* group = fillGroup.GetGroup();

	ASSERT_EQ(3, group->GetSubGroups().size());
	ASSERT_EQ(2, group->GetSubGroups()[0]->GetSubGroups().size());
	ASSERT_EQ(2, group->GetSubGroups()[1]->GetSubGroups().size());

	delete group;
}