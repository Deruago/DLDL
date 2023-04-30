#ifndef DLDL_GENERATION_AST_RELATION_NODEISIGNORED_H
#define DLDL_GENERATION_AST_RELATION_NODEISIGNORED_H

#include "DLDL_GENERATION/Ast/Enum/Type.h"

namespace DLDL_GENERATION { namespace ast { namespace relation { 

	constexpr static bool NodeIsIgnored(::DLDL_GENERATION::ast::Type t)
	{
		
		if (t == ::DLDL_GENERATION::ast::Type::GENERATE)
		{
			return false;
		}

		if (t == ::DLDL_GENERATION::ast::Type::INTEGRATE)
		{
			return false;
		}

		if (t == ::DLDL_GENERATION::ast::Type::ARGUMENT)
		{
			return false;
		}

		if (t == ::DLDL_GENERATION::ast::Type::VALUE)
		{
			return false;
		}

		if (t == ::DLDL_GENERATION::ast::Type::SYMBOLS)
		{
			return false;
		}

		if (t == ::DLDL_GENERATION::ast::Type::ESCAPE_CHARS)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_GENERATION_AST_RELATION_NODEISIGNORED_H