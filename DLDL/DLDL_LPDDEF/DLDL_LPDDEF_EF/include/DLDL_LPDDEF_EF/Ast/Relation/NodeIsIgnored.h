#ifndef DLDL_LPDDEF_EF_AST_RELATION_NODEISIGNORED_H
#define DLDL_LPDDEF_EF_AST_RELATION_NODEISIGNORED_H

#include "DLDL_LPDDEF_EF/Ast/Enum/Type.h"

namespace DLDL_LPDDEF_EF { namespace ast { namespace relation { 

	constexpr static bool NodeIsIgnored(::DLDL_LPDDEF_EF::ast::Type t)
	{
		
		if (t == ::DLDL_LPDDEF_EF::ast::Type::COMMENT)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::VARNAME)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::NUMBER)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::COLON)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::SEMICOLON)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::ESCAPE_CHARS)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_LPDDEF_EF_AST_RELATION_NODEISIGNORED_H