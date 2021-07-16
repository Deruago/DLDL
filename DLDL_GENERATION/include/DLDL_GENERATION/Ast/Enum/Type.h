#ifndef DLDL_GENERATION_AST_ENUM_TYPE_H
#define DLDL_GENERATION_AST_ENUM_TYPE_H

namespace DLDL_GENERATION { namespace ast {

	enum class Type
	{
		// Reserved
		deamerreserved_unknown,

		// Terminals
		GENERATE,
		INTEGRATE,
		ARGUMENT,
		VALUE,
		SYMBOLS,
		ESCAPE_CHARS,

		// Non-Terminals
		program,
		stmts,
		stmt,
		generate_declaration,
		integrate_declaration,
		argument_declaration,
		type,
		tool,
		argument_data,
	};

}}

#endif // DLDL_GENERATION_AST_ENUM_TYPE_H
