#ifndef DLDL_ARGUMENT_AST_RELATION_NODEISTERMINAL_H
#define DLDL_ARGUMENT_AST_RELATION_NODEISTERMINAL_H

#include "DLDL_ARGUMENT/Ast/Enum/Type.h"

namespace DLDL_ARGUMENT { namespace ast { namespace relation { 

	constexpr static bool NodeIsTerminal(::DLDL_ARGUMENT::ast::Type t)
	{
		
		if (t == ::DLDL_ARGUMENT::ast::Type::SINGLE_COMMENT)
		{
			return true;
		}

		if (t == ::DLDL_ARGUMENT::ast::Type::MULTI_COMMENT)
		{
			return true;
		}

		if (t == ::DLDL_ARGUMENT::ast::Type::TEXT)
		{
			return true;
		}

		if (t == ::DLDL_ARGUMENT::ast::Type::VARNAME)
		{
			return true;
		}

		if (t == ::DLDL_ARGUMENT::ast::Type::ESCAPE_CHARS)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_ARGUMENT_AST_RELATION_NODEISTERMINAL_H