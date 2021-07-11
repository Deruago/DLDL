#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Enum/Type.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Listener/EnterExitListener.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Bison/Parser.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Return;
using namespace DLDL_GRAMMAR_PRODUCTION_RULE::ast::listener;

class TestProductionRuleParser : public testing::Test
{
public:
protected:
	TestProductionRuleParser() = default;

	virtual ~TestProductionRuleParser() = default;

public:
};

class StatementListener : public EnterExitListener
{
public:
	void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group* node)
	{
		if (node->Get(static_cast<::std::size_t>(0))->GetType() ==
			static_cast<::std::size_t>(::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VALUE))
		{
			StatementValue(node->GetChildValue(::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VALUE));
		}
	}

	void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group* node)
	{
		if (node->Get(static_cast<::std::size_t>(0))->GetType() ==
			static_cast<::std::size_t>(::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group))
		{
			const auto* group = node->GetObject(::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group);

			if (group->Get(static_cast<::std::size_t>(0))->GetType() !=
				static_cast<::std::size_t>(::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VALUE))
			{
				return;
			}

			OptionalStatementValue(
				group->GetChildValue(::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VALUE));
		}
		else
		{
			const auto* group = node->GetObject(::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmts)
									->Get(static_cast<::std::size_t>(0))
									->Get(static_cast<::std::size_t>(0));

			if (group->Get(static_cast<::std::size_t>(0))->GetType() !=
				static_cast<::std::size_t>(::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VALUE))
			{
				return;
			}

			OptionalStatementValue(
				group->GetChildValue(::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VALUE));
		}
	}

	virtual std::string StatementValue(std::string text)
	{
		return text;
	}

	virtual std::string OptionalStatementValue(std::string text)
	{
		return text;
	}
};

class MockStatementListener : public StatementListener
{
public:
	MOCK_METHOD(std::string, StatementValue, (std::string text), (override));
	MOCK_METHOD(std::string, OptionalStatementValue, (std::string text), (override));
};

TEST_F(TestProductionRuleParser,
	   ParseBNF_ShouldCorrectlyGiveTheVariousTerminalsAndNonterminalsInProductionRule)
{
	auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "function_type VARNAME LEFT_PARAN arguments RIGHT_PARAN";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	auto startNode = result->GetStartNode();

	MockStatementListener mockStatementListener;

	EXPECT_CALL(mockStatementListener, StatementValue("RIGHT_PARAN"));
	EXPECT_CALL(mockStatementListener, StatementValue("arguments"));
	EXPECT_CALL(mockStatementListener, StatementValue("LEFT_PARAN"));
	EXPECT_CALL(mockStatementListener, StatementValue("VARNAME"));
	EXPECT_CALL(mockStatementListener, StatementValue("function_type"));

	mockStatementListener.Dispatch(startNode);
}

TEST_F(TestProductionRuleParser, ParseEBNF_OptionalGroup_ShouldCorrectlyGiveTheOptionalGroup)
{
	auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "[function_type] VARNAME [LEFT_PARAN] arguments? [RIGHT_PARAN]?";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	auto startNode = result->GetStartNode();

	MockStatementListener mockStatementListener;

	EXPECT_CALL(mockStatementListener, StatementValue("RIGHT_PARAN"));
	EXPECT_CALL(mockStatementListener, StatementValue("arguments"));
	EXPECT_CALL(mockStatementListener, StatementValue("LEFT_PARAN"));
	EXPECT_CALL(mockStatementListener, StatementValue("VARNAME"));
	EXPECT_CALL(mockStatementListener, StatementValue("function_type"));

	EXPECT_CALL(mockStatementListener, OptionalStatementValue("RIGHT_PARAN"));
	EXPECT_CALL(mockStatementListener, OptionalStatementValue("arguments"));
	EXPECT_CALL(mockStatementListener, OptionalStatementValue("LEFT_PARAN"));
	EXPECT_CALL(mockStatementListener, OptionalStatementValue("function_type"));

	mockStatementListener.Dispatch(startNode);
}

