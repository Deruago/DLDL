#ifndef DLDL_VALUE_AST_RELATION_NODETYPETOENUM_H
#define DLDL_VALUE_AST_RELATION_NODETYPETOENUM_H

#include "DLDL_VALUE/Ast/Enum/Type.h"

namespace DLDL_VALUE { namespace ast { namespace node {

class program;
class deamerreserved_star__stmt__;
class stmt;
class value_charactersitic_declaration;
class deamerreserved_long_82;
class deamerreserved_long_85;
class deamerreserved_long_88;
class value_declaration;
class deamerreserved_long_91;
class value_characteristic_abstraction;
class value_declaration_abstraction;
class value_abstraction;
class deamerreserved_star__value_abstraction__;
class deamerreserved_long_96;
class value;
class syntactic_context;
class abstraction_name;
class value_rule_name;
class SINGLE_COMMENT;
class MULTI_COMMENT;
class LEFT_PARANTHESIS;
class RIGHT_PARANTHESIS;
class LEFT_BRACKET;
class RIGHT_BRACKET;
class LEFT_SQUARE_BRACKET;
class RIGHT_SQUARE_BRACKET;
class DOT;
class VALUE_CHARACTERISTIC;
class VALUE_RULE;
class NUMBER;
class TEXT;
class VARNAME;
class ESCAPE_CHARS;

}}}

namespace DLDL_VALUE { namespace ast { namespace relation { 

	template<typename T>
	struct NodeTypeToEnum
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::deamerreserved_unknown;
		using type = void;
	};


	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::program>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::program;
		using type = ::DLDL_VALUE::ast::node::program;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::deamerreserved_star__stmt__>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::deamerreserved_star__stmt__;
		using type = ::DLDL_VALUE::ast::node::deamerreserved_star__stmt__;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::stmt>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::stmt;
		using type = ::DLDL_VALUE::ast::node::stmt;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::value_charactersitic_declaration>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::value_charactersitic_declaration;
		using type = ::DLDL_VALUE::ast::node::value_charactersitic_declaration;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::deamerreserved_long_82>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::deamerreserved_long_82;
		using type = ::DLDL_VALUE::ast::node::deamerreserved_long_82;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::deamerreserved_long_85>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::deamerreserved_long_85;
		using type = ::DLDL_VALUE::ast::node::deamerreserved_long_85;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::deamerreserved_long_88>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::deamerreserved_long_88;
		using type = ::DLDL_VALUE::ast::node::deamerreserved_long_88;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::value_declaration>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::value_declaration;
		using type = ::DLDL_VALUE::ast::node::value_declaration;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::deamerreserved_long_91>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::deamerreserved_long_91;
		using type = ::DLDL_VALUE::ast::node::deamerreserved_long_91;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::value_characteristic_abstraction>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::value_characteristic_abstraction;
		using type = ::DLDL_VALUE::ast::node::value_characteristic_abstraction;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::value_declaration_abstraction>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::value_declaration_abstraction;
		using type = ::DLDL_VALUE::ast::node::value_declaration_abstraction;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::value_abstraction>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::value_abstraction;
		using type = ::DLDL_VALUE::ast::node::value_abstraction;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::deamerreserved_star__value_abstraction__;
		using type = ::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::deamerreserved_long_96>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::deamerreserved_long_96;
		using type = ::DLDL_VALUE::ast::node::deamerreserved_long_96;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::value>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::value;
		using type = ::DLDL_VALUE::ast::node::value;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::syntactic_context>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::syntactic_context;
		using type = ::DLDL_VALUE::ast::node::syntactic_context;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::abstraction_name>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::abstraction_name;
		using type = ::DLDL_VALUE::ast::node::abstraction_name;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::value_rule_name>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::value_rule_name;
		using type = ::DLDL_VALUE::ast::node::value_rule_name;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::SINGLE_COMMENT>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::SINGLE_COMMENT;
		using type = ::DLDL_VALUE::ast::node::SINGLE_COMMENT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::MULTI_COMMENT>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::MULTI_COMMENT;
		using type = ::DLDL_VALUE::ast::node::MULTI_COMMENT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::LEFT_PARANTHESIS>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::LEFT_PARANTHESIS;
		using type = ::DLDL_VALUE::ast::node::LEFT_PARANTHESIS;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::RIGHT_PARANTHESIS;
		using type = ::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::LEFT_BRACKET>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::LEFT_BRACKET;
		using type = ::DLDL_VALUE::ast::node::LEFT_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::RIGHT_BRACKET>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::RIGHT_BRACKET;
		using type = ::DLDL_VALUE::ast::node::RIGHT_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::LEFT_SQUARE_BRACKET;
		using type = ::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::RIGHT_SQUARE_BRACKET;
		using type = ::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::DOT>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::DOT;
		using type = ::DLDL_VALUE::ast::node::DOT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::VALUE_CHARACTERISTIC;
		using type = ::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::VALUE_RULE>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::VALUE_RULE;
		using type = ::DLDL_VALUE::ast::node::VALUE_RULE;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::NUMBER>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::NUMBER;
		using type = ::DLDL_VALUE::ast::node::NUMBER;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::TEXT>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::TEXT;
		using type = ::DLDL_VALUE::ast::node::TEXT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::VARNAME>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::VARNAME;
		using type = ::DLDL_VALUE::ast::node::VARNAME;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_VALUE::ast::node::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_VALUE::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_VALUE::ast::node::ESCAPE_CHARS;
	};


template<typename T>
constexpr static auto NodeTypeToEnum_v = ::DLDL_VALUE::ast::relation::NodeTypeToEnum<T>::value;

template<typename T>
using NodeTypeToEnum_t = typename ::DLDL_VALUE::ast::relation::NodeTypeToEnum<T>::type;

}}}

#endif // DLDL_VALUE_AST_RELATION_NODETYPETOENUM_H