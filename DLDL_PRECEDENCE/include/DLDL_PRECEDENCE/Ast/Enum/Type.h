#ifndef DLDL_PRECEDENCE_AST_ENUM_TYPE_H
#define DLDL_PRECEDENCE_AST_ENUM_TYPE_H

namespace DLDL_PRECEDENCE { namespace ast {

	enum class Type
	{
		// Reserved
		deamerreserved_unknown,

		// Terminals
		PRECEDENCE,
		NUMBER,
		TERMINAL,
		SYMBOLS,
		ESCAPE_CHARS,

		// Non-Terminals
		program,
		stmts,
		stmt,
		localized_precedence,
		specific_precedence,
		terminal_one_or_more,
	};

}}

#endif // DLDL_PRECEDENCE_AST_ENUM_TYPE_H
