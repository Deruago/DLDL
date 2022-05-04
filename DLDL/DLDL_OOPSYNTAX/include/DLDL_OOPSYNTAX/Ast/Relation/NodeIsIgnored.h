#ifndef DLDL_OOPSYNTAX_AST_RELATION_NODEISIGNORED_H
#define DLDL_OOPSYNTAX_AST_RELATION_NODEISIGNORED_H

#include "DLDL_OOPSYNTAX/Ast/Enum/Type.h"

namespace DLDL_OOPSYNTAX { namespace ast { namespace relation { 

	constexpr static bool NodeIsIgnored(::DLDL_OOPSYNTAX::ast::Type t)
	{
		
		if (t == ::DLDL_OOPSYNTAX::ast::Type::ARROW)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::LEFT_BRACKET)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::RIGHT_BRACKET)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::DOT)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::EQ)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::STAR)
		{
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::VARNAME)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::NUMBER)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::COMMENT)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::ESCAPE_CHAR)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_OOPSYNTAX_AST_RELATION_NODEISIGNORED_H