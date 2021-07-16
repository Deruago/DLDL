#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_ENUM_TYPE_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_ENUM_TYPE_H

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast {

	enum class Type
	{
		// Reserved
		deamerreserved_unknown,

		// Terminals
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

		// Non-Terminals
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

}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_ENUM_TYPE_H
