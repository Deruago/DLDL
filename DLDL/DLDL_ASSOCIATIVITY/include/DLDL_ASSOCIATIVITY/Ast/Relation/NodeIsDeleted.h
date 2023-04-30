#ifndef DLDL_ASSOCIATIVITY_AST_RELATION_NODEISDELETED_H
#define DLDL_ASSOCIATIVITY_AST_RELATION_NODEISDELETED_H

#include "DLDL_ASSOCIATIVITY/Ast/Enum/Type.h"

namespace DLDL_ASSOCIATIVITY { namespace ast { namespace relation { 

	constexpr static bool NodeIsDeleted(::DLDL_ASSOCIATIVITY::ast::Type t)
	{
		
		if (t == ::DLDL_ASSOCIATIVITY::ast::Type::ASSOCIATIVITY)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_ASSOCIATIVITY_AST_RELATION_NODEISDELETED_H