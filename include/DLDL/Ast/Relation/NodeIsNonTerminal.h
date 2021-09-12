#ifndef DLDL_AST_RELATION_NODEISNONTERMINAL_H
#define DLDL_AST_RELATION_NODEISNONTERMINAL_H

#include "DLDL/Ast/Enum/Type.h"

namespace DLDL { namespace ast { namespace relation { 

	constexpr static bool NodeIsNonTerminal(::DLDL::ast::Type t)
	{
		
		if (t == ::DLDL::ast::Type::program)
		{
			return true;
		}

		if (t == ::DLDL::ast::Type::stmts)
		{
			return true;
		}

		if (t == ::DLDL::ast::Type::stmt)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_AST_RELATION_NODEISNONTERMINAL_H