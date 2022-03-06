#ifndef DLDL_OOPSYNTAX_AST_RELATION_NODETYPETOENUM_H
#define DLDL_OOPSYNTAX_AST_RELATION_NODETYPETOENUM_H

#include "DLDL_OOPSYNTAX/Ast/Enum/Type.h"

namespace DLDL_OOPSYNTAX { namespace ast { namespace node {

class program;
class deamerreserved_star__stmt__;
class stmt;
class nonterminal_conversion;
class deamerreserved_star__production_rule_conversion__;
class production_rule_conversion;
class numbered_pr_convert;
class deamerreserved_star__property_assignment__;
class property_assignment;
class direct_property_assignment;
class direct_any_property_assignment;
class embedded_assignment;
class nonterminal_name;
class oop_type;
class property;
class terminal_name;
class ARROW;
class LEFT_BRACKET;
class RIGHT_BRACKET;
class DOT;
class EQ;
class STAR;
class VARNAME;
class NUMBER;
class COMMENT;
class ESCAPE_CHAR;

}}}

namespace DLDL_OOPSYNTAX { namespace ast { namespace relation { 

	template<typename T>
	struct NodeTypeToEnum
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_unknown;
		using type = void;
	};


	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::program>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::program;
		using type = ::DLDL_OOPSYNTAX::ast::node::program;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__stmt__;
		using type = ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::stmt>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::stmt;
		using type = ::DLDL_OOPSYNTAX::ast::node::stmt;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::nonterminal_conversion;
		using type = ::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__production_rule_conversion__>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__production_rule_conversion__;
		using type = ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__production_rule_conversion__;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::production_rule_conversion>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::production_rule_conversion;
		using type = ::DLDL_OOPSYNTAX::ast::node::production_rule_conversion;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::numbered_pr_convert;
		using type = ::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__property_assignment__>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__property_assignment__;
		using type = ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__property_assignment__;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::property_assignment>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::property_assignment;
		using type = ::DLDL_OOPSYNTAX::ast::node::property_assignment;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::direct_property_assignment>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::direct_property_assignment;
		using type = ::DLDL_OOPSYNTAX::ast::node::direct_property_assignment;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::direct_any_property_assignment;
		using type = ::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::embedded_assignment>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::embedded_assignment;
		using type = ::DLDL_OOPSYNTAX::ast::node::embedded_assignment;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::nonterminal_name>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::nonterminal_name;
		using type = ::DLDL_OOPSYNTAX::ast::node::nonterminal_name;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::oop_type>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::oop_type;
		using type = ::DLDL_OOPSYNTAX::ast::node::oop_type;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::property>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::property;
		using type = ::DLDL_OOPSYNTAX::ast::node::property;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::terminal_name>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::terminal_name;
		using type = ::DLDL_OOPSYNTAX::ast::node::terminal_name;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::ARROW>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::ARROW;
		using type = ::DLDL_OOPSYNTAX::ast::node::ARROW;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::LEFT_BRACKET;
		using type = ::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::RIGHT_BRACKET;
		using type = ::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::DOT>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::DOT;
		using type = ::DLDL_OOPSYNTAX::ast::node::DOT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::EQ>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::EQ;
		using type = ::DLDL_OOPSYNTAX::ast::node::EQ;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::STAR>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::STAR;
		using type = ::DLDL_OOPSYNTAX::ast::node::STAR;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::VARNAME>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::VARNAME;
		using type = ::DLDL_OOPSYNTAX::ast::node::VARNAME;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::NUMBER>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::NUMBER;
		using type = ::DLDL_OOPSYNTAX::ast::node::NUMBER;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::COMMENT>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::COMMENT;
		using type = ::DLDL_OOPSYNTAX::ast::node::COMMENT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::ESCAPE_CHAR;
		using type = ::DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR;
	};


template<typename T>
constexpr static auto NodeTypeToEnum_v = ::DLDL_OOPSYNTAX::ast::relation::NodeTypeToEnum<T>::value;

template<typename T>
using NodeTypeToEnum_t = typename ::DLDL_OOPSYNTAX::ast::relation::NodeTypeToEnum<T>::type;

}}}

#endif // DLDL_OOPSYNTAX_AST_RELATION_NODETYPETOENUM_H