#ifndef DLDL_IMPORT_AST_ENUM_TYPE_H
#define DLDL_IMPORT_AST_ENUM_TYPE_H

#include <cstddef>

namespace DLDL_IMPORT { namespace ast { 

	enum class Type : std::size_t
	{
		// Reserved
		deamerreserved_unknown,

		// Terminal
		SINGLE_COMMENT,
		MULTI_COMMENT,
		LEFT_PARANTHESIS,
		RIGHT_PARANTHESIS,
		LEFT_SQUARE_BRACKET,
		RIGHT_SQUARE_BRACKET,
		COLON,
		DOT,
		IMPORT_FILE,
		IMPORT_MODULE,
		IMPORT,
		TEXT,
		VARNAME,
		ESCAPE_CHARS,


		// NonTerminal
		program,
		deamerreserved_star__stmt__,
		stmt,
		import_declaration,
		deamerreserved_arrow__import_context__,
		deamerreserved_long_40,
		deamerreserved_long_43,
		specialization,
		import_abstraction,
		value,
		deamerreserved_optional__VARNAME__,
		abstraction,
		import_context,
		import_rule_name,

	};

	static inline bool operator==(std::size_t lhs, ::DLDL_IMPORT::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_IMPORT::ast::Type lhs, std::size_t rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}

	static inline bool operator==(int lhs, ::DLDL_IMPORT::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_IMPORT::ast::Type lhs, int rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}
}}

#endif // DLDL_IMPORT_AST_ENUM_TYPE_H