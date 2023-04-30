#ifndef DLDL_OOPSYNTAX_AST_ENUM_TYPE_H
#define DLDL_OOPSYNTAX_AST_ENUM_TYPE_H

#include <cstddef>

namespace DLDL_OOPSYNTAX { namespace ast { 

	enum class Type : std::size_t
	{
		// Reserved
		deamerreserved_unknown,

		// Terminal
		ARROW,
		LEFT_BRACKET,
		RIGHT_BRACKET,
		DOT,
		EQ,
		STAR,
		VARNAME,
		NUMBER,
		COMMENT,
		ESCAPE_CHAR,


		// NonTerminal
		program,
		deamerreserved_star__stmt__,
		stmt,
		nonterminal_conversion,
		deamerreserved_long_69,
		production_rule_conversion,
		numbered_pr_convert,
		deamerreserved_long_72,
		property_assignment,
		direct_property_assignment,
		deamerreserved_arrow__property__,
		deamerreserved_long_76,
		deamerreserved_arrow__terminal_name__,
		deamerreserved_long_80,
		direct_any_property_assignment,
		embedded_assignment,
		nonterminal_name,
		oop_type,
		property,
		extended_property,
		extended_terminal_access,
		terminal_name,

	};

	static inline bool operator==(std::size_t lhs, ::DLDL_OOPSYNTAX::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_OOPSYNTAX::ast::Type lhs, std::size_t rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}

	static inline bool operator==(int lhs, ::DLDL_OOPSYNTAX::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_OOPSYNTAX::ast::Type lhs, int rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}
}}

#endif // DLDL_OOPSYNTAX_AST_ENUM_TYPE_H