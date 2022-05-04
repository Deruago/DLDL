#ifndef DLDL_LPDDEF_DF_AST_ENUM_TYPE_H
#define DLDL_LPDDEF_DF_AST_ENUM_TYPE_H

#include <cstddef>

namespace DLDL_LPDDEF_DF { namespace ast { 

	enum class Type : std::size_t
	{
		// Reserved
		deamerreserved_unknown,

		// Terminal
		LAB,
		RAB,
		LSB,
		RSB,
		EQ,
		COLON,
		LB,
		RB,
		COMMA,
		OPTIONAL,
		VECTOR,
		DEAMER_VARNAME,
		COMMENT,
		VARNAME,
		NUMBER,
		STRING,
		SEMICOLON,
		ESCAPE_CHARS,


		// NonTerminal
		program,
		deamerreserved_star__stmt__,
		stmt,
		comment_line,
		vector_variant,
		optional_variant,
		value_part,
		standard_variant,
		value,
		value_type,
		deamerreserved_arrow__value_type__,
		deamerreserved_star__COMMA__value_type__,
		var_type,
		deamerreserved_arrow__VARNAME__,
		deamerreserved_star__COLON__VARNAME__,
		var_name,

	};

	static inline bool operator==(std::size_t lhs, ::DLDL_LPDDEF_DF::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_LPDDEF_DF::ast::Type lhs, std::size_t rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}

	static inline bool operator==(int lhs, ::DLDL_LPDDEF_DF::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_LPDDEF_DF::ast::Type lhs, int rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}
}}

#endif // DLDL_LPDDEF_DF_AST_ENUM_TYPE_H