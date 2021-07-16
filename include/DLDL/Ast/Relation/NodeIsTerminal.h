#ifndef DLDL_AST_RELATION_NODEISTERMINAL_H
#define DLDL_AST_RELATION_NODEISTERMINAL_H

#include "DLDL/Ast/Enum/Type.h"

namespace DLDL { namespace ast { namespace relation { 

	constexpr static bool NodeIsTerminal(::DLDL::ast::Type t)
	{
		
		if (t == ::DLDL::ast::Type::ANY)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_AST_RELATION_NODEISTERMINAL_H