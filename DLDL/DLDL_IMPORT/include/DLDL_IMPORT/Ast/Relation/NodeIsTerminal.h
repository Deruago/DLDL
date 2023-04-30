#ifndef DLDL_IMPORT_AST_RELATION_NODEISTERMINAL_H
#define DLDL_IMPORT_AST_RELATION_NODEISTERMINAL_H

#include "DLDL_IMPORT/Ast/Enum/Type.h"

namespace DLDL_IMPORT { namespace ast { namespace relation { 

	constexpr static bool NodeIsTerminal(::DLDL_IMPORT::ast::Type t)
	{
		
		if (t == ::DLDL_IMPORT::ast::Type::SINGLE_COMMENT)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::MULTI_COMMENT)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::LEFT_PARANTHESIS)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::RIGHT_PARANTHESIS)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::LEFT_SQUARE_BRACKET)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::RIGHT_SQUARE_BRACKET)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::COLON)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::DOT)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::IMPORT_FILE)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::IMPORT_MODULE)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::IMPORT)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::TEXT)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::VARNAME)
		{
			return true;
		}

		if (t == ::DLDL_IMPORT::ast::Type::ESCAPE_CHARS)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_IMPORT_AST_RELATION_NODEISTERMINAL_H