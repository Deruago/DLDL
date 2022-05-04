#ifndef DLDL_OOPSYNTAX_AST_RELATION_NODEENUMTOTYPE_H
#define DLDL_OOPSYNTAX_AST_RELATION_NODEENUMTOTYPE_H

#include "DLDL_OOPSYNTAX/Ast/Enum/Type.h"

#include "DLDL_OOPSYNTAX/Ast/Node/program.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_OOPSYNTAX/Ast/Node/stmt.h"
#include "DLDL_OOPSYNTAX/Ast/Node/nonterminal_conversion.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_star__production_rule_conversion__.h"
#include "DLDL_OOPSYNTAX/Ast/Node/production_rule_conversion.h"
#include "DLDL_OOPSYNTAX/Ast/Node/numbered_pr_convert.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_star__property_assignment__.h"
#include "DLDL_OOPSYNTAX/Ast/Node/property_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/direct_property_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/direct_any_property_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/embedded_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/nonterminal_name.h"
#include "DLDL_OOPSYNTAX/Ast/Node/oop_type.h"
#include "DLDL_OOPSYNTAX/Ast/Node/property.h"
#include "DLDL_OOPSYNTAX/Ast/Node/terminal_name.h"
#include "DLDL_OOPSYNTAX/Ast/Node/ARROW.h"
#include "DLDL_OOPSYNTAX/Ast/Node/LEFT_BRACKET.h"
#include "DLDL_OOPSYNTAX/Ast/Node/RIGHT_BRACKET.h"
#include "DLDL_OOPSYNTAX/Ast/Node/DOT.h"
#include "DLDL_OOPSYNTAX/Ast/Node/EQ.h"
#include "DLDL_OOPSYNTAX/Ast/Node/STAR.h"
#include "DLDL_OOPSYNTAX/Ast/Node/VARNAME.h"
#include "DLDL_OOPSYNTAX/Ast/Node/NUMBER.h"
#include "DLDL_OOPSYNTAX/Ast/Node/COMMENT.h"
#include "DLDL_OOPSYNTAX/Ast/Node/ESCAPE_CHAR.h"


namespace DLDL_OOPSYNTAX { namespace ast { namespace relation { 

	template<::DLDL_OOPSYNTAX::ast::Type T>
	struct NodeEnumToType
	{
		constexpr static auto value = T;
		using type = void;
	};


	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::program>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::program;
		using type = ::DLDL_OOPSYNTAX::ast::node::program;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__stmt__>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__stmt__;
		using type = ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::stmt>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::stmt;
		using type = ::DLDL_OOPSYNTAX::ast::node::stmt;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::nonterminal_conversion>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::nonterminal_conversion;
		using type = ::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__production_rule_conversion__>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__production_rule_conversion__;
		using type = ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__production_rule_conversion__;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::production_rule_conversion>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::production_rule_conversion;
		using type = ::DLDL_OOPSYNTAX::ast::node::production_rule_conversion;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::numbered_pr_convert>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::numbered_pr_convert;
		using type = ::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__property_assignment__>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__property_assignment__;
		using type = ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__property_assignment__;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::property_assignment>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::property_assignment;
		using type = ::DLDL_OOPSYNTAX::ast::node::property_assignment;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::direct_property_assignment>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::direct_property_assignment;
		using type = ::DLDL_OOPSYNTAX::ast::node::direct_property_assignment;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::direct_any_property_assignment>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::direct_any_property_assignment;
		using type = ::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::embedded_assignment>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::embedded_assignment;
		using type = ::DLDL_OOPSYNTAX::ast::node::embedded_assignment;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::nonterminal_name>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::nonterminal_name;
		using type = ::DLDL_OOPSYNTAX::ast::node::nonterminal_name;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::oop_type>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::oop_type;
		using type = ::DLDL_OOPSYNTAX::ast::node::oop_type;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::property>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::property;
		using type = ::DLDL_OOPSYNTAX::ast::node::property;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::terminal_name>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::terminal_name;
		using type = ::DLDL_OOPSYNTAX::ast::node::terminal_name;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::ARROW>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::ARROW;
		using type = ::DLDL_OOPSYNTAX::ast::node::ARROW;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::LEFT_BRACKET>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::LEFT_BRACKET;
		using type = ::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::RIGHT_BRACKET>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::RIGHT_BRACKET;
		using type = ::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::DOT>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::DOT;
		using type = ::DLDL_OOPSYNTAX::ast::node::DOT;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::EQ>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::EQ;
		using type = ::DLDL_OOPSYNTAX::ast::node::EQ;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::STAR>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::STAR;
		using type = ::DLDL_OOPSYNTAX::ast::node::STAR;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::VARNAME>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::VARNAME;
		using type = ::DLDL_OOPSYNTAX::ast::node::VARNAME;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::NUMBER>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::NUMBER;
		using type = ::DLDL_OOPSYNTAX::ast::node::NUMBER;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::COMMENT>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::COMMENT;
		using type = ::DLDL_OOPSYNTAX::ast::node::COMMENT;
	};

	template<>
	struct NodeEnumToType<::DLDL_OOPSYNTAX::ast::Type::ESCAPE_CHAR>
	{
		constexpr static auto value = ::DLDL_OOPSYNTAX::ast::Type::ESCAPE_CHAR;
		using type = ::DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR;
	};


template<::DLDL_OOPSYNTAX::ast::Type T>
constexpr static auto NodeEnumToType_v = ::DLDL_OOPSYNTAX::ast::relation::NodeEnumToType<T>::value;

template<::DLDL_OOPSYNTAX::ast::Type T>
using NodeEnumToType_t = typename ::DLDL_OOPSYNTAX::ast::relation::NodeEnumToType<T>::type;

}}}

#endif // DLDL_OOPSYNTAX_AST_RELATION_NODEENUMTOTYPE_H