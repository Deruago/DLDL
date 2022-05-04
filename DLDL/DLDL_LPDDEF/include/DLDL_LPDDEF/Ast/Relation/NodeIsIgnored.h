#ifndef DLDL_LPDDEF_AST_RELATION_NODEISIGNORED_H
#define DLDL_LPDDEF_AST_RELATION_NODEISIGNORED_H

#include "DLDL_LPDDEF/Ast/Enum/Type.h"

namespace DLDL_LPDDEF { namespace ast { namespace relation { 

	constexpr static bool NodeIsIgnored(::DLDL_LPDDEF::ast::Type t)
	{
		
		if (t == ::DLDL_LPDDEF::ast::Type::COLON)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF::ast::Type::LEFT_ANGLE_BRACKET)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF::ast::Type::RIGHT_ANGLE_BRACKET)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF::ast::Type::VARNAME)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF::ast::Type::INDENTED_VALUE)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF::ast::Type::ESCAPE_CHARS)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_LPDDEF_AST_RELATION_NODEISIGNORED_H