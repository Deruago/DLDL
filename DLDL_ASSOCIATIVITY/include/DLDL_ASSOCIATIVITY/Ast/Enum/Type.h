#ifndef DLDL_ASSOCIATIVITY_AST_ENUM_TYPE_H
#define DLDL_ASSOCIATIVITY_AST_ENUM_TYPE_H

#include <cstddef>

namespace DLDL_ASSOCIATIVITY { namespace ast { 

	enum class Type : std::size_t
	{
		// Reserved
		deamerreserved_unknown,

		// Terminal
		ASSOCIATIVITY,


		// NonTerminal
		program,
		stmts,
		stmt,

	};

	static inline bool operator==(std::size_t lhs, ::DLDL_ASSOCIATIVITY::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_ASSOCIATIVITY::ast::Type lhs, std::size_t rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}

	static inline bool operator==(int lhs, ::DLDL_ASSOCIATIVITY::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_ASSOCIATIVITY::ast::Type lhs, int rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}
}}

#endif // DLDL_ASSOCIATIVITY_AST_ENUM_TYPE_H