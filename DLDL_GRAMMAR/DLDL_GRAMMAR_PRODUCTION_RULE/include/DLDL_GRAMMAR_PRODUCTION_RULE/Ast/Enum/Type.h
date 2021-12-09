#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_ENUM_TYPE_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_ENUM_TYPE_H

#include <cstddef>

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { 

	enum class Type : std::size_t
	{
		// Reserved
		deamerreserved_unknown,

		// Terminal
		ENDING_USELESS_SYMBOLS,
		VERTICAL_SLASH,
		LEFT_PARANTHESIS,
		RIGHT_PARANTHESIS,
		LEFT_BRACKET,
		RIGHT_BRACKET,
		LEFT_SQUARE_BRACKET,
		RIGHT_SQUARE_BRACKET,
		QUESTION_MARK,
		EXCLAMATION_MARK,
		ARROW,
		STAR,
		PLUS,
		MINUS,
		VALUE,
		NUMBER,
		SINGLE_LINE_COMMENT,
		MULTI_LINE_COMMENT,
		SYMBOLS,
		ESCAPE_CHARS,


		// NonTerminal
		program,
		stmts,
		stmt,
		group,
		nested_group,
		optional_group,
		zero_or_more_group,
		one_or_more_group,
		or_group,
		min_max_group,
		extension_group,

	};

	static inline bool operator==(std::size_t lhs, ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type lhs, std::size_t rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}

	static inline bool operator==(int lhs, ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type lhs, int rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}
}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_ENUM_TYPE_H