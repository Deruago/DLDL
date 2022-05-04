#ifndef DLDL_IDENTITY_AST_RELATION_NODEISNONTERMINAL_H
#define DLDL_IDENTITY_AST_RELATION_NODEISNONTERMINAL_H

#include "DLDL_IDENTITY/Ast/Enum/Type.h"

namespace DLDL_IDENTITY { namespace ast { namespace relation { 

	constexpr static bool NodeIsNonTerminal(::DLDL_IDENTITY::ast::Type t)
	{
		
		if (t == ::DLDL_IDENTITY::ast::Type::program)
		{
			return true;
		}

		if (t == ::DLDL_IDENTITY::ast::Type::stmts)
		{
			return true;
		}

		if (t == ::DLDL_IDENTITY::ast::Type::stmt)
		{
			return true;
		}

		if (t == ::DLDL_IDENTITY::ast::Type::name_declaration)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_IDENTITY_AST_RELATION_NODEISNONTERMINAL_H