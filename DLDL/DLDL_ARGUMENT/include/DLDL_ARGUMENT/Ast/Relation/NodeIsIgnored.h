#ifndef DLDL_ARGUMENT_AST_RELATION_NODEISIGNORED_H
#define DLDL_ARGUMENT_AST_RELATION_NODEISIGNORED_H

#include "DLDL_ARGUMENT/Ast/Enum/Type.h"

namespace DLDL_ARGUMENT { namespace ast { namespace relation { 

	constexpr static bool NodeIsIgnored(::DLDL_ARGUMENT::ast::Type t)
	{
		
		if (t == ::DLDL_ARGUMENT::ast::Type::SINGLE_COMMENT)
		{
			return false;
		}

		if (t == ::DLDL_ARGUMENT::ast::Type::MULTI_COMMENT)
		{
			return false;
		}

		if (t == ::DLDL_ARGUMENT::ast::Type::TEXT)
		{
			return false;
		}

		if (t == ::DLDL_ARGUMENT::ast::Type::VARNAME)
		{
			return false;
		}

		if (t == ::DLDL_ARGUMENT::ast::Type::ESCAPE_CHARS)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_ARGUMENT_AST_RELATION_NODEISIGNORED_H