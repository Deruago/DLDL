#ifndef DLDL_LPDDEF_EF_AST_RELATION_NODEISTERMINAL_H
#define DLDL_LPDDEF_EF_AST_RELATION_NODEISTERMINAL_H

#include "DLDL_LPDDEF_EF/Ast/Enum/Type.h"

namespace DLDL_LPDDEF_EF { namespace ast { namespace relation { 

	constexpr static bool NodeIsTerminal(::DLDL_LPDDEF_EF::ast::Type t)
	{
		
		if (t == ::DLDL_LPDDEF_EF::ast::Type::COMMENT)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::VARNAME)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::NUMBER)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::COLON)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::SEMICOLON)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_EF::ast::Type::ESCAPE_CHARS)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_LPDDEF_EF_AST_RELATION_NODEISTERMINAL_H