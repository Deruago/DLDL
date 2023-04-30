#ifndef DLDL_IDENTITY_AST_ENUM_TYPE_H
#define DLDL_IDENTITY_AST_ENUM_TYPE_H

#include <cstddef>

namespace DLDL_IDENTITY { namespace ast { 

	enum class Type : std::size_t
	{
		// Reserved
		deamerreserved_unknown,

		// Terminal
		NAME,
		VALUE,
		SYMBOLS,
		ESCAPE_CHARS,


		// NonTerminal
		program,
		stmts,
		stmt,
		name_declaration,

	};

	static inline bool operator==(std::size_t lhs, ::DLDL_IDENTITY::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_IDENTITY::ast::Type lhs, std::size_t rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}

	static inline bool operator==(int lhs, ::DLDL_IDENTITY::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_IDENTITY::ast::Type lhs, int rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}
}}

#endif // DLDL_IDENTITY_AST_ENUM_TYPE_H