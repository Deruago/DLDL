#ifndef DLDL_ARGUMENT_AST_RELATION_NODEISNONTERMINAL_H
#define DLDL_ARGUMENT_AST_RELATION_NODEISNONTERMINAL_H

#include "DLDL_ARGUMENT/Ast/Enum/Type.h"

namespace DLDL_ARGUMENT { namespace ast { namespace relation { 

	constexpr static bool NodeIsNonTerminal(::DLDL_ARGUMENT::ast::Type t)
	{
		
		if (t == ::DLDL_ARGUMENT::ast::Type::program)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_ARGUMENT_AST_RELATION_NODEISNONTERMINAL_H