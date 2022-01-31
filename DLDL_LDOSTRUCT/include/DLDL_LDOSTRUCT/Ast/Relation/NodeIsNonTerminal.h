#ifndef DLDL_LDOSTRUCT_AST_RELATION_NODEISNONTERMINAL_H
#define DLDL_LDOSTRUCT_AST_RELATION_NODEISNONTERMINAL_H

#include "DLDL_LDOSTRUCT/Ast/Enum/Type.h"

namespace DLDL_LDOSTRUCT { namespace ast { namespace relation { 

	constexpr static bool NodeIsNonTerminal(::DLDL_LDOSTRUCT::ast::Type t)
	{
		
		if (t == ::DLDL_LDOSTRUCT::ast::Type::program)
		{
			return true;
		}

		if (t == ::DLDL_LDOSTRUCT::ast::Type::deamerreserved_star__stmt__)
		{
			return true;
		}

		if (t == ::DLDL_LDOSTRUCT::ast::Type::stmt)
		{
			return true;
		}

		if (t == ::DLDL_LDOSTRUCT::ast::Type::argument)
		{
			return true;
		}

		if (t == ::DLDL_LDOSTRUCT::ast::Type::argument_name)
		{
			return true;
		}

		if (t == ::DLDL_LDOSTRUCT::ast::Type::argument_block)
		{
			return true;
		}

		if (t == ::DLDL_LDOSTRUCT::ast::Type::deamerreserved_star__argument_stmt__)
		{
			return true;
		}

		if (t == ::DLDL_LDOSTRUCT::ast::Type::argument_stmt)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_LDOSTRUCT_AST_RELATION_NODEISNONTERMINAL_H