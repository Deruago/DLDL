#ifndef DLDL_LPDSTRUCT_AST_RELATION_NODEISNONTERMINAL_H
#define DLDL_LPDSTRUCT_AST_RELATION_NODEISNONTERMINAL_H

#include "DLDL_LPDSTRUCT/Ast/Enum/Type.h"

namespace DLDL_LPDSTRUCT { namespace ast { namespace relation { 

	constexpr static bool NodeIsNonTerminal(::DLDL_LPDSTRUCT::ast::Type t)
	{
		
		if (t == ::DLDL_LPDSTRUCT::ast::Type::program)
		{
			return true;
		}

		if (t == ::DLDL_LPDSTRUCT::ast::Type::deamerreserved_star__stmt__)
		{
			return true;
		}

		if (t == ::DLDL_LPDSTRUCT::ast::Type::stmt)
		{
			return true;
		}

		if (t == ::DLDL_LPDSTRUCT::ast::Type::argument)
		{
			return true;
		}

		if (t == ::DLDL_LPDSTRUCT::ast::Type::argument_name)
		{
			return true;
		}

		if (t == ::DLDL_LPDSTRUCT::ast::Type::argument_block)
		{
			return true;
		}

		if (t == ::DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_60)
		{
			return true;
		}

		if (t == ::DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_63)
		{
			return true;
		}

		if (t == ::DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_66)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_LPDSTRUCT_AST_RELATION_NODEISNONTERMINAL_H