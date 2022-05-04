#ifndef DLDL_LPDDEF_AST_RELATION_NODEISNONTERMINAL_H
#define DLDL_LPDDEF_AST_RELATION_NODEISNONTERMINAL_H

#include "DLDL_LPDDEF/Ast/Enum/Type.h"

namespace DLDL_LPDDEF { namespace ast { namespace relation { 

	constexpr static bool NodeIsNonTerminal(::DLDL_LPDDEF::ast::Type t)
	{
		
		if (t == ::DLDL_LPDDEF::ast::Type::program)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF::ast::Type::deamerreserved_star__stmt__)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF::ast::Type::stmt)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF::ast::Type::argument)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF::ast::Type::argument_name)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF::ast::Type::argument_block)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF::ast::Type::deamerreserved_star__argument_stmt__)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF::ast::Type::argument_stmt)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_LPDDEF_AST_RELATION_NODEISNONTERMINAL_H