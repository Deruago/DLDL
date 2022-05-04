#ifndef DLDL_AST_RELATION_NODEISINLINED_H
#define DLDL_AST_RELATION_NODEISINLINED_H

#include "DLDL/Ast/Enum/Type.h"

namespace DLDL { namespace ast { namespace relation { 

	constexpr static bool NodeIsInlined(::DLDL::ast::Type t)
	{
		
		if (t == ::DLDL::ast::Type::program)
		{
			return false;
		}

		if (t == ::DLDL::ast::Type::stmts)
		{
			return false;
		}

		if (t == ::DLDL::ast::Type::stmt)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_AST_RELATION_NODEISINLINED_H