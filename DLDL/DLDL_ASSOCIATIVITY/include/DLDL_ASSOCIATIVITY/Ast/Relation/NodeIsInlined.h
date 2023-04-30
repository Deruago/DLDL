#ifndef DLDL_ASSOCIATIVITY_AST_RELATION_NODEISINLINED_H
#define DLDL_ASSOCIATIVITY_AST_RELATION_NODEISINLINED_H

#include "DLDL_ASSOCIATIVITY/Ast/Enum/Type.h"

namespace DLDL_ASSOCIATIVITY { namespace ast { namespace relation { 

	constexpr static bool NodeIsInlined(::DLDL_ASSOCIATIVITY::ast::Type t)
	{
		
		if (t == ::DLDL_ASSOCIATIVITY::ast::Type::program)
		{
			return false;
		}

		if (t == ::DLDL_ASSOCIATIVITY::ast::Type::stmts)
		{
			return false;
		}

		if (t == ::DLDL_ASSOCIATIVITY::ast::Type::stmt)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_ASSOCIATIVITY_AST_RELATION_NODEISINLINED_H