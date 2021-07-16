#ifndef DLDL_PRECEDENCE_AST_RELATION_NODEENUMTOTYPE_H
#define DLDL_PRECEDENCE_AST_RELATION_NODEENUMTOTYPE_H

#include "DLDL_PRECEDENCE/Ast/Enum/Type.h"

#include "DLDL_PRECEDENCE/Ast/Node/program.h"
#include "DLDL_PRECEDENCE/Ast/Node/stmts.h"
#include "DLDL_PRECEDENCE/Ast/Node/stmt.h"
#include "DLDL_PRECEDENCE/Ast/Node/localized_precedence.h"
#include "DLDL_PRECEDENCE/Ast/Node/specific_precedence.h"
#include "DLDL_PRECEDENCE/Ast/Node/terminal_one_or_more.h"
#include "DLDL_PRECEDENCE/Ast/Node/PRECEDENCE.h"
#include "DLDL_PRECEDENCE/Ast/Node/NUMBER.h"
#include "DLDL_PRECEDENCE/Ast/Node/TERMINAL.h"
#include "DLDL_PRECEDENCE/Ast/Node/SYMBOLS.h"
#include "DLDL_PRECEDENCE/Ast/Node/ESCAPE_CHARS.h"


namespace DLDL_PRECEDENCE { namespace ast { namespace relation { 

	template<::DLDL_PRECEDENCE::ast::Type T>
	struct NodeEnumToType
	{
		constexpr static auto value = T;
		using type = void;
	};


	template<>
	struct NodeEnumToType<::DLDL_PRECEDENCE::ast::Type::program>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::program;
		using type = ::DLDL_PRECEDENCE::ast::node::program;
	};

	template<>
	struct NodeEnumToType<::DLDL_PRECEDENCE::ast::Type::stmts>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::stmts;
		using type = ::DLDL_PRECEDENCE::ast::node::stmts;
	};

	template<>
	struct NodeEnumToType<::DLDL_PRECEDENCE::ast::Type::stmt>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::stmt;
		using type = ::DLDL_PRECEDENCE::ast::node::stmt;
	};

	template<>
	struct NodeEnumToType<::DLDL_PRECEDENCE::ast::Type::localized_precedence>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::localized_precedence;
		using type = ::DLDL_PRECEDENCE::ast::node::localized_precedence;
	};

	template<>
	struct NodeEnumToType<::DLDL_PRECEDENCE::ast::Type::specific_precedence>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::specific_precedence;
		using type = ::DLDL_PRECEDENCE::ast::node::specific_precedence;
	};

	template<>
	struct NodeEnumToType<::DLDL_PRECEDENCE::ast::Type::terminal_one_or_more>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::terminal_one_or_more;
		using type = ::DLDL_PRECEDENCE::ast::node::terminal_one_or_more;
	};

	template<>
	struct NodeEnumToType<::DLDL_PRECEDENCE::ast::Type::PRECEDENCE>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::PRECEDENCE;
		using type = ::DLDL_PRECEDENCE::ast::node::PRECEDENCE;
	};

	template<>
	struct NodeEnumToType<::DLDL_PRECEDENCE::ast::Type::NUMBER>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::NUMBER;
		using type = ::DLDL_PRECEDENCE::ast::node::NUMBER;
	};

	template<>
	struct NodeEnumToType<::DLDL_PRECEDENCE::ast::Type::TERMINAL>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::TERMINAL;
		using type = ::DLDL_PRECEDENCE::ast::node::TERMINAL;
	};

	template<>
	struct NodeEnumToType<::DLDL_PRECEDENCE::ast::Type::SYMBOLS>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::SYMBOLS;
		using type = ::DLDL_PRECEDENCE::ast::node::SYMBOLS;
	};

	template<>
	struct NodeEnumToType<::DLDL_PRECEDENCE::ast::Type::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS;
	};


template<::DLDL_PRECEDENCE::ast::Type T>
constexpr static auto NodeEnumToType_v = ::DLDL_PRECEDENCE::ast::relation::NodeEnumToType<T>::value;

template<::DLDL_PRECEDENCE::ast::Type T>
using NodeEnumToType_t = typename ::DLDL_PRECEDENCE::ast::relation::NodeEnumToType<T>::type;

}}}

#endif // DLDL_PRECEDENCE_AST_RELATION_NODEENUMTOTYPE_H