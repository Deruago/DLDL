#ifndef DLDL_LDOSTRUCT_AST_ENUM_TYPE_H
#define DLDL_LDOSTRUCT_AST_ENUM_TYPE_H

#include <cstddef>

namespace DLDL_LDOSTRUCT { namespace ast { 

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
		deamerreserved_star__argument_stmt__,
		argument_stmt,

	};

	static inline bool operator==(std::size_t lhs, ::DLDL_LDOSTRUCT::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_LDOSTRUCT::ast::Type lhs, std::size_t rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}

	static inline bool operator==(int lhs, ::DLDL_LDOSTRUCT::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_LDOSTRUCT::ast::Type lhs, int rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}
}}

#endif // DLDL_LDOSTRUCT_AST_ENUM_TYPE_H