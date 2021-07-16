#ifndef DLDL_IDENTITY_AST_RELATION_NODEISTERMINAL_H
#define DLDL_IDENTITY_AST_RELATION_NODEISTERMINAL_H

#include "DLDL_IDENTITY/Ast/Enum/Type.h"

namespace DLDL_IDENTITY { namespace ast { namespace relation { 

	constexpr static bool NodeIsTerminal(::DLDL_IDENTITY::ast::Type t)
	{
		
		if (t == ::DLDL_IDENTITY::ast::Type::NAME)
		{
			return true;
		}

		if (t == ::DLDL_IDENTITY::ast::Type::VALUE)
		{
			return true;
		}

		if (t == ::DLDL_IDENTITY::ast::Type::SYMBOLS)
		{
			return true;
		}

		if (t == ::DLDL_IDENTITY::ast::Type::ESCAPE_CHARS)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_IDENTITY_AST_RELATION_NODEISTERMINAL_H