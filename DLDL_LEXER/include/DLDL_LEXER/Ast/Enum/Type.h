#ifndef DLDL_LEXER_AST_ENUM_TYPE_H
#define DLDL_LEXER_AST_ENUM_TYPE_H

namespace DLDL_LEXER { namespace ast {

	enum class Type
	{
		// Terminals
		DELETE_ABSTRACTION,
		IGNORE_ABSTRACTION,
		NOVALUE_ABSTRACTION,
		CRASH_ABSTRACTION,
		STANDARD_ABSTRACTION,
		UNKNOWN_ABSTRACTION,
		TERMINAL,
		REGEX,
		ESCAPE_CHARS,
		COMMENT,
		MULTI_LINE_COMMENT,

		// Non-Terminals
		program,
		stmts,
		stmt,
		tokendeclaration,
		abstraction,
	};

}}

#endif // DLDL_LEXER_AST_ENUM_TYPE_H
