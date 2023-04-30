#ifndef DLDL_LPDSTRUCT_AST_ENUM_TYPE_H
#define DLDL_LPDSTRUCT_AST_ENUM_TYPE_H

#include <cstddef>

namespace DLDL_LPDSTRUCT { namespace ast { 

	enum class Type : std::size_t
	{
		// Reserved
		deamerreserved_unknown,

		// Terminal
		COLON,
		LEFT_ANGLE_BRACKET,
		RIGHT_ANGLE_BRACKET,
		VARNAME,
		VARNAME_EXT,
		INDENTED_VALUE,
		ESCAPE_CHARS,


		// NonTerminal
		program,
		deamerreserved_star__stmt__,
		stmt,
		argument,
		argument_name,
		argument_block,
		deamerreserved_long_60,
		deamerreserved_long_63,
		deamerreserved_long_66,

	};

	static inline bool operator==(std::size_t lhs, ::DLDL_LPDSTRUCT::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_LPDSTRUCT::ast::Type lhs, std::size_t rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}

	static inline bool operator==(int lhs, ::DLDL_LPDSTRUCT::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_LPDSTRUCT::ast::Type lhs, int rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}
}}

#endif // DLDL_LPDSTRUCT_AST_ENUM_TYPE_H