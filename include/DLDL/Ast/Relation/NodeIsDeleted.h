#ifndef DLDL_AST_RELATION_NODEISDELETED_H
#define DLDL_AST_RELATION_NODEISDELETED_H

#include "DLDL/Ast/Enum/Type.h"

namespace DLDL { namespace ast { namespace relation { 

	constexpr static bool NodeIsDeleted(::DLDL::ast::Type t)
	{
		
		if (t == ::DLDL::ast::Type::ANY)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_AST_RELATION_NODEISDELETED_H