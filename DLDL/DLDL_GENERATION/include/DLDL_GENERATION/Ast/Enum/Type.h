#ifndef DLDL_GENERATION_AST_ENUM_TYPE_H
#define DLDL_GENERATION_AST_ENUM_TYPE_H

#include <cstddef>

namespace DLDL_GENERATION { namespace ast { 

	enum class Type : std::size_t
	{
		// Reserved
		deamerreserved_unknown,

		// Terminal
		GENERATE,
		INTEGRATE,
		ARGUMENT,
		VALUE,
		SYMBOLS,
		ESCAPE_CHARS,


		// NonTerminal
		program,
		stmts,
		stmt,
		generate_declaration,
		integrate_declaration,
		argument_declaration,
		type,
		tool,
		argument_data,

	};

	static inline bool operator==(std::size_t lhs, ::DLDL_GENERATION::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_GENERATION::ast::Type lhs, std::size_t rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}

	static inline bool operator==(int lhs, ::DLDL_GENERATION::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_GENERATION::ast::Type lhs, int rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}
}}

#endif // DLDL_GENERATION_AST_ENUM_TYPE_H