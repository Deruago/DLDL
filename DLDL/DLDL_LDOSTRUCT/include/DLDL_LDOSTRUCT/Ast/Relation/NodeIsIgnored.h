#ifndef DLDL_LDOSTRUCT_AST_RELATION_NODEISIGNORED_H
#define DLDL_LDOSTRUCT_AST_RELATION_NODEISIGNORED_H

#include "DLDL_LDOSTRUCT/Ast/Enum/Type.h"

namespace DLDL_LDOSTRUCT { namespace ast { namespace relation { 

	constexpr static bool NodeIsIgnored(::DLDL_LDOSTRUCT::ast::Type t)
	{
		
		if (t == ::DLDL_LDOSTRUCT::ast::Type::COLON)
		{
			return true;
		}

		if (t == ::DLDL_LDOSTRUCT::ast::Type::LEFT_ANGLE_BRACKET)
		{
			return true;
		}

		if (t == ::DLDL_LDOSTRUCT::ast::Type::RIGHT_ANGLE_BRACKET)
		{
			return true;
		}

		if (t == ::DLDL_LDOSTRUCT::ast::Type::VARNAME)
		{
			return false;
		}

		if (t == ::DLDL_LDOSTRUCT::ast::Type::INDENTED_VALUE)
		{
			return false;
		}

		if (t == ::DLDL_LDOSTRUCT::ast::Type::ESCAPE_CHARS)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_LDOSTRUCT_AST_RELATION_NODEISIGNORED_H