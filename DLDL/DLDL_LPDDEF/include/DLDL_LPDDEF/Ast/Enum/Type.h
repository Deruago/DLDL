#ifndef DLDL_LPDDEF_AST_ENUM_TYPE_H
#define DLDL_LPDDEF_AST_ENUM_TYPE_H

#include <cstddef>

namespace DLDL_LPDDEF { namespace ast { 

	enum class Type : std::size_t
	{
		// Reserved
		deamerreserved_unknown,

		// Terminal
		COLON,
		LEFT_ANGLE_BRACKET,
		RIGHT_ANGLE_BRACKET,
		VARNAME,
		INDENTED_VALUE,
		ESCAPE_CHARS,


		// NonTerminal
		program,
		deamerreserved_star__stmt__,
		stmt,
		argument,
		argument_name,
		argument_block,
		deamerreserved_star__argument_stmt__,
		argument_stmt,

	};

	static inline bool operator==(std::size_t lhs, ::DLDL_LPDDEF::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_LPDDEF::ast::Type lhs, std::size_t rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}

	static inline bool operator==(int lhs, ::DLDL_LPDDEF::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_LPDDEF::ast::Type lhs, int rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}
}}

#endif // DLDL_LPDDEF_AST_ENUM_TYPE_H