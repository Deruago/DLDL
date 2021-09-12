#ifndef DLDL_ASSOCIATIVITY_AST_RELATION_NODEISTERMINAL_H
#define DLDL_ASSOCIATIVITY_AST_RELATION_NODEISTERMINAL_H

#include "DLDL_ASSOCIATIVITY/Ast/Enum/Type.h"

namespace DLDL_ASSOCIATIVITY { namespace ast { namespace relation { 

	constexpr static bool NodeIsTerminal(::DLDL_ASSOCIATIVITY::ast::Type t)
	{
		
		if (t == ::DLDL_ASSOCIATIVITY::ast::Type::ASSOCIATIVITY)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_ASSOCIATIVITY_AST_RELATION_NODEISTERMINAL_H