#ifndef DLDL_LPDDEF_EF_AST_ENUM_TYPE_H
#define DLDL_LPDDEF_EF_AST_ENUM_TYPE_H

#include <cstddef>

namespace DLDL_LPDDEF_EF { namespace ast { 

	enum class Type : std::size_t
	{
		// Reserved
		deamerreserved_unknown,

		// Terminal
		COMMENT,
		VARNAME,
		NUMBER,
		COLON,
		SEMICOLON,
		ESCAPE_CHARS,


		// NonTerminal
		program,
		deamerreserved_star__stmt__,
		stmt,
		comment_line,
		standard_variant,
		standard_variant_specific_number,
		value,
		enum_name,

	};

	static inline bool operator==(std::size_t lhs, ::DLDL_LPDDEF_EF::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_LPDDEF_EF::ast::Type lhs, std::size_t rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}

	static inline bool operator==(int lhs, ::DLDL_LPDDEF_EF::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_LPDDEF_EF::ast::Type lhs, int rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}
}}

#endif // DLDL_LPDDEF_EF_AST_ENUM_TYPE_H