TEST_F(
	TestProductionRuleParser,
	ParseBNFWithSpacesInFront_ShouldCorrectlyGiveTheVariousTerminalsAndNonterminalsInProductionRule)
{
	auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text =
		"                   function_type VARNAME LEFT_PARAN arguments RIGHT_PARAN";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	auto startNode = result->GetStartNode();

	MockStatementListener mockStatementListener;

	EXPECT_CALL(mockStatementListener, StatementValue("RIGHT_PARAN"));
	EXPECT_CALL(mockStatementListener, StatementValue("arguments"));
	EXPECT_CALL(mockStatementListener, StatementValue("LEFT_PARAN"));
	EXPECT_CALL(mockStatementListener, StatementValue("VARNAME"));
	EXPECT_CALL(mockStatementListener, StatementValue("function_type"));

	mockStatementListener.Dispatch(startNode);
}

TEST_F(
	TestProductionRuleParser,
	ParseBNFWithTabsInFront_ShouldCorrectlyGiveTheVariousTerminalsAndNonterminalsInProductionRule)
{
	auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text = "				function_type VARNAME LEFT_PARAN arguments RIGHT_PARAN";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	auto startNode = result->GetStartNode();

	MockStatementListener mockStatementListener;

	EXPECT_CALL(mockStatementListener, StatementValue("RIGHT_PARAN"));
	EXPECT_CALL(mockStatementListener, StatementValue("arguments"));
	EXPECT_CALL(mockStatementListener, StatementValue("LEFT_PARAN"));
	EXPECT_CALL(mockStatementListener, StatementValue("VARNAME"));
	EXPECT_CALL(mockStatementListener, StatementValue("function_type"));

	mockStatementListener.Dispatch(startNode);
}

TEST_F(
	TestProductionRuleParser,
	ParseBNFWithSpacesAndTabsInFront_ShouldCorrectlyGiveTheVariousTerminalsAndNonterminalsInProductionRule)
{
	auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text =
		"						  function_type VARNAME LEFT_PARAN arguments RIGHT_PARAN";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	auto startNode = result->GetStartNode();

	MockStatementListener mockStatementListener;

	EXPECT_CALL(mockStatementListener, StatementValue("RIGHT_PARAN"));
	EXPECT_CALL(mockStatementListener, StatementValue("arguments"));
	EXPECT_CALL(mockStatementListener, StatementValue("LEFT_PARAN"));
	EXPECT_CALL(mockStatementListener, StatementValue("VARNAME"));
	EXPECT_CALL(mockStatementListener, StatementValue("function_type"));

	mockStatementListener.Dispatch(startNode);
}

TEST_F(
	TestProductionRuleParser,
	ParseBNFWithTabsAndSpacesInBetween_ShouldCorrectlyGiveTheVariousTerminalsAndNonterminalsInProductionRule)
{
	auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text =
		"function_type VARNAME		LEFT_PARAN  arguments			"
		"RIGHT_PARAN";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	auto startNode = result->GetStartNode();

	MockStatementListener mockStatementListener;

	EXPECT_CALL(mockStatementListener, StatementValue("RIGHT_PARAN"));
	EXPECT_CALL(mockStatementListener, StatementValue("arguments"));
	EXPECT_CALL(mockStatementListener, StatementValue("LEFT_PARAN"));
	EXPECT_CALL(mockStatementListener, StatementValue("VARNAME"));
	EXPECT_CALL(mockStatementListener, StatementValue("function_type"));

	mockStatementListener.Dispatch(startNode);
}

TEST_F(
	TestProductionRuleParser,
	ParseBNFWithSpacesAndTabsAfter_ShouldCorrectlyGiveTheVariousTerminalsAndNonterminalsInProductionRule)
{
	auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::parser::Parser();
	constexpr auto text =
		"function_type VARNAME LEFT_PARAN arguments RIGHT_PARAN								";
	auto* const result = parser.Parse(text);

	ASSERT_TRUE(result != nullptr);
	auto startNode = result->GetStartNode();

	MockStatementListener mockStatementListener;

	EXPECT_CALL(mockStatementListener, StatementValue("RIGHT_PARAN"));
	EXPECT_CALL(mockStatementListener, StatementValue("arguments"));
	EXPECT_CALL(mockStatementListener, StatementValue("LEFT_PARAN"));
	EXPECT_CALL(mockStatementListener, StatementValue("VARNAME"));
	EXPECT_CALL(mockStatementListener, StatementValue("function_type"));

	mockStatementListener.Dispatch(startNode);
}
