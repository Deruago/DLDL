#ifndef DLDL_ASSOCIATIVITY_AST_RELATION_NODEISNONTERMINAL_H
#define DLDL_ASSOCIATIVITY_AST_RELATION_NODEISNONTERMINAL_H

#include "DLDL_ASSOCIATIVITY/Ast/Enum/Type.h"

namespace DLDL_ASSOCIATIVITY { namespace ast { namespace relation { 

	constexpr static bool NodeIsNonTerminal(::DLDL_ASSOCIATIVITY::ast::Type t)
	{
		
		if (t == ::DLDL_ASSOCIATIVITY::ast::Type::program)
		{
			return true;
		}

		if (t == ::DLDL_ASSOCIATIVITY::ast::Type::stmts)
		{
			return true;
		}

		if (t == ::DLDL_ASSOCIATIVITY::ast::Type::stmt)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_ASSOCIATIVITY_AST_RELATION_NODEISNONTERMINAL_H