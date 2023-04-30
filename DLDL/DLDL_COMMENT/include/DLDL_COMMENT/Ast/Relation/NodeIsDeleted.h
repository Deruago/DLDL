#ifndef DLDL_COMMENT_AST_RELATION_NODEISDELETED_H
#define DLDL_COMMENT_AST_RELATION_NODEISDELETED_H

#include "DLDL_COMMENT/Ast/Enum/Type.h"

namespace DLDL_COMMENT { namespace ast { namespace relation { 

	constexpr static bool NodeIsDeleted(::DLDL_COMMENT::ast::Type t)
	{
		
		if (t == ::DLDL_COMMENT::ast::Type::SINGLE_COMMENT)
		{
			return true;
		}

		if (t == ::DLDL_COMMENT::ast::Type::MULTI_COMMENT)
		{
			return true;
		}

		if (t == ::DLDL_COMMENT::ast::Type::COMMENT_VALUE)
		{
			return false;
		}

		if (t == ::DLDL_COMMENT::ast::Type::LEFT_SQUARE_BRACKET)
		{
			return false;
		}

		if (t == ::DLDL_COMMENT::ast::Type::RIGHT_SQUARE_BRACKET)
		{
			return false;
		}

		if (t == ::DLDL_COMMENT::ast::Type::START)
		{
			return false;
		}

		if (t == ::DLDL_COMMENT::ast::Type::END)
		{
			return false;
		}

		if (t == ::DLDL_COMMENT::ast::Type::TEXT)
		{
			return false;
		}

		if (t == ::DLDL_COMMENT::ast::Type::VARNAME)
		{
			return false;
		}

		if (t == ::DLDL_COMMENT::ast::Type::ESCAPE_CHARS)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_COMMENT_AST_RELATION_NODEISDELETED_H