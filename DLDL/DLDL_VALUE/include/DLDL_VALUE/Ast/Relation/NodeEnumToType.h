#ifndef DLDL_VALUE_AST_RELATION_NODEENUMTOTYPE_H
#define DLDL_VALUE_AST_RELATION_NODEENUMTOTYPE_H

#include "DLDL_VALUE/Ast/Enum/Type.h"

#include "DLDL_VALUE/Ast/Node/program.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_VALUE/Ast/Node/stmt.h"
#include "DLDL_VALUE/Ast/Node/value_charactersitic_declaration.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_82.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_85.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_88.h"
#include "DLDL_VALUE/Ast/Node/value_declaration.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_91.h"
#include "DLDL_VALUE/Ast/Node/value_characteristic_abstraction.h"
#include "DLDL_VALUE/Ast/Node/value_declaration_abstraction.h"
#include "DLDL_VALUE/Ast/Node/value_abstraction.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_star__value_abstraction__.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_96.h"
#include "DLDL_VALUE/Ast/Node/value.h"
#include "DLDL_VALUE/Ast/Node/syntactic_context.h"
#include "DLDL_VALUE/Ast/Node/abstraction_name.h"
#include "DLDL_VALUE/Ast/Node/value_rule_name.h"
#include "DLDL_VALUE/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_VALUE/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_VALUE/Ast/Node/LEFT_PARANTHESIS.h"
#include "DLDL_VALUE/Ast/Node/RIGHT_PARANTHESIS.h"
#include "DLDL_VALUE/Ast/Node/LEFT_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/RIGHT_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/DOT.h"
#include "DLDL_VALUE/Ast/Node/VALUE_CHARACTERISTIC.h"
#include "DLDL_VALUE/Ast/Node/VALUE_RULE.h"
#include "DLDL_VALUE/Ast/Node/NUMBER.h"
#include "DLDL_VALUE/Ast/Node/TEXT.h"
#include "DLDL_VALUE/Ast/Node/VARNAME.h"
#include "DLDL_VALUE/Ast/Node/ESCAPE_CHARS.h"


namespace DLDL_VALUE { namespace ast { namespace relation { 

	template<::DLDL_VALUE::ast::Type T>
	struct NodeEnumToType
	{
		constexpr static auto value = T;
		using type = void;
	};


	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::program>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::program;
		using type = ::DLDL_VALUE::ast::node::program;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::deamerreserved_star__stmt__>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::deamerreserved_star__stmt__;
		using type = ::DLDL_VALUE::ast::node::deamerreserved_star__stmt__;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::stmt>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::stmt;
		using type = ::DLDL_VALUE::ast::node::stmt;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::value_charactersitic_declaration>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::value_charactersitic_declaration;
		using type = ::DLDL_VALUE::ast::node::value_charactersitic_declaration;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::deamerreserved_long_82>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::deamerreserved_long_82;
		using type = ::DLDL_VALUE::ast::node::deamerreserved_long_82;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::deamerreserved_long_85>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::deamerreserved_long_85;
		using type = ::DLDL_VALUE::ast::node::deamerreserved_long_85;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::deamerreserved_long_88>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::deamerreserved_long_88;
		using type = ::DLDL_VALUE::ast::node::deamerreserved_long_88;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::value_declaration>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::value_declaration;
		using type = ::DLDL_VALUE::ast::node::value_declaration;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::deamerreserved_long_91>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::deamerreserved_long_91;
		using type = ::DLDL_VALUE::ast::node::deamerreserved_long_91;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::value_characteristic_abstraction>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::value_characteristic_abstraction;
		using type = ::DLDL_VALUE::ast::node::value_characteristic_abstraction;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::value_declaration_abstraction>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::value_declaration_abstraction;
		using type = ::DLDL_VALUE::ast::node::value_declaration_abstraction;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::value_abstraction>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::value_abstraction;
		using type = ::DLDL_VALUE::ast::node::value_abstraction;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::deamerreserved_star__value_abstraction__>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::deamerreserved_star__value_abstraction__;
		using type = ::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::deamerreserved_long_96>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::deamerreserved_long_96;
		using type = ::DLDL_VALUE::ast::node::deamerreserved_long_96;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::value>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::value;
		using type = ::DLDL_VALUE::ast::node::value;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::syntactic_context>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::syntactic_context;
		using type = ::DLDL_VALUE::ast::node::syntactic_context;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::abstraction_name>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::abstraction_name;
		using type = ::DLDL_VALUE::ast::node::abstraction_name;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::value_rule_name>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::value_rule_name;
		using type = ::DLDL_VALUE::ast::node::value_rule_name;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::SINGLE_COMMENT>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::SINGLE_COMMENT;
		using type = ::DLDL_VALUE::ast::node::SINGLE_COMMENT;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::MULTI_COMMENT>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::MULTI_COMMENT;
		using type = ::DLDL_VALUE::ast::node::MULTI_COMMENT;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::LEFT_PARANTHESIS>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::LEFT_PARANTHESIS;
		using type = ::DLDL_VALUE::ast::node::LEFT_PARANTHESIS;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::RIGHT_PARANTHESIS>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::RIGHT_PARANTHESIS;
		using type = ::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::LEFT_BRACKET>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::LEFT_BRACKET;
		using type = ::DLDL_VALUE::ast::node::LEFT_BRACKET;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::RIGHT_BRACKET>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::RIGHT_BRACKET;
		using type = ::DLDL_VALUE::ast::node::RIGHT_BRACKET;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::LEFT_SQUARE_BRACKET>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::LEFT_SQUARE_BRACKET;
		using type = ::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::RIGHT_SQUARE_BRACKET>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::RIGHT_SQUARE_BRACKET;
		using type = ::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::DOT>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::DOT;
		using type = ::DLDL_VALUE::ast::node::DOT;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::VALUE_CHARACTERISTIC>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::VALUE_CHARACTERISTIC;
		using type = ::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::VALUE_RULE>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::VALUE_RULE;
		using type = ::DLDL_VALUE::ast::node::VALUE_RULE;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::NUMBER>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::NUMBER;
		using type = ::DLDL_VALUE::ast::node::NUMBER;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::TEXT>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::TEXT;
		using type = ::DLDL_VALUE::ast::node::TEXT;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::VARNAME>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::VARNAME;
		using type = ::DLDL_VALUE::ast::node::VARNAME;
	};

	template<>
	struct NodeEnumToType<::DLDL_VALUE::ast::Type::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_VALUE::ast::node::ESCAPE_CHARS;
	};


template<::DLDL_VALUE::ast::Type T>
constexpr static auto NodeEnumToType_v = ::DLDL_VALUE::ast::relation::NodeEnumToType<T>::value;

template<::DLDL_VALUE::ast::Type T>
using NodeEnumToType_t = typename ::DLDL_VALUE::ast::relation::NodeEnumToType<T>::type;

}}}

#endif // DLDL_VALUE_AST_RELATION_NODEENUMTOTYPE_H