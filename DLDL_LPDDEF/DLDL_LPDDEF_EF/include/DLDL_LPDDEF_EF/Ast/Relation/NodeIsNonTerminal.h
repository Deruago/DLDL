#ifndef DLDL_LPDDEF_EF_AST_RELATION_NODEISNONTERMINAL_H
#define DLDL_LPDDEF_EF_AST_RELATION_NODEISNONTERMINAL_H

#include "DLDL_LPDDEF_EF/Ast/Enum/Type.h"

namespace DLDL_LPDDEF_EF { namespace ast { namespace relation { 

	constexpr static bool NodeIsNonTerminal(::DLDL_LPDDEF_EF::ast::Type t)
	{
		
		if (t == ::DLDL_LPDDEF_EF::ast::Type::program)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::deamerreserved_star__stmt__)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::stmt)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::comment_line)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::standard_variant)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::standard_variant_specific_number)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::value)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::enum_name)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_LPDDEF_EF_AST_RELATION_NODEISNONTERMINAL_H