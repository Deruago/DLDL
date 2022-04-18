#ifndef DLDL_PRECEDENCE_AST_RELATION_NODEISIGNORED_H
#define DLDL_PRECEDENCE_AST_RELATION_NODEISIGNORED_H

#include "DLDL_PRECEDENCE/Ast/Enum/Type.h"

namespace DLDL_PRECEDENCE { namespace ast { namespace relation { 

	constexpr static bool NodeIsIgnored(::DLDL_PRECEDENCE::ast::Type t)
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
			return false;
		}

		if (t == ::DLDL_PRECEDENCE::ast::Type::ESCAPE_CHARS)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_PRECEDENCE_AST_RELATION_NODEISIGNORED_H