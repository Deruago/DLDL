#ifndef DLDL_GENERATION_AST_RELATION_NODEISDELETED_H
#define DLDL_GENERATION_AST_RELATION_NODEISDELETED_H

#include "DLDL_GENERATION/Ast/Enum/Type.h"

namespace DLDL_GENERATION { namespace ast { namespace relation { 

	constexpr static bool NodeIsDeleted(::DLDL_GENERATION::ast::Type t)
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
			return true;
		}

		if (t == ::DLDL_GENERATION::ast::Type::ESCAPE_CHARS)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_GENERATION_AST_RELATION_NODEISDELETED_H