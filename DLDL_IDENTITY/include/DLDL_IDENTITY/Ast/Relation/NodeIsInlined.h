#ifndef DLDL_IDENTITY_AST_RELATION_NODEISINLINED_H
#define DLDL_IDENTITY_AST_RELATION_NODEISINLINED_H

#include "DLDL_IDENTITY/Ast/Enum/Type.h"

namespace DLDL_IDENTITY { namespace ast { namespace relation { 

	constexpr static bool NodeIsInlined(::DLDL_IDENTITY::ast::Type t)
	{
		
		if (t == ::DLDL_IDENTITY::ast::Type::program)
		{
			return false;
		}

		if (t == ::DLDL_IDENTITY::ast::Type::stmts)
		{
			return false;
		}

		if (t == ::DLDL_IDENTITY::ast::Type::stmt)
		{
			return false;
		}

		if (t == ::DLDL_IDENTITY::ast::Type::name_declaration)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_IDENTITY_AST_RELATION_NODEISINLINED_H