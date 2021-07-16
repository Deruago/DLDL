#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODEENUMTOTYPE_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODEENUMTOTYPE_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Enum/Type.h"

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/program.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/stmts.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/stmt.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/nested_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/optional_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/zero_or_more_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/one_or_more_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/or_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/min_max_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/extension_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/VERTICAL_SLASH.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_PARANTHESIS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_PARANTHESIS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/QUESTION_MARK.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/EXCLAMATION_MARK.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ARROW.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/STAR.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/PLUS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/MINUS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/VALUE.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/NUMBER.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/SINGLE_LINE_COMMENT.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/MULTI_LINE_COMMENT.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/SYMBOLS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ESCAPE_CHARS.h"


namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace relation { 

	template<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type T>
	struct NodeEnumToType
	{
		constexpr static auto value = T;
		using type = void;
	};


	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::program>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::program;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmts>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmts;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmt>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmt;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::nested_group>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::nested_group;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::optional_group>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::optional_group;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::zero_or_more_group>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::zero_or_more_group;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::one_or_more_group>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::one_or_more_group;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::or_group>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::or_group;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::min_max_group>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::min_max_group;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::extension_group>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::extension_group;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VERTICAL_SLASH>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VERTICAL_SLASH;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_PARANTHESIS>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_PARANTHESIS;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_PARANTHESIS>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_PARANTHESIS;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_BRACKET>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_BRACKET;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_BRACKET>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_BRACKET;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_SQUARE_BRACKET>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_SQUARE_BRACKET;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_SQUARE_BRACKET>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_SQUARE_BRACKET;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::QUESTION_MARK>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::QUESTION_MARK;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::EXCLAMATION_MARK>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::EXCLAMATION_MARK;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ARROW>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ARROW;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::STAR>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::STAR;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::PLUS>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::PLUS;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MINUS>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MINUS;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VALUE>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VALUE;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::NUMBER>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::NUMBER;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SINGLE_LINE_COMMENT>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SINGLE_LINE_COMMENT;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MULTI_LINE_COMMENT>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MULTI_LINE_COMMENT;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SYMBOLS>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SYMBOLS;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS;
	};

	template<>
	struct NodeEnumToType<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS;
	};


template<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type T>
constexpr static auto NodeEnumToType_v = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::relation::NodeEnumToType<T>::value;

template<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type T>
using NodeEnumToType_t = typename ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::relation::NodeEnumToType<T>::type;

}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODEENUMTOTYPE_H