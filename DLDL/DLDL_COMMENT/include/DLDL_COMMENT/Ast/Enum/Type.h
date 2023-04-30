#ifndef DLDL_COMMENT_AST_ENUM_TYPE_H
#define DLDL_COMMENT_AST_ENUM_TYPE_H

#include <cstddef>

namespace DLDL_COMMENT { namespace ast { 

	enum class Type : std::size_t
	{
		// Reserved
		deamerreserved_unknown,

		// Terminal
		SINGLE_COMMENT,
		MULTI_COMMENT,
		COMMENT_VALUE,
		LEFT_SQUARE_BRACKET,
		RIGHT_SQUARE_BRACKET,
		START,
		END,
		TEXT,
		VARNAME,
		ESCAPE_CHARS,


		// NonTerminal
		program,
		deamerreserved_star__stmt__,
		stmt,
		comment_value_declaration,
		deamerreserved_long_3,
		deamerreserved_long_6,
		comment_abstraction,
		start_abstraction,
		end_abstraction,
		start_sequence,
		end_sequence,
		sequence,
		syntactic_reference,

	};

	static inline bool operator==(std::size_t lhs, ::DLDL_COMMENT::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_COMMENT::ast::Type lhs, std::size_t rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}

	static inline bool operator==(int lhs, ::DLDL_COMMENT::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_COMMENT::ast::Type lhs, int rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}
}}

#endif // DLDL_COMMENT_AST_ENUM_TYPE_H