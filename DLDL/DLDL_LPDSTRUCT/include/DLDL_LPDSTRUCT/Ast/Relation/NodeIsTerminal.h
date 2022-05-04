#ifndef DLDL_LPDSTRUCT_AST_RELATION_NODEISTERMINAL_H
#define DLDL_LPDSTRUCT_AST_RELATION_NODEISTERMINAL_H

#include "DLDL_LPDSTRUCT/Ast/Enum/Type.h"

namespace DLDL_LPDSTRUCT { namespace ast { namespace relation { 

	constexpr static bool NodeIsTerminal(::DLDL_LPDSTRUCT::ast::Type t)
	{
		
		if (t == ::DLDL_LPDSTRUCT::ast::Type::COLON)
		{
			return true;
		}

		if (t == ::DLDL_LPDSTRUCT::ast::Type::LEFT_ANGLE_BRACKET)
		{
			return true;
		}

		if (t == ::DLDL_LPDSTRUCT::ast::Type::RIGHT_ANGLE_BRACKET)
		{
			return true;
		}

		if (t == ::DLDL_LPDSTRUCT::ast::Type::VARNAME)
		{
			return true;
		}

		if (t == ::DLDL_LPDSTRUCT::ast::Type::VARNAME_EXT)
		{
			return true;
		}

		if (t == ::DLDL_LPDSTRUCT::ast::Type::INDENTED_VALUE)
		{
			return true;
		}

		if (t == ::DLDL_LPDSTRUCT::ast::Type::ESCAPE_CHARS)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_LPDSTRUCT_AST_RELATION_NODEISTERMINAL_H