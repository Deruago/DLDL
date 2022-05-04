#ifndef DLDL_LEXER_AST_RELATION_NODEENUMTOTYPE_H
#define DLDL_LEXER_AST_RELATION_NODEENUMTOTYPE_H

#include "DLDL_LEXER/Ast/Enum/Type.h"

#include "DLDL_LEXER/Ast/Node/program.h"
#include "DLDL_LEXER/Ast/Node/stmts.h"
#include "DLDL_LEXER/Ast/Node/stmt.h"
#include "DLDL_LEXER/Ast/Node/tokendeclaration.h"
#include "DLDL_LEXER/Ast/Node/abstraction.h"
#include "DLDL_LEXER/Ast/Node/DELETE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/IGNORE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/NOVALUE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/CRASH_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/STANDARD_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/UNKNOWN_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/TERMINAL.h"
#include "DLDL_LEXER/Ast/Node/REGEX.h"
#include "DLDL_LEXER/Ast/Node/ESCAPE_CHARS.h"
#include "DLDL_LEXER/Ast/Node/COMMENT.h"


namespace DLDL_LEXER { namespace ast { namespace relation { 

	template<::DLDL_LEXER::ast::Type T>
	struct NodeEnumToType
	{
		constexpr static auto value = T;
		using type = void;
	};


	template<>
	struct NodeEnumToType<::DLDL_LEXER::ast::Type::program>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::program;
		using type = ::DLDL_LEXER::ast::node::program;
	};

	template<>
	struct NodeEnumToType<::DLDL_LEXER::ast::Type::stmts>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::stmts;
		using type = ::DLDL_LEXER::ast::node::stmts;
	};

	template<>
	struct NodeEnumToType<::DLDL_LEXER::ast::Type::stmt>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::stmt;
		using type = ::DLDL_LEXER::ast::node::stmt;
	};

	template<>
	struct NodeEnumToType<::DLDL_LEXER::ast::Type::tokendeclaration>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::tokendeclaration;
		using type = ::DLDL_LEXER::ast::node::tokendeclaration;
	};

	template<>
	struct NodeEnumToType<::DLDL_LEXER::ast::Type::abstraction>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::abstraction;
		using type = ::DLDL_LEXER::ast::node::abstraction;
	};

	template<>
	struct NodeEnumToType<::DLDL_LEXER::ast::Type::DELETE_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::DELETE_ABSTRACTION;
		using type = ::DLDL_LEXER::ast::node::DELETE_ABSTRACTION;
	};

	template<>
	struct NodeEnumToType<::DLDL_LEXER::ast::Type::IGNORE_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::IGNORE_ABSTRACTION;
		using type = ::DLDL_LEXER::ast::node::IGNORE_ABSTRACTION;
	};

	template<>
	struct NodeEnumToType<::DLDL_LEXER::ast::Type::NOVALUE_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::NOVALUE_ABSTRACTION;
		using type = ::DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION;
	};

	template<>
	struct NodeEnumToType<::DLDL_LEXER::ast::Type::CRASH_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::CRASH_ABSTRACTION;
		using type = ::DLDL_LEXER::ast::node::CRASH_ABSTRACTION;
	};

	template<>
	struct NodeEnumToType<::DLDL_LEXER::ast::Type::STANDARD_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::STANDARD_ABSTRACTION;
		using type = ::DLDL_LEXER::ast::node::STANDARD_ABSTRACTION;
	};

	template<>
	struct NodeEnumToType<::DLDL_LEXER::ast::Type::UNKNOWN_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::UNKNOWN_ABSTRACTION;
		using type = ::DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION;
	};

	template<>
	struct NodeEnumToType<::DLDL_LEXER::ast::Type::TERMINAL>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::TERMINAL;
		using type = ::DLDL_LEXER::ast::node::TERMINAL;
	};

	template<>
	struct NodeEnumToType<::DLDL_LEXER::ast::Type::REGEX>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::REGEX;
		using type = ::DLDL_LEXER::ast::node::REGEX;
	};

	template<>
	struct NodeEnumToType<::DLDL_LEXER::ast::Type::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_LEXER::ast::node::ESCAPE_CHARS;
	};

	template<>
	struct NodeEnumToType<::DLDL_LEXER::ast::Type::COMMENT>
	{
		constexpr static auto value = ::DLDL_LEXER::ast::Type::COMMENT;
		using type = ::DLDL_LEXER::ast::node::COMMENT;
	};


template<::DLDL_LEXER::ast::Type T>
constexpr static auto NodeEnumToType_v = ::DLDL_LEXER::ast::relation::NodeEnumToType<T>::value;

template<::DLDL_LEXER::ast::Type T>
using NodeEnumToType_t = typename ::DLDL_LEXER::ast::relation::NodeEnumToType<T>::type;

}}}

#endif // DLDL_LEXER_AST_RELATION_NODEENUMTOTYPE_H