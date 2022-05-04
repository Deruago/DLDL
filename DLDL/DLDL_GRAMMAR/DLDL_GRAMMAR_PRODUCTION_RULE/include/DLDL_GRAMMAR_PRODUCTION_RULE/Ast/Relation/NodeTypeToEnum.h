#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODETYPETOENUM_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODETYPETOENUM_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Enum/Type.h"

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace node {

class program;
class stmts;
class stmt;
class group;
class nested_group;
class optional_group;
class zero_or_more_group;
class one_or_more_group;
class or_group;
class min_max_group;
class extension_group;
class ENDING_USELESS_SYMBOLS;
class VERTICAL_SLASH;
class LEFT_PARANTHESIS;
class RIGHT_PARANTHESIS;
class LEFT_BRACKET;
class RIGHT_BRACKET;
class LEFT_SQUARE_BRACKET;
class RIGHT_SQUARE_BRACKET;
class QUESTION_MARK;
class EXCLAMATION_MARK;
class ARROW;
class STAR;
class PLUS;
class MINUS;
class VALUE;
class NUMBER;
class SINGLE_LINE_COMMENT;
class MULTI_LINE_COMMENT;
class SYMBOLS;
class ESCAPE_CHARS;

}}}

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace relation { 

	template<typename T>
	struct NodeTypeToEnum
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::deamerreserved_unknown;
		using type = void;
	};


	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::program;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmts;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmt;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::nested_group;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::optional_group;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::zero_or_more_group;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::one_or_more_group;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::or_group;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::min_max_group;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::extension_group;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ENDING_USELESS_SYMBOLS;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VERTICAL_SLASH;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_PARANTHESIS;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_PARANTHESIS;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_BRACKET;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_BRACKET;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_SQUARE_BRACKET;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_SQUARE_BRACKET;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::QUESTION_MARK;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::EXCLAMATION_MARK;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ARROW;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::STAR;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::PLUS;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MINUS;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VALUE;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::NUMBER;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SINGLE_LINE_COMMENT;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MULTI_LINE_COMMENT;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SYMBOLS;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS;
	};


template<typename T>
constexpr static auto NodeTypeToEnum_v = ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::relation::NodeTypeToEnum<T>::value;

template<typename T>
using NodeTypeToEnum_t = typename ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::relation::NodeTypeToEnum<T>::type;

}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODETYPETOENUM_H