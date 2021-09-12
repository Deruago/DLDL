#ifndef DLDL_AST_ENUM_TYPE_H
#define DLDL_AST_ENUM_TYPE_H

namespace DLDL { namespace ast {

	enum class Type
	{
		// Reserved
		deamerreserved_unknown,

		// Terminals
		ANY,

		// Non-Terminals
		program,
		stmts,
		stmt,
	};

}}

#endif // DLDL_AST_ENUM_TYPE_H
