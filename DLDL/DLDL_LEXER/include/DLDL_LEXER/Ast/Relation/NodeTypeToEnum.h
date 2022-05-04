#ifndef DLDL_LEXER_AST_RELATION_NODETYPETOENUM_H
#define DLDL_LEXER_AST_RELATION_NODETYPETOENUM_H

#include "DLDL_LEXER/Ast/Enum/Type.h"

namespace DLDL_LEXER { namespace ast { namespace node {

class program;
class stmts;
class stmt;
class tokendeclaration;
class abstraction;
class DELETE_ABSTRACTION;
class IGNORE_ABSTRACTION;
class NOVALUE_ABSTRACTION;
class CRASH_ABSTRACTION;
class STANDARD_ABSTRACTION;
class UNKNOWN_ABSTRACTION;
class TERMINAL;
class REGEX;
class ESCAPE_CHARS;
class COMMENT;

}}}

namespace DLDL_LEXER { namespace ast { namespace relation { 

	template<typename T>
	struct NodeTypeToEnum
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::deamerreserved_unknown;
		using type = void;
	};


	template<>
	struct NodeTypeToEnum<::DLDL_LEXER::ast::node::program>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::program;
		using type = ::DLDL_LEXER::ast::node::program;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LEXER::ast::node::stmts>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::stmts;
		using type = ::DLDL_LEXER::ast::node::stmts;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LEXER::ast::node::stmt>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::stmt;
		using type = ::DLDL_LEXER::ast::node::stmt;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LEXER::ast::node::tokendeclaration>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::tokendeclaration;
		using type = ::DLDL_LEXER::ast::node::tokendeclaration;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LEXER::ast::node::abstraction>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::abstraction;
		using type = ::DLDL_LEXER::ast::node::abstraction;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LEXER::ast::node::DELETE_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::DELETE_ABSTRACTION;
		using type = ::DLDL_LEXER::ast::node::DELETE_ABSTRACTION;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LEXER::ast::node::IGNORE_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::IGNORE_ABSTRACTION;
		using type = ::DLDL_LEXER::ast::node::IGNORE_ABSTRACTION;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::NOVALUE_ABSTRACTION;
		using type = ::DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LEXER::ast::node::CRASH_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::CRASH_ABSTRACTION;
		using type = ::DLDL_LEXER::ast::node::CRASH_ABSTRACTION;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LEXER::ast::node::STANDARD_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::STANDARD_ABSTRACTION;
		using type = ::DLDL_LEXER::ast::node::STANDARD_ABSTRACTION;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::UNKNOWN_ABSTRACTION;
		using type = ::DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LEXER::ast::node::TERMINAL>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::TERMINAL;
		using type = ::DLDL_LEXER::ast::node::TERMINAL;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LEXER::ast::node::REGEX>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::REGEX;
		using type = ::DLDL_LEXER::ast::node::REGEX;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LEXER::ast::node::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_LEXER::ast::node::ESCAPE_CHARS;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LEXER::ast::node::COMMENT>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::COMMENT;
		using type = ::DLDL_LEXER::ast::node::COMMENT;
	};


template<typename T>
constexpr static auto NodeTypeToEnum_v = ::DLDL_LEXER::ast::relation::NodeTypeToEnum<T>::value;

template<typename T>
using NodeTypeToEnum_t = typename ::DLDL_LEXER::ast::relation::NodeTypeToEnum<T>::type;

}}}

#endif // DLDL_LEXER_AST_RELATION_NODETYPETOENUM_H