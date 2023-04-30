#ifndef DLDL_ARGUMENT_AST_ENUM_TYPE_H
#define DLDL_ARGUMENT_AST_ENUM_TYPE_H

#include <cstddef>

namespace DLDL_ARGUMENT { namespace ast { 

	enum class Type : std::size_t
	{
		// Reserved
		deamerreserved_unknown,

		// Terminal
		SINGLE_COMMENT,
		MULTI_COMMENT,
		TEXT,
		VARNAME,
		ESCAPE_CHARS,


		// NonTerminal
		program,

	};

	static inline bool operator==(std::size_t lhs, ::DLDL_ARGUMENT::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_ARGUMENT::ast::Type lhs, std::size_t rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}

	static inline bool operator==(int lhs, ::DLDL_ARGUMENT::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_ARGUMENT::ast::Type lhs, int rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}
}}

#endif // DLDL_ARGUMENT_AST_ENUM_TYPE_H