#ifndef DLDL_PRECEDENCE_AST_RELATION_NODEISTERMINAL_H
#define DLDL_PRECEDENCE_AST_RELATION_NODEISTERMINAL_H

#include "DLDL_PRECEDENCE/Ast/Enum/Type.h"

namespace DLDL_PRECEDENCE { namespace ast { namespace relation { 

	constexpr static bool NodeIsTerminal(::DLDL_PRECEDENCE::ast::Type t)
	{
		
		if (t == ::DLDL_PRECEDENCE::ast::Type::PRECEDENCE)
		{
			return true;
		}

		if (t == ::DLDL_PRECEDENCE::ast::Type::NUMBER)
		{
			return true;
		}

		if (t == ::DLDL_PRECEDENCE::ast::Type::TERMINAL)
		{
			return true;
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

#endif // DLDL_PRECEDENCE_AST_RELATION_NODEISTERMINAL_H