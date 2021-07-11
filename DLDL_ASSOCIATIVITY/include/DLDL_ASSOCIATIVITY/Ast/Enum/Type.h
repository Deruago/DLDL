#ifndef DLDL_ASSOCIATIVITY_AST_ENUM_TYPE_H
#define DLDL_ASSOCIATIVITY_AST_ENUM_TYPE_H

namespace DLDL_ASSOCIATIVITY { namespace ast {

	enum class Type
	{
		// Terminals
		ASSOCIATIVITY,

		// Non-Terminals
		program,
		stmts,
		stmt,
	};

}}

#endif // DLDL_ASSOCIATIVITY_AST_ENUM_TYPE_H
