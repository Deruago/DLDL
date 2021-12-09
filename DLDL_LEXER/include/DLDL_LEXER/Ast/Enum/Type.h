#ifndef DLDL_LEXER_AST_ENUM_TYPE_H
#define DLDL_LEXER_AST_ENUM_TYPE_H

#include <cstddef>

namespace DLDL_LEXER { namespace ast { 

	enum class Type : std::size_t
	{
		// Reserved
		deamerreserved_unknown,

		// Terminal
		DELETE_ABSTRACTION,
		IGNORE_ABSTRACTION,
		NOVALUE_ABSTRACTION,
		CRASH_ABSTRACTION,
		STANDARD_ABSTRACTION,
		UNKNOWN_ABSTRACTION,
		TERMINAL,
		REGEX,
		ESCAPE_CHARS,
		COMMENT,


		// NonTerminal
		program,
		stmts,
		stmt,
		tokendeclaration,
		abstraction,

	};

	static inline bool operator==(std::size_t lhs, ::DLDL_LEXER::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_LEXER::ast::Type lhs, std::size_t rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}

	static inline bool operator==(int lhs, ::DLDL_LEXER::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_LEXER::ast::Type lhs, int rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}
}}

#endif // DLDL_LEXER_AST_ENUM_TYPE_H