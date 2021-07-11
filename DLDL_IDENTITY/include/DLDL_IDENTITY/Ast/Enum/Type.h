#ifndef DLDL_IDENTITY_AST_ENUM_TYPE_H
#define DLDL_IDENTITY_AST_ENUM_TYPE_H

namespace DLDL_IDENTITY { namespace ast {

	enum class Type
	{
		// Terminals
		NAME,
		VALUE,
		SYMBOLS,
		ESCAPE_CHARS,

		// Non-Terminals
		program,
		stmts,
		stmt,
		name_declaration,
	};

}}

#endif // DLDL_IDENTITY_AST_ENUM_TYPE_H
