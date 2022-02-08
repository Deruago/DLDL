#ifndef DLDL_LPDDEF_EF_AST_RELATION_NODEISINLINED_H
#define DLDL_LPDDEF_EF_AST_RELATION_NODEISINLINED_H

#include "DLDL_LPDDEF_EF/Ast/Enum/Type.h"

namespace DLDL_LPDDEF_EF { namespace ast { namespace relation { 

	constexpr static bool NodeIsInlined(::DLDL_LPDDEF_EF::ast::Type t)
	{
		
		if (t == ::DLDL_LPDDEF_EF::ast::Type::program)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::deamerreserved_star__stmt__)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::stmt)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::comment_line)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::standard_variant)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::standard_variant_specific_number)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::value)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::enum_name)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_LPDDEF_EF_AST_RELATION_NODEISINLINED_H