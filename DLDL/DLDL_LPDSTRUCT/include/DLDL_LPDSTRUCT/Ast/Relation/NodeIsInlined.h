#ifndef DLDL_LPDSTRUCT_AST_RELATION_NODEISINLINED_H
#define DLDL_LPDSTRUCT_AST_RELATION_NODEISINLINED_H

#include "DLDL_LPDSTRUCT/Ast/Enum/Type.h"

namespace DLDL_LPDSTRUCT { namespace ast { namespace relation { 

	constexpr static bool NodeIsInlined(::DLDL_LPDSTRUCT::ast::Type t)
	{
		
		if (t == ::DLDL_LPDSTRUCT::ast::Type::program)
		{
			return false;
		}

		if (t == ::DLDL_LPDSTRUCT::ast::Type::deamerreserved_star__stmt__)
		{
			return true;
		}

		if (t == ::DLDL_LPDSTRUCT::ast::Type::stmt)
		{
			return false;
		}

		if (t == ::DLDL_LPDSTRUCT::ast::Type::argument)
		{
			return false;
		}

		if (t == ::DLDL_LPDSTRUCT::ast::Type::argument_name)
		{
			return false;
		}

		if (t == ::DLDL_LPDSTRUCT::ast::Type::argument_block)
		{
			return false;
		}

		if (t == ::DLDL_LPDSTRUCT::ast::Type::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_LPDSTRUCT_AST_RELATION_NODEISINLINED_H