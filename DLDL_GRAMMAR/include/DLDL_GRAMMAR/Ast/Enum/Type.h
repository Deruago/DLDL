#ifndef DLDL_GRAMMAR_AST_ENUM_TYPE_H
#define DLDL_GRAMMAR_AST_ENUM_TYPE_H

namespace DLDL_GRAMMAR { namespace ast {

	enum class Type
	{
		// Reserved
		deamerreserved_unknown,

		// Terminals
		COMMENT,
		START_ABSTRACTION,
		GROUP_ABSTRACTION,
		INLINE_ABSTRACTION,
		INLINE_GROUP_ABSTRACTION,
		UNKNOWN_ABSTRACTION,
		NONTERMINAL,
		PRODUCTION_RULE,
		ESCAPE_CHARS,

		// Non-Terminals
		program,
		stmts,
		stmt,
		abstraction_declaration,
		abstraction,
		definition,
		production_rules,
	};

}}

#endif // DLDL_GRAMMAR_AST_ENUM_TYPE_H
