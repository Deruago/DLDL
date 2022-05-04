#ifndef DLDL_IDENTITY_AST_RELATION_NODEISIGNORED_H
#define DLDL_IDENTITY_AST_RELATION_NODEISIGNORED_H

#include "DLDL_IDENTITY/Ast/Enum/Type.h"

namespace DLDL_IDENTITY { namespace ast { namespace relation { 

	constexpr static bool NodeIsIgnored(::DLDL_IDENTITY::ast::Type t)
	{
		
		if (t == ::DLDL_IDENTITY::ast::Type::NAME)
		{
			return false;
		}

		if (t == ::DLDL_IDENTITY::ast::Type::VALUE)
		{
			return false;
		}

		if (t == ::DLDL_IDENTITY::ast::Type::SYMBOLS)
		{
			return false;
		}

		if (t == ::DLDL_IDENTITY::ast::Type::ESCAPE_CHARS)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_IDENTITY_AST_RELATION_NODEISIGNORED_H