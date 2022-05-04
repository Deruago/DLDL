#ifndef DLDL_OOPSYNTAX_AST_RELATION_NODEISDELETED_H
#define DLDL_OOPSYNTAX_AST_RELATION_NODEISDELETED_H

#include "DLDL_OOPSYNTAX/Ast/Enum/Type.h"

namespace DLDL_OOPSYNTAX { namespace ast { namespace relation { 

	constexpr static bool NodeIsDeleted(::DLDL_OOPSYNTAX::ast::Type t)
	{
		
		if (t == ::DLDL_OOPSYNTAX::ast::Type::ARROW)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::LEFT_BRACKET)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::RIGHT_BRACKET)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::DOT)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::EQ)
		{
			return false;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::STAR)
		{
			return false;
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
			return true;
		}

		if (t == ::DLDL_OOPSYNTAX::ast::Type::ESCAPE_CHAR)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_OOPSYNTAX_AST_RELATION_NODEISDELETED_H