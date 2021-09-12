#ifndef DLDL_PRECEDENCE_AST_RELATION_NODETYPETOENUM_H
#define DLDL_PRECEDENCE_AST_RELATION_NODETYPETOENUM_H

#include "DLDL_PRECEDENCE/Ast/Enum/Type.h"

namespace DLDL_PRECEDENCE { namespace ast { namespace node {

class program;
class stmts;
class stmt;
class localized_precedence;
class specific_precedence;
class terminal_one_or_more;
class PRECEDENCE;
class NUMBER;
class TERMINAL;
class SYMBOLS;
class ESCAPE_CHARS;

}}}

namespace DLDL_PRECEDENCE { namespace ast { namespace relation { 

	template<typename T>
	struct NodeTypeToEnum
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::deamerreserved_unknown;
		using type = void;
	};


	template<>
	struct NodeTypeToEnum<::DLDL_PRECEDENCE::ast::node::program>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::program;
		using type = ::DLDL_PRECEDENCE::ast::node::program;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_PRECEDENCE::ast::node::stmts>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::stmts;
		using type = ::DLDL_PRECEDENCE::ast::node::stmts;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_PRECEDENCE::ast::node::stmt>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::stmt;
		using type = ::DLDL_PRECEDENCE::ast::node::stmt;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_PRECEDENCE::ast::node::localized_precedence>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::localized_precedence;
		using type = ::DLDL_PRECEDENCE::ast::node::localized_precedence;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_PRECEDENCE::ast::node::specific_precedence>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::specific_precedence;
		using type = ::DLDL_PRECEDENCE::ast::node::specific_precedence;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_PRECEDENCE::ast::node::terminal_one_or_more>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::terminal_one_or_more;
		using type = ::DLDL_PRECEDENCE::ast::node::terminal_one_or_more;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_PRECEDENCE::ast::node::PRECEDENCE>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::PRECEDENCE;
		using type = ::DLDL_PRECEDENCE::ast::node::PRECEDENCE;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_PRECEDENCE::ast::node::NUMBER>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::NUMBER;
		using type = ::DLDL_PRECEDENCE::ast::node::NUMBER;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_PRECEDENCE::ast::node::TERMINAL>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::TERMINAL;
		using type = ::DLDL_PRECEDENCE::ast::node::TERMINAL;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_PRECEDENCE::ast::node::SYMBOLS>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::SYMBOLS;
		using type = ::DLDL_PRECEDENCE::ast::node::SYMBOLS;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_PRECEDENCE::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS;
	};


template<typename T>
constexpr static auto NodeTypeToEnum_v = ::DLDL_PRECEDENCE::ast::relation::NodeTypeToEnum<T>::value;

template<typename T>
using NodeTypeToEnum_t = typename ::DLDL_PRECEDENCE::ast::relation::NodeTypeToEnum<T>::type;

}}}

#endif // DLDL_PRECEDENCE_AST_RELATION_NODETYPETOENUM_H