#ifndef DLDL_PRECEDENCE_AST_RELATION_NODEISDELETED_H
#define DLDL_PRECEDENCE_AST_RELATION_NODEISDELETED_H

#include "DLDL_PRECEDENCE/Ast/Enum/Type.h"

namespace DLDL_PRECEDENCE { namespace ast { namespace relation { 

	constexpr static bool NodeIsDeleted(::DLDL_PRECEDENCE::ast::Type t)
	{
		
		if (t == ::DLDL_PRECEDENCE::ast::Type::PRECEDENCE)
		{
			return false;
		}

		if (t == ::DLDL_PRECEDENCE::ast::Type::NUMBER)
		{
			return false;
		}

		if (t == ::DLDL_PRECEDENCE::ast::Type::TERMINAL)
		{
			return false;
		}

		if (t == ::DLDL_PRECEDENCE::ast::Type::SYMBOLS)
		{
			return true;
		}

		if (t == ::DLDL_PRECEDENCE::ast::Type::ESCAPE_CHARS)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_PRECEDENCE_AST_RELATION_NODEISDELETED_H