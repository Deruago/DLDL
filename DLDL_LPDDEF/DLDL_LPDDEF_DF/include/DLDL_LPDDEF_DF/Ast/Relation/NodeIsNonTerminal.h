#ifndef DLDL_LPDDEF_DF_AST_RELATION_NODEISNONTERMINAL_H
#define DLDL_LPDDEF_DF_AST_RELATION_NODEISNONTERMINAL_H

#include "DLDL_LPDDEF_DF/Ast/Enum/Type.h"

namespace DLDL_LPDDEF_DF { namespace ast { namespace relation { 

	constexpr static bool NodeIsNonTerminal(::DLDL_LPDDEF_DF::ast::Type t)
	{
		
		if (t == ::DLDL_LPDDEF_DF::ast::Type::program)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__stmt__)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::stmt)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::comment_line)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::vector_variant)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::optional_variant)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::value_part)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::standard_variant)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::value)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::value_type)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__value_type__)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COMMA__value_type__)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::var_type)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__VARNAME__)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COLON__VARNAME__)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::var_name)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_LPDDEF_DF_AST_RELATION_NODEISNONTERMINAL_H