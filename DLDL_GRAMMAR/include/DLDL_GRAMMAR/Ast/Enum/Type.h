#ifndef DLDL_GRAMMAR_AST_ENUM_TYPE_H
#define DLDL_GRAMMAR_AST_ENUM_TYPE_H

#include <cstddef>

namespace DLDL_GRAMMAR { namespace ast { 

	enum class Type : std::size_t
	{
		// Reserved
		deamerreserved_unknown,

		// Terminal
		COMMENT,
		START_ABSTRACTION,
		GROUP_ABSTRACTION,
		INLINE_ABSTRACTION,
		INLINE_GROUP_ABSTRACTION,
		UNKNOWN_ABSTRACTION,
		NONTERMINAL,
		PRODUCTION_RULE,
		ESCAPE_CHARS,


		// NonTerminal
		program,
		stmts,
		stmt,
		abstraction_declaration,
		abstraction,
		definition,
		production_rules,

	};

	static inline bool operator==(std::size_t lhs, ::DLDL_GRAMMAR::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_GRAMMAR::ast::Type lhs, std::size_t rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}

	static inline bool operator==(int lhs, ::DLDL_GRAMMAR::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_GRAMMAR::ast::Type lhs, int rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}
}}

#endif // DLDL_GRAMMAR_AST_ENUM_TYPE_H