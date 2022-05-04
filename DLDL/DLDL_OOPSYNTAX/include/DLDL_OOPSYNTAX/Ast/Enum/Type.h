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
		deamerreserved_star__production_rule_conversion__,
		production_rule_conversion,
		numbered_pr_convert,
		deamerreserved_star__property_assignment__,
		property_assignment,
		direct_property_assignment,
		direct_any_property_assignment,
		embedded_assignment,
		nonterminal_name,
		oop_type,
		property,
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