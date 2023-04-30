#ifndef DLDL_LPDDEF_DF_AST_RELATION_NODEISINLINED_H
#define DLDL_LPDDEF_DF_AST_RELATION_NODEISINLINED_H

#include "DLDL_LPDDEF_DF/Ast/Enum/Type.h"

namespace DLDL_LPDDEF_DF { namespace ast { namespace relation { 

	constexpr static bool NodeIsInlined(::DLDL_LPDDEF_DF::ast::Type t)
	{
		
		if (t == ::DLDL_LPDDEF_DF::ast::Type::program)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__stmt__)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::stmt)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::comment_line)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::vector_variant)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_optional__value_part__)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::optional_variant)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::value_part)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::standard_variant)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::value)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::value_type)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__value_type__)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COMMA__value_type__)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_long_54)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::var_type)
		{
			return false;
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
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_LPDDEF_DF_AST_RELATION_NODEISINLINED_H