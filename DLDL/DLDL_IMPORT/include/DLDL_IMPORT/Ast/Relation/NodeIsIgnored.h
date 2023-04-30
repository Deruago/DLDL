#ifndef DLDL_IMPORT_AST_RELATION_NODEISIGNORED_H
#define DLDL_IMPORT_AST_RELATION_NODEISIGNORED_H

#include "DLDL_IMPORT/Ast/Enum/Type.h"

namespace DLDL_IMPORT { namespace ast { namespace relation { 

	constexpr static bool NodeIsIgnored(::DLDL_IMPORT::ast::Type t)
	{
		
		if (t == ::DLDL_IMPORT::ast::Type::SINGLE_COMMENT)
		{
			return false;
		}

		if (t == ::DLDL_IMPORT::ast::Type::MULTI_COMMENT)
		{
			return false;
		}

		if (t == ::DLDL_IMPORT::ast::Type::LEFT_PARANTHESIS)
		{
			return false;
		}

		if (t == ::DLDL_IMPORT::ast::Type::RIGHT_PARANTHESIS)
		{
			return false;
		}

		if (t == ::DLDL_IMPORT::ast::Type::LEFT_SQUARE_BRACKET)
		{
			return false;
		}

		if (t == ::DLDL_IMPORT::ast::Type::RIGHT_SQUARE_BRACKET)
		{
			return false;
		}

		if (t == ::DLDL_IMPORT::ast::Type::COLON)
		{
			return false;
		}

		if (t == ::DLDL_IMPORT::ast::Type::DOT)
		{
			return false;
		}

		if (t == ::DLDL_IMPORT::ast::Type::IMPORT_FILE)
		{
			return false;
		}

		if (t == ::DLDL_IMPORT::ast::Type::IMPORT_MODULE)
		{
			return false;
		}

		if (t == ::DLDL_IMPORT::ast::Type::IMPORT)
		{
			return false;
		}

		if (t == ::DLDL_IMPORT::ast::Type::TEXT)
		{
			return false;
		}

		if (t == ::DLDL_IMPORT::ast::Type::VARNAME)
		{
			return false;
		}

		if (t == ::DLDL_IMPORT::ast::Type::ESCAPE_CHARS)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_IMPORT_AST_RELATION_NODEISIGNORED_H