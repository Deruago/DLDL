#ifndef DLDL_PRECEDENCE_AST_ENUM_TYPE_H
#define DLDL_PRECEDENCE_AST_ENUM_TYPE_H

#include <cstddef>

namespace DLDL_PRECEDENCE { namespace ast { 

	enum class Type : std::size_t
	{
		// Reserved
		deamerreserved_unknown,

		// Terminal
		PRECEDENCE,
		NUMBER,
		TERMINAL,
		SYMBOLS,
		ESCAPE_CHARS,


		// NonTerminal
		program,
		stmts,
		stmt,
		localized_precedence,
		specific_precedence,
		terminal_one_or_more,

	};

	static inline bool operator==(std::size_t lhs, ::DLDL_PRECEDENCE::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_PRECEDENCE::ast::Type lhs, std::size_t rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}

	static inline bool operator==(int lhs, ::DLDL_PRECEDENCE::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_PRECEDENCE::ast::Type lhs, int rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}
}}

#endif // DLDL_PRECEDENCE_AST_ENUM_TYPE_H